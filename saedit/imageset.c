#include "imageset.h"
#include <string.h>

struct _Imageset {
	gchar *name;
	gint width, height;
	gint offsetX, offsetY;

	GdkPixbuf *pixbuf;
};

Imageset *
imageset_new (
	const XMLNode *node,
	const gchar *cdf_filename
) {
	Imageset *imgset; 
	gchar    *src, *filename;
	GError   *err = NULL;
	gboolean  fail = FALSE;

	g_return_val_if_fail (g_strcmp0 (node->name, "imageset") == 0, NULL);

	imgset = (Imageset *) g_new0 (Imageset, 1);

	imgset->name = xml_node_get_attr_value (node, "name");
	if (imgset->name == NULL) {
		/* TODO: report error */
		fail = TRUE;
	}

	src = xml_node_get_attr_value (node, "src");
	if (src == NULL) {
		/* TODO: report error */
		fail = TRUE;
	} else {
		gchar *delim = strchr (src, '|');
		if (delim != NULL)
			*delim = 0;
		/* TODO: process palettes? */
	}

	imgset->width  = xml_node_get_int_attr_value (node,  "width", -1);
	imgset->height = xml_node_get_int_attr_value (node, "height", -1);
	if (imgset->width <= 0 || imgset->height <= 0) {
		/* TODO: report error */
		fail = TRUE;
	}

	imgset->offsetX = xml_node_get_int_attr_value (node, "offsetX", 0);
	imgset->offsetY = xml_node_get_int_attr_value (node, "offsetY", 0);

	filename = g_strconcat (cdf_filename, "/", src, NULL);
	imgset->pixbuf = gdk_pixbuf_new_from_file (filename, &err);

	if (imgset->pixbuf == NULL) {
		/* TODO handle err and report error */
		fail = TRUE;
	}

	if (fail) {
		imageset_free (imgset);
		return NULL;
	}

	return imgset;
}

gint
imageset_compare_by_name (
	const Imageset *first,
	const Imageset *second
) {
	return g_strcmp0 (first->name, second->name);
}

GdkPixbuf *
imageset_get_sprite_by_index (
	const Imageset *imageset,
	gint index
) {
	gint w = gdk_pixbuf_get_width (imageset->pixbuf);
	w /= imageset->width;

	g_return_val_if_fail (index >= 0, NULL);

	return gdk_pixbuf_new_subpixbuf (
		imageset->pixbuf,
		(index % w) * imageset->width,
		(index / w) * imageset->height,
		imageset->width,
		imageset->height
	);
}

void
imageset_free (Imageset *imgset) {
	g_free (imgset->name);
	if (imgset->pixbuf != NULL)
		g_object_unref (imgset->pixbuf);
	g_free (imgset);
}

gboolean
imageset_name_equals (
	const Imageset *imageset,
	const gchar *name
) {
	return g_strcmp0 (imageset->name, name) == 0;
}

void
imageset_get_offset (
	const Imageset *imageset,
	gint *offsetX,
	gint *offsetY
) {
	*offsetX = imageset->offsetX;
	*offsetY = imageset->offsetY;
}

void
imageset_get_size (
	const Imageset *imageset,
	gint *width,
	gint *height
) {
	*width = imageset->width;
	*height = imageset->height;
}
