#ifndef ANIMATION_H
#define ANIMATION_H

#include <gdk/gdk.h>
#include <glib.h>
#include "common.h"
#include "xml.h"
#include "imageset.h"

typedef struct {
	gchar *direction;
	GList *elements;
} Animation;

Animation *
animation_new (
	const Imageset *imageset,
	const XMLNode *node,
	gint included_from
);

void
animation_free (Animation *animation);

gint
animation_compare_by_direction (
	const Animation *first,
	const Animation *second
);

gboolean
animation_direction_equals (
	const Animation *animation,
	const gchar *direction
);

enum {
	ELEMENT_END = 0,
	ELEMENT_FRAME,
	ELEMENT_JUMP,
	ELEMENT_GOTO,
	ELEMENT_PAUSE,
	ELEMENT_LABEL,
	ELEMENT_COUNT
};

typedef struct {
	gint   type;
	gint   delay;
	gint   offsetX, offsetY;
	gint   rand;
	gchar *str;
	gint   line_no;
	GdkPixbuf *sprite;
} AnimElement;

AnimElement *animation_element_new (void);

#endif
