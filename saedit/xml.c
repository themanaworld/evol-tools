/*=======================================*\
|  ____                         ____      |
| /    \         /\            |          |
| \____         /  \           |____      |
|      \       /____\          |          |
| \____/prite /      \nimation |____ditor |
|                                         |
|      Copyleft Vasily_Makarov 2011       |
|                                         |
\*=======================================*/

#include "xml.h"

gchar** xml_attr_new(const gchar *name, const gchar *value) {
	gchar **attr = g_new0(gchar*, 2);
	attr[0] = g_strdup(name);
	attr[1] = g_strdup(value);
	return attr;
}

gchar* xml_node_get_attr_value(const XMLNode *node, const gchar *attr_name) {
	gchar **attr = node->attributes;
	guint i;
	for (i = 0; i < g_strv_length(attr); i += 2)
		if (g_str_equal(attr[i], attr_name))
			return attr[i + 1];
	return NULL;
}


gint xml_node_compare_with_name_func(gconstpointer a, gconstpointer b) {
	return g_strcmp0((gchar *)b, ((XMLNode *)a)->name);
}

gint xml_node_compare_with_action_node_by_imageset_name_func(gconstpointer a, gconstpointer b) {
	return g_strcmp0("action", ((XMLNode *)a)->name) ||
	       g_strcmp0((gchar *)b, xml_node_get_attr_value((XMLNode *)a, "imageset"));
}

gint xml_node_compare_with_attr_func(const XMLNode *node, const gchar **attr) {
	return g_strcmp0(attr[1],
	                 xml_node_get_attr_value(node, attr[0]));
}

static GMarkupParser parser;

void xml_free (XMLNode *node) {
	g_free (node->name);

	g_free (node->text);

	g_strfreev (node->attributes);

	g_list_foreach (node->sub_nodes, (GFunc) xml_free, NULL);
	g_list_free (node->sub_nodes);

	g_slice_free (XMLNode, node);
}

static void _start_root_element_cb (	GMarkupParseContext *context,
				        const gchar         *element_name,
				        const gchar        **attribute_names,
				        const gchar        **attribute_values,
				        gpointer             user_data,
				        GError             **error) {
	XMLNode **node = (XMLNode **) user_data;
	g_assert (node != NULL);

	XMLNode *p = g_slice_new0 (XMLNode);


	p->name = g_strdup (element_name);

	GArray *attributes = g_array_new (TRUE, TRUE, sizeof (gchar *));
	while (*attribute_names != NULL && *attribute_values != NULL) {
		gchar *p2;
		p2 = g_strdup (*attribute_names++);
		g_array_append_val (attributes, p2);
		p2 = g_strdup (*attribute_values++);
		g_array_append_val (attributes, p2);
	}

	p->attributes = (gchar **) g_array_free (attributes, FALSE);

	g_markup_parse_context_push (context, &parser, p);
	*node = p;
}


static void _start_element_cb (	GMarkupParseContext *context,
			   	const gchar         *element_name,
			   	const gchar        **attribute_names,
			  	const gchar        **attribute_values,
			   	gpointer             user_data,
			   	GError             **error) {

	XMLNode *node = (XMLNode *) user_data;

	if (node->text) {
		g_set_error (error, G_MARKUP_ERROR, G_MARKUP_ERROR_INVALID_CONTENT, " ");
		return;
	}

	XMLNode *p = g_slice_new0 (XMLNode);

	node->sub_nodes = g_list_append (node->sub_nodes, p);
	g_markup_parse_context_push (context, &parser, p);

	p->name = g_strdup (element_name);

	GArray *attributes = g_array_new (TRUE, TRUE, sizeof (gchar *));
	while (*attribute_names != NULL && *attribute_values != NULL) {
		gchar *p2;
		p2 = g_strdup (*attribute_names++);
		g_array_append_val (attributes, p2);
		p2 = g_strdup (*attribute_values++);
		g_array_append_val (attributes, p2);
	}

	p->attributes = (gchar **)g_array_free (attributes, FALSE);

	gint char_n, line_n;
	g_markup_parse_context_get_position(context, &line_n, &char_n);
	p->line_number = line_n - (char_n <= 1 ? 1 : 0);
}

static void _end_element_cb (	GMarkupParseContext *context,
				const gchar         *element_name,
				gpointer             user_data,
				GError             **error) {
	XMLNode *p = (XMLNode *) g_markup_parse_context_pop (context);

	if (p->text && p->sub_nodes) {
		g_warning ("Error");
	}

	if (p->text == NULL && p->sub_nodes == NULL) {
		p->text = g_strdup ("");
	}
}

