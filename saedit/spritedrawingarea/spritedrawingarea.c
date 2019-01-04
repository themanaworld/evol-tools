#include "spritedrawingarea.h"
#include "sdalayer.h"
#include "sdalayerprivate.h"

struct _SpriteDrawingAreaPrivate {
	gint center_x, center_y;
	gdouble scale_factor;

	gboolean drag_active;
	gdouble drag_x, drag_y;

	GList *layers;
};

enum {
	PROP_0,
	PROP_CENTER_X,
	PROP_CENTER_Y,
	PROP_SCALE_FACTOR,
	PROP_COUNT
};

void
sprite_drawing_area_get_center (
	SpriteDrawingArea *sdarea,
	gint *center_x,
	gint *center_y
) {
	g_object_get (
		sdarea,
		"center-x", center_x,
		"center-y", center_y,
		NULL
	);
}

void
sprite_drawing_area_set_center (
	SpriteDrawingArea *sdarea,
	gint center_x,
	gint center_y
) {
	g_object_set (
		sdarea,
		"center-x", center_x,
		"center-y", center_y,
		NULL
	);
}

gdouble
sprite_drawing_area_get_scale_factor (
	SpriteDrawingArea *sdarea
) {
	gdouble result;

	g_object_get (
		sdarea,
		"scale-factor", &result,
		NULL
	);

	return result;
}

void
sprite_drawing_area_set_scale_factor (
	SpriteDrawingArea *sdarea,
	gdouble scale_factor
) {
	g_object_set (
		sdarea,
		"scale-factor", scale_factor,
		NULL
	);
}

static gboolean
_sprite_drawing_area_draw_handler (
	GtkWidget *widget,
	cairo_t *cr,
	gpointer user_data
) {
	SpriteDrawingArea *sdarea = SPRITE_DRAWING_AREA (widget);
	GList *l;

	gint width  = gtk_widget_get_allocated_width (widget);
	gint height = gtk_widget_get_allocated_height (widget);

	gdouble scale = sprite_drawing_area_get_scale_factor (sdarea);

	gint center_x, center_y;

	sprite_drawing_area_get_center (sdarea, &center_x, &center_y);

	cairo_translate (
		cr,
		0.5 * (gdouble) width,
		0.5 * (gdouble) height
	);

	cairo_scale (cr, scale, scale);

	cairo_translate (
		cr,
		-center_x,
		-center_y
	);

	sdarea->priv->layers = g_list_sort (
		sdarea->priv->layers,
		(GCompareFunc) sda_layer_compare_by_z_index
	);

	for (l = sdarea->priv->layers; l != NULL; l = l->next) {
		SDALayer *layer = SDA_LAYER (l->data);

		if (!layer->priv->visible)
			continue;

		cairo_save (cr);

		cairo_translate (
			cr,
			layer->priv->offset_x,
			layer->priv->offset_y
		);

		if (layer->priv->draw_func != NULL)
			layer->priv->draw_func (layer, cr, layer->priv->user_data);

		cairo_restore (cr);
	}

	return FALSE;
}

static void
sprite_drawing_area_get_property (
	GObject *object,
	guint prop_id,
	GValue *value,
	GParamSpec *pspec
) {
	SpriteDrawingArea *sdarea = SPRITE_DRAWING_AREA (object);

	switch (prop_id) {
		case PROP_CENTER_X:
			g_value_set_int (
				value, sdarea->priv->center_x
			);
			break;

		case PROP_CENTER_Y:
			g_value_set_int (
				value, sdarea->priv->center_y
			);
			break;

		case PROP_SCALE_FACTOR:
			g_value_set_double (
				value, sdarea->priv->scale_factor
			);
			break;

		default:
			G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
			break;
	}
}

static void
sprite_drawing_area_set_property (
	GObject *object,
	guint prop_id,
	const GValue *value,
	GParamSpec *pspec
) {
	SpriteDrawingArea *sdarea = SPRITE_DRAWING_AREA (object);

	switch (prop_id) {
		case PROP_CENTER_X:
			sdarea->priv->center_x = g_value_get_int (value); 
			break;

		case PROP_CENTER_Y:
			sdarea->priv->center_y = g_value_get_int (value);
			break;

		case PROP_SCALE_FACTOR:
			sdarea->priv->scale_factor = g_value_get_double (value);
			break;

		default:
			G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
			break;
	}
}

gboolean
_sprite_drawing_area_drag_start_callback (
	GtkWidget *widget,
	GdkEvent *event,
	gpointer user_data
) {
	SpriteDrawingArea *sdarea = SPRITE_DRAWING_AREA (widget);

	if (event->button.button != 1)
		return FALSE;

	sdarea->priv->drag_active = TRUE;
	sdarea->priv->drag_x = event->button.x;
	sdarea->priv->drag_y = event->button.y;

	return FALSE;
}

gboolean
_sprite_drawing_area_drag_end_callback (
		GtkWidget *widget,
		GdkEvent *event,
		gpointer user_data
) {
	SpriteDrawingArea *sdarea = SPRITE_DRAWING_AREA (widget);

	if (event->button.button != 1)
		return FALSE;

	sdarea->priv->drag_active = FALSE;
	return FALSE;
}

