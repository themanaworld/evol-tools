#ifndef _SDALAYER_H_
#define _SDALAYER_H_

#include <glib-object.h>
#include <cairo.h>

G_BEGIN_DECLS

#define SDA_TYPE_LAYER (sda_layer_get_type ())
#define SDA_LAYER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), SDA_TYPE_LAYER, SDALayer))
#define SDA_LAYER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), SDA_TYPE_LAYER, SDALayerClass))
#define IS_SDA_LAYER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), SDA_TYPE_LAYER))
#define IS_SDA_LAYER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), SDA_TYPE_LAYER))
#define SDA_LAYER_GET_CLASS(obj) ((obj), SDA_TYPE_LAYER, SDALayerClass)

typedef struct _SDALayer SDALayer;
typedef struct _SDALayerClass SDALayerClass;
typedef struct _SDALayerPrivate SDALayerPrivate;

struct _SDALayerClass {
	GObjectClass parent_class;
};

GType
sda_layer_get_type (void);

typedef void
(* SDALayerDrawFunc) (
	SDALayer *layer,
	cairo_t *cr,
	gpointer user_data
);

SDALayer *
sda_layer_new (
	SDALayerDrawFunc draw_func,
	gpointer user_data
);

gint
sda_layer_compare_by_z_index (
	const SDALayer *a,
	const SDALayer *b
);

void
sda_layer_set_z_index (SDALayer *layer, gint z_index);

void
sda_layer_set_visible (SDALayer *layer, gboolean visible);

G_END_DECLS

#endif