static gboolean _is_space (	const gchar *text,
           			gsize        text_len) {
	gsize i = 0;

	for (i = 0; text[i] != '\0' && i < text_len; i++) {
		switch (text[i]) {
		case '\t':
		case ' ':
		case '\n':
		case '\r':
			continue;
		default:
			return FALSE;
		}
	}

	return TRUE;
}

static void _text_cb (	GMarkupParseContext *context,
			const gchar         *text,
			gsize                text_len,
			gpointer             user_data,
			GError             **error) {
	XMLNode *p = (XMLNode *)user_data;

	if (_is_space (text, text_len)) {
		return;
	}

	if (p->sub_nodes || p->text) {
		g_set_error (error, G_MARKUP_ERROR, G_MARKUP_ERROR_INVALID_CONTENT, " ");
		return;
	}

	p->text = g_strndup (text, text_len);
}

static GMarkupParser parser = {
	_start_element_cb,
	_end_element_cb,
	_text_cb,
	0,
	0,
};

XMLNode *xml_parse_file (const gchar *filename) {
	gboolean retval = FALSE;
	GError *error = NULL;
	FILE *pf = fopen (filename, "r");

	if (pf == NULL) {
		return NULL;
	}

	GMarkupParseContext *context;
	XMLNode *node;

	static const GMarkupParser root_parser = {
		_start_root_element_cb,
		_end_element_cb,
		_text_cb,
		0,
		0,
	};

	do {
		context = g_markup_parse_context_new (&root_parser, 0, &node, 0);

		while (!feof (pf)) {
			gchar buf[1024];
			gssize len = 0;

			len = fread (buf, 1, sizeof (buf), pf);
			retval = g_markup_parse_context_parse (context, buf, len, &error);

			if (!retval)
				break;
		}
		fclose (pf);

		if (!retval)
			break;

		retval = g_markup_parse_context_end_parse (context, &error);
		if (!retval)
			break;

		g_markup_parse_context_free (context);

		return node;
	} while (0);

	g_warning ("Parse %s failed: %s", filename, error->message);
	g_error_free (error);
	g_markup_parse_context_free (context);
	return NULL;
}

XMLNode *xml_parse_buffer (const gchar *buffer, GError **error) {
	gboolean retval;

	GMarkupParseContext *context;
	XMLNode *node;

	static const GMarkupParser root_parser = {
		_start_root_element_cb,
		_end_element_cb,
		_text_cb,
		0,
		0,
	};

	context = g_markup_parse_context_new (&root_parser, 0, &node, 0);

	do {
		retval = g_markup_parse_context_parse (context, buffer, strlen (buffer), error);
		if (!retval)
			break;

		retval = g_markup_parse_context_end_parse (context, error);
		if (!retval)
			break;
		g_markup_parse_context_free (context);
		return node;
	} while (0);

	//g_warning ("Parse buffer failed: %s", (*error)->message);
	g_markup_parse_context_free (context);
	return NULL;
}


static void output_indent (int level, GString *output) {
	gint i;
	for (i = 0; i < level; i++) {
		g_string_append (output, "    ");
	}
}

static void xml_output_indent (const XMLNode *node, int level, GString *output) {
	gchar **attrs;

	output_indent (level, output);
	g_string_append_printf (output, "<%s", node->name);

	attrs = node->attributes;

	while (attrs != NULL && *attrs != NULL) {
		g_string_append_printf (output, " %s", *(attrs++));
		g_string_append_printf (output, "=\"%s\"", *(attrs++));
	}

	if (node->sub_nodes != NULL) {
		g_string_append (output, ">\n");
		GList *sub_node;

		for (sub_node = node->sub_nodes; sub_node != NULL; sub_node = sub_node->next) {
			xml_output_indent (sub_node->data, level + 1, output);
		}
		output_indent (level, output);
		g_string_append_printf (output, "</%s>\n",node->name);
	} else if (node->text != NULL) {
		gchar *text = g_markup_escape_text (node->text, -1);
		g_string_append_printf (output, ">%s</%s>\n", text, node->name);
		g_free (text);
	} else {
		g_string_append (output, "/>\n");
	}
}

void xml_output (const XMLNode *node, GString *output) {
	xml_output_indent (node, 0, output);
}

