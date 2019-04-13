#include "action.h"
#include "animation.h"
#include "imageset.h"
#include "context.h"

Action *
action_new (
	const SpriteContext *context,
	const XMLNode *node, 
	gint included_from
) {
	Action *action;
	GList  *list;
	gchar  *imgset_name;
	gboolean fail = FALSE;
	Imageset *imageset;

	g_return_val_if_fail (g_strcmp0 (node->name, "action") == 0, NULL);
	
	action = (Action *) g_new0 (Action, 1);

	action->name = xml_node_get_attr_value (node, "name");
	if (action->name == NULL) {
		/* TODO: report error */
		fail = TRUE;
	}

	imgset_name = xml_node_get_attr_value (node, "imageset");
	if (imgset_name == NULL) {
		/* TODO: report error */
		fail = TRUE;
	} else {
		imageset = sprite_context_get_imageset (context, imgset_name);
		if (imageset == NULL) {
			/* TODO: report error */
			fail = TRUE;
		}
	}

	if (fail) {
		g_free (action);
		return NULL;
	}

	action->hp = xml_node_get_int_attr_value (node, "hp", 100);

	list = node->sub_nodes;
	while (list != NULL) {
		XMLNode *current = (XMLNode *) list->data;
		
		if (g_strcmp0 (current->name, "animation") == 0) {
			action_add_animation (
				action,
				imageset,
				current,
				included_from
			);
		} else {
			/* TODO: action contains something unknown */
		}

		list = g_list_next (list);
	}

	return action;
}

void
action_add_animation (
	Action *action,
	const Imageset *imageset,
	const XMLNode *node,
	gint included_from
) {
	Animation *animation;

	g_return_if_fail (g_strcmp0 (node->name, "animation") == 0);

	animation = animation_new (imageset, node, included_from);
	if (animation == NULL)
		return;

	if (g_list_find_custom (
		action->animations, animation,
		(GCompareFunc) animation_compare_by_direction) != NULL
	) {
		animation_free (animation);
		return;
	}

	action->animations = g_list_append (action->animations, animation);
}

void
action_free (Action *action) {
	g_list_free_full (
		action->animations,
		(GDestroyNotify) animation_free
	);

	g_free (action->name);
	g_free (action);
}

gint
action_compare_by_hp_and_name (
	const Action *first,
	const Action *second
) {
	if (first->hp != second->hp) {
		return first->hp - second->hp;
	}
	return g_strcmp0 (first->name, second->name);
}

gboolean
action_hp_and_name_equals (
	const Action *action,
	gint hp,
	const gchar *name
) {
	return
		action->hp == hp &&
		g_strcmp0 (action->name, name) == 0;
}

const Animation *
action_get_animation (
	const Action *action,
	const gchar *direction
) {
	GList *animation = action->animations;
	g_return_val_if_fail (animation != NULL, NULL);
	
	while (direction != NULL && animation != NULL) {
		Animation *current = (Animation *) animation->data;
		g_assert (current != NULL);
		if (animation_direction_equals (current, direction))
			return current;
		
		animation = g_list_next (animation);
	}

	return (Animation *) action->animations->data;
}

void
action_get_hp_and_name (
	const Action *action,
	gint *hp,
	gchar **name
) {
	if (hp != NULL)
		*hp = action->hp;
	if (name != NULL)
		*name = action->name;
}

GList *
action_get_directions (const Action *action) {
	GList *result = NULL;
	GList *animations = action->animations;

	while (animations != NULL) {
		Animation *animation = (Animation *) animations->data;
		result = g_list_append (result, animation->direction);
		animations = g_list_next (animations);
	}

	return result;
}

gchar *
get_action_id (gint hp, const gchar *name) {
	return g_strdup_printf ("%d:%s", hp, name);
}