gboolean
_sprite_drawing_area_drag_motion_callback (
		GtkWidget *widget,
		GdkEvent *event,
		gpointer user_data
) {
	SpriteDrawingArea *sdarea = SPRITE_DRAWING_AREA (widget);

	gdouble event_x, event_y;

	gint center_x, center_y;
	gint delta_x, delta_y;

	gdouble scale_factor;

	if ((event->motion.state & GDK_BUTTON1_MASK) == 0)
		return FALSE;

	if (!sdarea->priv->drag_active)
		return FALSE;

	event_x = event->motion.x;
	event_y = event->motion.y;

	sprite_drawing_area_get_center (sdarea, &center_x, &center_y);

	scale_factor = sprite_drawing_area_get_scale_factor (sdarea);

	delta_x = 
		(gint) (event_x / scale_factor + 0.5) - (gint) (sdarea->priv->drag_x / scale_factor + 0.5);
	delta_y =
		(gint) (event_y / scale_factor + 0.5) - (gint) (sdarea->priv->drag_y / scale_factor + 0.5);

	sprite_drawing_area_set_center (
		sdarea,
		center_x - delta_x,
		center_y - delta_y
	);

	sdarea->priv->drag_x = event_x;
	sdarea->priv->drag_y = event_y;

	gtk_widget_queue_draw (widget);
	return FALSE;
}

static void
sprite_drawing_area_init (
	SpriteDrawingArea *sdarea,
	SpriteDrawingAreaClass *klass
) {
	/* Setting up private */
	sdarea->priv = G_TYPE_INSTANCE_GET_PRIVATE (
		sdarea,
		TYPE_SPRITE_DRAWING_AREA,
		SpriteDrawingAreaPrivate
	);

	sdarea->priv->layers = NULL;

	g_signal_connect (
		sdarea,
		"button-press-event",
		(GCallback) _sprite_drawing_area_drag_start_callback,
		NULL
	);

	g_signal_connect (
		sdarea,
		"button-release-event",
		(GCallback) _sprite_drawing_area_drag_end_callback,
		NULL
	);

	g_signal_connect (
		sdarea,
		"motion-notify-event",
		(GCallback) _sprite_drawing_area_drag_motion_callback,
		NULL
	);
}

static void
sprite_drawing_area_class_init (
	SpriteDrawingAreaClass *klass,
	gpointer class_data
) {
	GObjectClass *object_class;

	g_type_class_add_private (klass, sizeof (SpriteDrawingAreaPrivate));

	object_class = G_OBJECT_CLASS (klass);
	object_class->set_property = sprite_drawing_area_set_property;
	object_class->get_property = sprite_drawing_area_get_property;

	g_signal_override_class_handler (
		"draw",
		TYPE_SPRITE_DRAWING_AREA,
		(GCallback) _sprite_drawing_area_draw_handler
	);

	g_object_class_install_property (
		object_class,
		PROP_CENTER_X,
		g_param_spec_int (
			"center-x",
			"Center X",
			"The X coordinate of the point on the field "
			"camera is centered on, in pixels",
			-SPRITE_DRAWING_AREA_FIELD_SIZE,
			 SPRITE_DRAWING_AREA_FIELD_SIZE,
			0,
			G_PARAM_READWRITE | G_PARAM_CONSTRUCT
		)
	);

	g_object_class_install_property (
		object_class,
		PROP_CENTER_Y,
		g_param_spec_int (
			"center-y",
			"Center Y",
			"The Y coordinate of the point on the field "
			"camera is centered on, in pixels",
			-SPRITE_DRAWING_AREA_FIELD_SIZE,
			 SPRITE_DRAWING_AREA_FIELD_SIZE,
			0,
			G_PARAM_READWRITE | G_PARAM_CONSTRUCT
		)
	);

	g_object_class_install_property (
		object_class,
		PROP_SCALE_FACTOR,
		g_param_spec_double (
			"scale-factor",
			"Scale factor",
			"The scaling factor that is used in making "
			"the camera zooming effect",
			0.01, 100.0, 1.0,
			G_PARAM_READWRITE | G_PARAM_CONSTRUCT
		)
	);
}

GType
sprite_drawing_area_get_type (void) {
	static GType sdarea_type = 0;

	if (sdarea_type == 0) {
		const GTypeInfo sdarea_info = {
			sizeof (SpriteDrawingAreaClass),
			NULL, 	/* base_init */
			NULL, 	/* base_finalize */
			(GClassInitFunc) sprite_drawing_area_class_init,
			NULL, 	/* class_finalize */
			NULL,	/* class_data */
			sizeof (SpriteDrawingArea),
			0,	/* n_preallocs */
			(GInstanceInitFunc) sprite_drawing_area_init,
			NULL,	/* value_table */
		};

		sdarea_type = g_type_register_static (
			GTK_TYPE_DRAWING_AREA,
			"SpriteDrawingArea",
			&sdarea_info,
			0
		);

	}

	return sdarea_type;
}

GtkWidget *
sprite_drawing_area_new (void) {
	GtkWidget *sdarea = GTK_WIDGET (
		g_object_new (TYPE_SPRITE_DRAWING_AREA, NULL)
	);
	return sdarea;
}

void
sprite_drawing_area_add_layer (
	SpriteDrawingArea *sdarea,
	SDALayer *layer
) {
	sdarea->priv->layers = g_list_insert_sorted (
		sdarea->priv->layers,
		layer,
		(GCompareFunc) sda_layer_compare_by_z_index
	);
}

void
sprite_drawing_area_remove_layer (
	SpriteDrawingArea *sdarea,
	SDALayer *layer
) {
	sdarea->priv->layers = g_list_remove (
		sdarea->priv->layers,
		layer
	);
}
