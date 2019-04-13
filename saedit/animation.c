#include "animation.h"
#include <string.h>

static void
animation_add_element_pause (
	Animation *animation,
	gint delay,
	gint rand,
	gint line_no
) {
	AnimElement *elem = animation_element_new ();
	elem->delay  = delay;
	elem->rand   = rand;
	elem->type   = ELEMENT_PAUSE;
	elem->line_no = line_no;

	animation->elements = g_list_append (animation->elements, elem);
}

static void
animation_add_element_end (
	Animation *animation,
	gint rand,
	gint line_no
) {
	AnimElement *elem = animation_element_new ();
	elem->type    = ELEMENT_END;
	elem->rand    = rand;
	elem->line_no = line_no;

	animation->elements = g_list_append (animation->elements, elem);
}

static void
animation_add_element_frame (
	Animation *animation,
	const Imageset *imageset,
	gint index,
	gint offsetX,
	gint offsetY,
	gint delay,
	gint rand,
	gint line_no
) {
	gint x, y;
	AnimElement *elem = animation_element_new ();

	elem->type    = ELEMENT_FRAME;

	imageset_get_offset (imageset, &x, &y);
	offsetX += x;
	offsetY += y;

	imageset_get_size (imageset, &x, &y);
	offsetX -= x / 2;
	offsetY -= y;

	elem->offsetX = offsetX;
	elem->offsetY = offsetY;
	
	elem->delay   = delay;
	elem->rand    = rand;
	elem->line_no = line_no;

	elem->sprite = imageset_get_sprite_by_index (imageset, index);
	if (elem->sprite == NULL) {
		/* TODO: report this */
		g_free (elem);
		return;
	}

	animation->elements = g_list_append (animation->elements, elem);
}

static void
animation_add_element_goto (
	Animation *animation,
	gchar *label,
	gint   rand,
	gint   line_no
) {
	AnimElement *elem = animation_element_new ();
	elem->type = ELEMENT_GOTO;
	elem->str  = label;
	elem->rand = rand;
	elem->line_no = line_no;

	animation->elements = g_list_append (animation->elements, elem);
}

static void
animation_add_element_jump (
	Animation *animation,
	gchar *action,
	gint   rand,
	gint   line_no
) {
	AnimElement *elem = animation_element_new ();
	elem->type = ELEMENT_JUMP;
	elem->str  = action;
	elem->rand = rand;
	elem->line_no = line_no;

	animation->elements = g_list_append (animation->elements, elem);
}

static void
animation_add_element_label (
	Animation *animation,
	gchar *name,
	gint line_no
) {
	AnimElement *elem = animation_element_new ();
	elem->type = ELEMENT_LABEL;
	elem->str  = name;
	elem->line_no = line_no;

	animation->elements = g_list_append (animation->elements, elem);
}

static void
animation_add_sequence (
	Animation     *animation,
	const Imageset *imageset,
	const XMLNode *node,
	gint           offsetX,
	gint           offsetY,
	gint           delay,
	gint           rand,
	gint           line_no
) {
	gchar *value, **tokens;
	gint start  = xml_node_get_int_attr_value (node, "start", -1);
	gint end    = xml_node_get_int_attr_value (node,   "end", -1);
	gint repeat = xml_node_get_int_attr_value_limited (
		node, "repeat", 1, 0, 100
	);

	g_return_if_fail (g_strcmp0 (node->name, "sequence") == 0);

	if (repeat < 1) {
		/* TODO: show error */
		return;
	}

	value = xml_node_get_attr_value (node, "value");

	if (value == NULL) {
		if (start < 0 || end < 0) {
			/* TODO: show error */
			return;
		}
		value = g_strdup_printf ("%d-%d", start, end);
	}

	tokens = g_strsplit (value, ",", 0);
	g_free (value);

	while (repeat > 0) {
		gchar **token = tokens;

		while (*token != NULL) {
			if (g_strcmp0 (*token, "p") == 0) {
				animation_add_element_pause (
					animation,
					delay,
					rand,
					line_no
				);
			} else {
				gint start = -1, end = -1, d;
				gchar *delim = strchr (*token, '-');

				if (delim == NULL) {
					try_strtoint (*token, &start);
					end = start;
				} else {
					*delim = 0;
					try_strtoint (   *token, &start);
					try_strtoint (delim + 1,   &end);
					*delim = '-';
				}

				if (start < 0 || end < 0) {
					/* TODO: show error */
					g_strfreev (tokens);
					return;
				}

				d = start <= end ? +1 : -1;
				end += d;

				while (start != end) {
					animation_add_element_frame (
						animation,
						imageset,
						start,
						offsetX,
						offsetY,
						delay,
						rand,
						line_no
					);
					start += d;
				}
			}
			++token;
		}
		--repeat;
	}

	g_strfreev (tokens);
}

