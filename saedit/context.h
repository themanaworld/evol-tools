#ifndef CONTEXT_H
#define CONTEXT_H

#include "xml.h"
#include "imageset.h"
#include "action.h"

typedef struct _SpriteContext SpriteContext;

SpriteContext *
sprite_context_new (
	const gchar *client_data_folder
);

void
sprite_context_add_sprite (
	SpriteContext *context,
	XMLNode *node,
	gboolean is_include
);

Action *
action_new (
	const SpriteContext *context,
	const XMLNode *node,
	gint  included_from
);

Action *
sprite_context_get_action (
	const SpriteContext *context,
	gint hp,
	const gchar *name
);

Imageset *
sprite_context_get_imageset (
	const SpriteContext *context,
	const gchar *name
);

GList *
sprite_context_get_actions (
	const SpriteContext *context
);

void
sprite_context_free (SpriteContext *context);

#endif
