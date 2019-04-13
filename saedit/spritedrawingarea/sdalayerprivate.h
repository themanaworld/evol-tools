#ifndef _SDALAYERPRIVATE_H_
#define _SDALAYERPRIVATE_H_

struct _SDALayerPrivate {
	gboolean visible;
	gint offset_x, offset_y;
	gint z_index;

	SDALayerDrawFunc draw_func;
	gpointer user_data;
};

struct _SDALayer {
	GObject object;

	SDALayerPrivate *priv;
};

#endif
