#include <gtk/gtk.h>
#include "context.h"
#include "imageset.h"
#include "action.h"
#include "animation.h"
#include "xml.h"
#include "config.h"
#include "xmlsetup.h"

struct _SpriteContext {
	gchar *cdf_filename;
	GList *imagesets;
	GList *actions;
	GList *includes;
};

SpriteContext *
sprite_context_new (
	const gchar *cdf_filename
) {
	SpriteContext *context = (SpriteContext *) g_new0 (SpriteContext, 1);
	context->cdf_filename = g_strdup (cdf_filename);
	return context;
}

void
sprite_context_add_imageset (
	SpriteContext *context,
	XMLNode *node
) {
	Imageset *imgset;

	g_return_if_fail (g_strcmp0 (node->name, "imageset") == 0);

	imgset = imageset_new (node, context->cdf_filename);
	if (imgset == NULL)
		return;

	if (g_list_find_custom (
		context->imagesets, imgset,
		(GCompareFunc) imageset_compare_by_name) != NULL
	) {
		imageset_free (imgset);
		return;
	}

	context->imagesets = g_list_append (context->imagesets, imgset);
}

void
sprite_context_add_action (
	SpriteContext *context,
	XMLNode *node,
	gint included_from
) {
	Action *action;

	g_return_if_fail (g_strcmp0 (node->name, "action") == 0);

	action = action_new (context, node, included_from);
	if (action == NULL)
		return;

	if (g_list_find_custom (
		context->actions, action,
		(GCompareFunc) action_compare_by_hp_and_name) != NULL
	) {
		action_free (action);
		return;
	}

	context->actions = g_list_append (context->actions, action);
}

void
sprite_context_add_sprite (
	SpriteContext *context,
	XMLNode *node,
	gint included_from
) {
	GList *list;
	g_return_if_fail (node != NULL);
	g_return_if_fail (g_strcmp0 (node->name, "sprite") == 0);

	list = node->sub_nodes;	
	for (; list != NULL; list = g_list_next (list)) {
		XMLNode *current = (XMLNode *) list->data;
		gchar *name = current->name;
		if (g_strcmp0 (name, "include") == 0) {
			XMLNode *sprite;
			gchar *filename, *file;

			file = xml_node_get_attr_value (current, "file");
			if (file == NULL) {
				/* TODO: report error */
				continue;
			}

			if (g_list_find_custom (
				context->includes, file, 
				(GCompareFunc) g_strcmp0) != NULL
			) {
				/* TODO: such file was already included */
				g_free (file);
				continue;
			}

			context->includes = g_list_append (
				context->includes, file
			);

			filename = config_data_path_get_full_sprite_path (file);

			sprite = xml_parse_file (filename);
			g_free (filename);

			if (sprite == NULL) {
				/* TODO: report error */
				continue;
			}

			if (g_strcmp0 (sprite->name, "sprite") != 0) {
				/* TODO: report error */
				continue;
			}

			if (included_from == -1)
				included_from = current->line_no;

			sprite_context_add_sprite (
				context,
				sprite,
				included_from
			);

			xml_free (sprite);
		} else
		if (g_strcmp0 (name, "imageset") == 0) {
			sprite_context_add_imageset (context, current);
		} else
		if (g_strcmp0 (name, "action") == 0) {
			sprite_context_add_action (context, current, included_from);
		} else
		if (g_strcmp0 (name, "saedit") == 0) {
			if (included_from == -1) { /* we are in the main context */
				xml_setup_setup (current);
			}
		} else {
			/* TODO: sprite contains something unknown */
		}
	}
}

Action *
sprite_context_get_action (
	const SpriteContext *context,
	gint hp,
	const gchar *name
) {
	GList *action = context->actions;

	while (action != NULL) {
		if (action_hp_and_name_equals (
			(Action *) action->data,
			hp,
			name
		)) {
			return (Action *) action->data;
		}

		action = g_list_next (action);
	}

	return NULL;
}

Imageset *
sprite_context_get_imageset (
	const SpriteContext *context,
	const gchar *name
) {
	GList *imageset = context->imagesets;

	while (imageset != NULL) {
		if (imageset_name_equals (
			(Imageset *) imageset->data,
			name
		)) {
			return (Imageset *) imageset->data;
		}

		imageset = g_list_next (imageset);
	}

	return NULL;
}

GList *
sprite_context_get_actions (
	const SpriteContext *context
) {
	return g_list_copy (context->actions);
}

void
sprite_context_free (
	SpriteContext *context
) {
	g_list_free_full (
		context->imagesets,
		(GDestroyNotify) imageset_free
	);

	g_list_free_full (
		context->actions,
		(GDestroyNotify) action_free
	);

	g_list_free_full (
		context->includes,
		(GDestroyNotify) g_free
	);

	g_free (context->cdf_filename);

	g_free (context);
}
