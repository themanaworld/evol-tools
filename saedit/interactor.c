#include <glib.h>
#include <stdlib.h>

#include "interactor.h"
#include "imageset.h"
#include "action.h"
#include "animation.h"
#include "errors.h"

struct _Interactor {
	const SpriteContext *context;
	const Action *action;
	const Animation *animation;
	gchar *direction;
	gboolean rand_checked;
	GList *element;
	gint delay;

	guint loop_tag;
	guint tick_length;

	InteractionUpdatedFunc updated_cb;

	GList *repeaters;
};

static gboolean
interactor_updated_func (Interactor *interactor) {
	g_return_val_if_fail (interactor->updated_cb != NULL, FALSE);

	interactor->updated_cb (interactor);
	return FALSE;
}

static void
interactor_updated (Interactor *interactor) {
	if (interactor->updated_cb == NULL)
		return;

	g_main_context_invoke (
		NULL,
		(GSourceFunc) interactor_updated_func,
		interactor
	);
}

static AnimElement *
interactor_get_element (const Interactor *interactor) {
	if (interactor->element == NULL)
		return NULL;
	return (AnimElement *) interactor->element->data;
}

Interactor *
interactor_new (
	const SpriteContext *context
) {
	Interactor *interactor = g_new0 (Interactor, 1);

	interactor->context = context;
	interactor->repeaters = NULL;
	return interactor;
}

gboolean
interactor_reset_animation (
	Interactor *interactor
) {
	GList *l;

	for (l = interactor->repeaters; l != NULL; l = l->next)
		interactor_reset_animation ((Interactor *) l->data);

	if (interactor->action == NULL)
		return FALSE;

	interactor->animation = action_get_animation (
		interactor->action,
		interactor->direction
	);

	g_return_val_if_fail (interactor->animation != NULL, FALSE);

	interactor->element = interactor->animation->elements;
	interactor->delay = 0;
	interactor->rand_checked = TRUE;
	interactor_updated (interactor);
	interactor_play (interactor, 0);

	return TRUE;
}

gboolean
interactor_set_action (
	Interactor *interactor,
	gint hp,
	const gchar *name
) {
	Action *action;
	GList *l;

	for (l = interactor->repeaters; l != NULL; l = l->next)
		interactor_set_action ((Interactor *) l->data, hp, name);

	if (	
		interactor->action != NULL &&
		action_hp_and_name_equals (interactor->action, hp, name)
	)
		return FALSE;

	action = sprite_context_get_action (
		interactor->context, hp, name
	);

	if (action == NULL)
		return FALSE;

	interactor->action = action;
	return interactor_reset_animation (interactor);
}

gboolean
interactor_set_direction (
	Interactor *interactor,
	const gchar *direction
) {
	GList *l;

	for (l = interactor->repeaters; l != NULL; l = l->next)
		interactor_set_direction ((Interactor *) l->data, direction);

	if (g_strcmp0 (interactor->direction, direction) != 0) {
		if (interactor->direction != NULL)
			g_free (interactor->direction);

		interactor->direction = g_strdup (direction);
		return interactor_reset_animation (interactor);
	}

	return FALSE;
} 

static gboolean
_animation_element_rand_check (
	const AnimElement *element
) {
	if (element->rand == 100) return TRUE;
	if (element->rand == 0)   return FALSE;
	return rand() % 100 < element->rand;
}

gboolean
interactor_play (
	Interactor *interactor,
	gint time
) {
	gboolean updated = FALSE;
	GList *l;

	for (l = interactor->repeaters; l != NULL; l = l->next)
		interactor_play ((Interactor *) l->data, time);
	
	g_return_val_if_fail (time >= 0, FALSE);

	if (interactor->action == NULL)
		return FALSE;
	if (interactor->animation == NULL)
		return FALSE;
	g_return_val_if_fail (interactor->element != NULL, FALSE);

	interactor->delay += time;

	while (TRUE) {
		AnimElement *element = interactor_get_element (interactor);
		gint e_delay = element->delay;

		if (	interactor->rand_checked || 
			_animation_element_rand_check (element)
		) {
			interactor->rand_checked = TRUE;

			if (interactor->delay < e_delay)
				break;

			interactor->delay -= e_delay;
			interactor->rand_checked = FALSE;
			updated = TRUE;

			if (element->type == ELEMENT_END) {
				interactor_reset_animation (interactor);
				return FALSE;
			} else

			if (element->type == ELEMENT_FRAME) {
				if (e_delay == 0)
					break;
			} else

			if (element->type == ELEMENT_PAUSE) {
				if (e_delay == 0)
					break;
			} else

			if (element->type == ELEMENT_JUMP) {
				gint delay = interactor->delay;

				gboolean found = interactor_set_action (
					interactor,
					interactor->action->hp,
					element->str
				);

				if (!found) {
					/* TODO: report about this */
					return FALSE;
				}

				return interactor_play (
					interactor,
					delay
				);
			} else

			if (element->type == ELEMENT_LABEL) {

			} else

			if (element->type == ELEMENT_GOTO) {
				GList *nelem = 
					interactor->animation->elements;

				while (nelem != NULL) {
					AnimElement *current =
						(AnimElement *) nelem->data;
					if (current->type == ELEMENT_LABEL) {
						if (g_strcmp0 (
							current->str,
							element->str) == 0
						)
							break;
					}

					nelem = g_list_next (nelem);
				}

				if (nelem != NULL) {
					interactor->element = nelem;
					continue;
				} else {
					post_error ("Playback", "Specified goto label not found");
					return FALSE;
				}
			}
		}

		interactor->element = g_list_next (interactor->element);
		if (interactor->element == NULL)
			interactor->element = interactor->animation->elements;
	}

	if (updated)
		interactor_updated (interactor);

	return TRUE;
}

