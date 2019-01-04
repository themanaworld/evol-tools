#ifndef ACTION_H
#define ACTION_H

#include <glib.h>
#include "common.h"
#include "imageset.h"
#include "animation.h"
#include "xml.h"

typedef struct {
	gchar *name;
	gint hp;
	GList *animations;
} Action;

void
action_free (Action *action);

gint
action_compare_by_hp_and_name (
	const Action *first,
	const Action *second
);

gboolean
action_hp_and_name_equals (
	const Action *action,
	gint hp,
	const gchar *name
);

void
action_add_animation (
	Action  *action,
	const Imageset *imageset,
	const XMLNode *node,
	gint included_from
);

const Animation *
action_get_animation (
	const Action *action,
	const gchar *direction
);

void
action_get_hp_and_name (
	const Action *action,
	gint *hp,
	gchar **name
);

GList *
action_get_directions (const Action *action);

gchar *
get_action_id (gint hp, const gchar *name);

#endif