static void
animation_add_elements_from_node (
	Animation *animation,
	const Imageset *imageset,
	const XMLNode *node,
	gint  included_from
) {
	gchar *name = node->name;

	gint   offsetX, offsetY;
	gint   delay, rand;
	gchar *str;
	gint   line_no;

	imageset_get_offset (imageset, &offsetX, &offsetY);

	offsetX += xml_node_get_int_attr_value (node, "offsetX", 0);
	offsetY += xml_node_get_int_attr_value (node, "offsetY", 0);

	delay = xml_node_get_int_attr_value_limited (
		node, "delay", 0, 
		0, 100000
	);

	rand = xml_node_get_int_attr_value_limited (
		node, "rand", 100,
		0, 100
	);

	line_no = included_from;
	if (line_no == -1)
		line_no = node->line_no;

	if (g_strcmp0 (name, "frame") == 0) {
		gint index = xml_node_get_int_attr_value (node, "index", -1);
		
		if (index < 0) {
			/* TODO: report error */
			return;
		}

		animation_add_element_frame (
			animation,
			imageset,
			index,
			offsetX, offsetY,
			delay, rand,
			line_no
		);
	} else

	if (g_strcmp0 (name, "pause") == 0) {
		animation_add_element_pause (
			animation, delay, rand, line_no
		);
	} else

	if (g_strcmp0 (name, "end") == 0) {
		animation_add_element_end (animation, rand, line_no);
	} else

	if (g_strcmp0 (name, "jump") == 0) {
		str = xml_node_get_attr_value (node, "action");
		animation_add_element_jump (
			animation, str, rand, line_no
		);
	} else

	if (g_strcmp0 (name, "label") == 0) {
		str = xml_node_get_attr_value (node, "name");
		if (str == NULL) {
			/* TODO: report error */
			return;
		}

		animation_add_element_label (animation, str, line_no);
	} else
	
	if (g_strcmp0 (name, "goto") == 0) {
		str = xml_node_get_attr_value (node, "label");
		if (str == NULL) {
			/* TODO: report error */
			return;
		}

		animation_add_element_goto (
			animation, str, rand, line_no
		);
	} else

	if (g_strcmp0 (name, "sequence") == 0) {
		animation_add_sequence (
			animation, 
			imageset,
			node,
			offsetX, offsetY,
			delay, rand,
			line_no
		);
	} else

	{
		/* TODO: unknown tag */
		return;
	}
}

Animation *
animation_new (
	const Imageset *imageset,
	const XMLNode *node,
	gint included_from
) {
	Animation *animation;
	gchar     *dir;
	GList     *sub_node;

	g_return_val_if_fail (g_strcmp0 (node->name, "animation") == 0, NULL);
	
	dir = xml_node_get_attr_value (node, "direction");

	if (dir == NULL)
		dir = "";

	animation = (Animation *) g_new0 (Animation, 1);
	animation->direction = dir;

	sub_node = node->sub_nodes;
	while (sub_node != NULL) {
		animation_add_elements_from_node (
			animation,
			imageset,
			(XMLNode *) sub_node->data,
			included_from
		);
		sub_node = g_list_next (sub_node);
	}

	return animation;
}

gint
animation_compare_by_direction (
	const Animation *first,
	const Animation *second
) {
	return g_strcmp0 (first->direction, second->direction);
}

gboolean
animation_direction_equals (
	const Animation *animation,
	const gchar *direction
) {
	return g_strcmp0 (animation->direction, direction) == 0;
}

void
animation_free (Animation *animation) {
	g_list_free_full (
		animation->elements,
		(GDestroyNotify) g_free
	);

	g_free (animation->direction);
	g_free (animation);
}

AnimElement *
animation_element_new () {
	return (AnimElement *) g_new0 (AnimElement, 1);
}
