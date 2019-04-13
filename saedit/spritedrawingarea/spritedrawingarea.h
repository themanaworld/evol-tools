#ifndef __SPRITE_DRAWING_AREA_H__
#define __SPRITE_DRAWING_AREA_H__

#include <gdk/gdk.h>
#include <gtk/gtk.h>
#include "sdalayer.h"

G_BEGIN_DECLS

#define TYPE_SPRITE_DRAWING_AREA (sprite_drawing_area_get_type ())
#define SPRITE_DRAWING_AREA(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_SPRITE_DRAWING_AREA, SpriteDrawingArea))
#define SPRITE_DRAWING_AREA_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_SPRITE_DRAWING_AREA, SpriteDrawingAreaClass))
#define IS_SPRITE_DRAWING_AREA(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_SPRITE_DRAWING_AREA))
#define IS_SPRITE_DRAWING_AREA_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_SPRITE_DRAWING_AREA))
#define SPRITE_DRAWING_AREA_GET_CLASS(obj) ((obj), TYPE_SPRITE_DRAWING_AREA, SpriteDrawingAreaClass)

typedef struct _SpriteDrawingArea SpriteDrawingArea;
typedef struct _SpriteDrawingAreaPrivate SpriteDrawingAreaPrivate;
typedef struct _SpriteDrawingAreaClass SpriteDrawingAreaClass;

struct _SpriteDrawingArea {
	GtkDrawingArea darea;

	SpriteDrawingAreaPrivate *priv;
};

struct _SpriteDrawingAreaClass {
	GtkDrawingAreaClass darea_class;

	void (* draw_field) (
		GtkWidget *sdarea,
		gpointer data
	);
};

static const gint SPRITE_DRAWING_AREA_FIELD_SIZE = 1024;

GType
sprite_drawing_area_get_type (void);

GtkWidget*
sprite_drawing_area_new (void);

void
sprite_drawing_area_set_scale_factor (
	SpriteDrawingArea *sdarea,
	gdouble scale_factor
);

void
sprite_drawing_area_add_layer (
	SpriteDrawingArea *sdarea,
	SDALayer *layer
);

void
sprite_drawing_area_remove_layer (
	SpriteDrawingArea *sdarea,
	SDALayer *layer
);

void
sprite_drawing_area_set_center (
	SpriteDrawingArea *sdarea,
	gint center_x,
	gint center_y
);

G_END_DECLS

#endif
