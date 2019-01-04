#ifndef _INTERACTOR_H_
#define _INTERACTOR_H_

#include "context.h"

typedef struct _Interactor Interactor;

Interactor *
interactor_new (
	const SpriteContext *context
);

gboolean
interactor_set_action (
	Interactor *interactor,
	gint hp,
	const gchar *name
);

gboolean
interactor_reset_animation (
	Interactor *interactor
);

gboolean
interactor_set_direction (
	Interactor *interactor,
	const gchar *direction
);

gboolean
interactor_play (
	Interactor *interactor,
	gint time
);

const GdkPixbuf *
interactor_get_sprite (const Interactor *interactor);

void
interactor_loop_start (
	Interactor *interactor,
	const guint interval,
	const guint tick_length
);

gboolean
interactor_loop_stop (Interactor *interactor);

void
interactor_free (Interactor *interactor);

void
interactor_free_with_repeaters (Interactor *interactor);

typedef void
(*InteractionUpdatedFunc) (Interactor *interactor);

void
interactor_set_updated_callback (
	Interactor *interactor,
	InteractionUpdatedFunc callback
);

void
interactor_get_offset (
	const Interactor *interactor,
	gint *offsetX,
	gint *offsetY
);

gint
interactor_get_line_no (
	Interactor *interactor
);

const gchar *
interactor_get_animation_direction (
	const Interactor *interactor
);

const gchar *
interactor_get_direction (
	const Interactor *interactor
);

gboolean
interactor_get_action_hp_and_name (
	const Interactor *interactor,
	gint *hp,
	gchar **name
);

gboolean
interactor_loop_running (
	const Interactor *interactor
);

void
interactor_skip_current_frame (
	Interactor *interactor
);

void
interactor_add_repeater (
	Interactor *interactor,
	Interactor *repeater
);

#endif
