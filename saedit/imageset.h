#ifndef IMAGESET_H
#define IMAGESET_H

#include <gdk/gdk.h>
#include "common.h"
#include "xml.h"

typedef struct _Imageset Imageset;

Imageset *
imageset_new (
	const XMLNode *node,
	const gchar *cdf_filename
);

void
imageset_free (Imageset *imageset);

gint
imageset_compare_by_name (
	const Imageset *first,
	const Imageset *second
);

GdkPixbuf *
imageset_get_sprite_by_index (
	const Imageset *imageset,
	gint index
);

gboolean
imageset_name_equals (
	const Imageset *imageset,
	const gchar *name
);

void
imageset_get_offset (
	const Imageset *imageset,
	gint *offsetX,
	gint *offsetY
);

void
imageset_get_size (
	const Imageset *imageset,
	gint *width,
	gint *height
);
#endif