const GdkPixbuf *
interactor_get_sprite (const Interactor *interactor) {
	if (interactor->element == NULL)
		return NULL;
	return interactor_get_element (interactor)->sprite;
}

void
interactor_get_offset (
	const Interactor *interactor,
	gint *offsetX,
	gint *offsetY
) {
	AnimElement *element = interactor_get_element (interactor);
	if (element == NULL)
		return;

	*offsetX = element->offsetX;
	*offsetY = element->offsetY;
}

gboolean
interactor_loop_tick (Interactor *interactor) {
	gboolean result = interactor_play (
		interactor, 
		interactor->tick_length
	);

	if (result == FALSE) {
		interactor->loop_tag = 0;
		interactor_updated (interactor);
	}

	return result;
}

void
interactor_loop_start (
	Interactor *interactor,
	const guint interval,
	const guint tick_length
) {
	if (interactor->loop_tag != 0)
		return;
	
	interactor->tick_length = tick_length;
	interactor->loop_tag = g_timeout_add (
		interval,
		(GSourceFunc) interactor_loop_tick,
		interactor
	);

	interactor_updated (interactor);
}

gboolean
interactor_loop_stop (Interactor *interactor) {
	if (interactor->loop_tag == 0)
		return FALSE;

	g_source_remove (interactor->loop_tag);
	interactor->loop_tag = 0;

	interactor_updated (interactor);

	return TRUE;
}

gboolean
interactor_loop_running (
	const Interactor *interactor
) {
	if (interactor == NULL)
		return FALSE;
	return interactor->loop_tag != 0;
}

void
interactor_free (Interactor *interactor) {
	interactor_loop_stop (interactor);
	g_list_free (interactor->repeaters);
	g_free (interactor);
}

void
interactor_free_with_repeaters (Interactor *interactor) {
	interactor_loop_stop (interactor);

	g_list_free_full (
		interactor->repeaters,
		(GDestroyNotify) interactor_free_with_repeaters
	);

	g_free (interactor);
}

void
interactor_set_updated_callback (
	Interactor *interactor,
	InteractionUpdatedFunc callback
) {
	interactor->updated_cb = callback;
}

gint
interactor_get_line_no (
	Interactor *interactor
) {
	AnimElement *element = interactor_get_element (interactor);

	if (element == NULL)
		return -1;

	return element->line_no;
}

const gchar *
interactor_get_animation_direction (
	const Interactor *interactor
) {
	if (interactor->animation == NULL)
		return NULL;
	return interactor->animation->direction;
}

const gchar *
interactor_get_direction (
	const Interactor *interactor
) {
	return interactor->direction;
}

gboolean
interactor_get_action_hp_and_name (
	const Interactor *interactor,
	gint *hp,
	gchar **name
) {
	if (interactor->action == NULL)
		return FALSE;

	action_get_hp_and_name (interactor->action, hp, name);
	return TRUE;
}

void
interactor_skip_current_frame (
	Interactor *interactor
) {
	AnimElement *element;
	
	interactor_loop_stop (interactor);
	element = interactor_get_element (interactor);

	if (element != NULL) {
		g_return_if_fail (interactor->delay <= element->delay);
		interactor_play (
			interactor,
			element->delay - interactor->delay
		);
	}
}

void
interactor_add_repeater (
	Interactor *interactor,
	Interactor *repeater
) {
	interactor->repeaters = g_list_append (
		interactor->repeaters,
		repeater
	);
}
