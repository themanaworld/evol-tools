#include "spritedrawingarea.h"
#include "sdalayer.h"
#include "sdalayerprivate.h"

enum {
	PROP_0,
	PROP_VISIBLE,
	PROP_OFFSET_X,
	PROP_OFFSET_Y,
	PROP_DRAW_FUNC,
	PROP_USER_DATA,
	PROP_Z_INDEX,
	PROP_COUNT
};

static void
sda_layer_get_property (
	GObject *object,
	guint prop_id,
	GValue *value,
	GParamSpec *pspec
) {
	SDALayer *layer = SDA_LAYER (object);
	SDALayerPrivate *priv = layer->priv;

	switch (prop_id) {
		case PROP_VISIBLE:
			g_value_set_boolean (
				value, priv->visible
			);
			break;

		case PROP_OFFSET_X:
			g_value_set_int (
				value, priv->offset_x
			);
			break;

		case PROP_OFFSET_Y:
			g_value_set_int (
				value, priv->offset_y
			);
			break;

		case PROP_Z_INDEX:
			g_value_set_int (
				value, priv->z_index
			);
			break;

		case PROP_DRAW_FUNC:
			g_value_set_pointer (
				value, (gpointer) priv->draw_func
			);
			break;

		case PROP_USER_DATA:
			g_value_set_pointer (
				value, priv->user_data
			);
			break;

		default:
			G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
			break;
	}
}

static void
sda_layer_set_property (
	GObject *object,
	guint prop_id,
	const GValue *value,
	GParamSpec *pspec
) {
	SDALayer *layer = SDA_LAYER (object);
	SDALayerPrivate *priv = layer->priv;

	switch (prop_id) {
		case PROP_VISIBLE:
			priv->visible = g_value_get_boolean (value); 
			break;

		case PROP_OFFSET_X:
			priv->offset_x = g_value_get_int (value);
			break;

		case PROP_OFFSET_Y:
			priv->offset_y = g_value_get_int (value);
			break;

		case PROP_Z_INDEX:
			priv->z_index = g_value_get_int (value);
			break;

		case PROP_DRAW_FUNC:
			priv->draw_func = (SDALayerDrawFunc) g_value_get_pointer (value);
			break;

		case PROP_USER_DATA:
			priv->user_data = g_value_get_pointer (value);
			break;

		default:
			G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
			break;
	}
}

void
sda_layer_init (
	SDALayer *layer,
	SDALayerClass *class
) {
	layer->priv = G_TYPE_INSTANCE_GET_PRIVATE (
		layer,
		SDA_TYPE_LAYER,
		SDALayerPrivate
	);
	
	layer->priv->draw_func = NULL;
	layer->priv->user_data = NULL;
}

void
sda_layer_class_init (
	SDALayerClass *klass,
	gpointer class_data
) {
	GObjectClass *object_class;

	g_type_class_add_private (klass, sizeof (SDALayerPrivate));

	object_class = G_OBJECT_CLASS (klass);
	object_class->set_property = sda_layer_set_property;
	object_class->get_property = sda_layer_get_property;

	g_object_class_install_property (
		object_class,
		PROP_VISIBLE,
		g_param_spec_boolean (
			"visible",
			"Visible",
			"Whether this layer is visible",
			TRUE,
			G_PARAM_READWRITE | G_PARAM_CONSTRUCT
		)
	);

	g_object_class_install_property (
		object_class,
		PROP_OFFSET_X,
		g_param_spec_int (
			"offset-x",
			"Offset X",
			"The X coordinate of the layer offset",
			-SPRITE_DRAWING_AREA_FIELD_SIZE,
			 SPRITE_DRAWING_AREA_FIELD_SIZE,
			0,
			G_PARAM_READWRITE | G_PARAM_CONSTRUCT
		)
	);

	g_object_class_install_property (
		object_class,
		PROP_OFFSET_Y,
		g_param_spec_int (
			"offset-y",
			"Offset y",
			"The Y coordinate of the layer offset",
			-SPRITE_DRAWING_AREA_FIELD_SIZE,
			 SPRITE_DRAWING_AREA_FIELD_SIZE,
			0,
			G_PARAM_READWRITE | G_PARAM_CONSTRUCT
		)
	);

	g_object_class_install_property (
		object_class,
		PROP_DRAW_FUNC,
		g_param_spec_pointer (
			"draw-func",
			"Draw function",
			"A function invoked to draw the layer",
			G_PARAM_READWRITE | G_PARAM_CONSTRUCT_ONLY
		)
	);

	g_object_class_install_property (
		object_class,
		PROP_USER_DATA,
		g_param_spec_pointer (
			"user-data",
			"User data",
			"Data that will be propagated to the draw"
			" function upon call",
			G_PARAM_READWRITE | G_PARAM_CONSTRUCT
		)
	);

	g_object_class_install_property (
		object_class,
		PROP_Z_INDEX,
		g_param_spec_int (
			"z-index",
			"Z-index",
			"Z-index of the layer",
			-1024, 1024, 0,
			G_PARAM_READWRITE | G_PARAM_CONSTRUCT
		)
	);
}

GType
sda_layer_get_type (void) {
	static GType sda_layer_type = 0;

	if (sda_layer_type == 0) {
		const GTypeInfo sda_layer_info = {
			sizeof (SDALayerClass),
			NULL, 	/* base_init */
			NULL, 	/* base_finalize */
			(GClassInitFunc) sda_layer_class_init,
			NULL, 	/* class_finalize */
			NULL,	/* class_data */
			sizeof (SDALayer),
			0,	/* n_preallocs */
			(GInstanceInitFunc) sda_layer_init,
			NULL,	/* value_table */
		};

		sda_layer_type = g_type_register_static (
			G_TYPE_OBJECT,
			"SDALayer",
			&sda_layer_info,
			0
		);
	}

	return sda_layer_type;
}

SDALayer *sda_layer_new (
	SDALayerDrawFunc draw_func,
	gpointer user_data
) {
	return g_object_new (
		SDA_TYPE_LAYER,
		"draw-func", draw_func,
		"user-data", user_data,
		NULL
	);
}

gint
sda_layer_compare_by_z_index (
	const SDALayer *a,
	const SDALayer *b
) {
	return a->priv->z_index - b->priv->z_index;
}

void
sda_layer_set_z_index (SDALayer *layer, gint z_index) {
	g_object_set (layer, "z-index", z_index, NULL);
}

void
sda_layer_set_visible (SDALayer *layer, gboolean visible) {
	g_object_set (layer, "visible", visible, NULL);
}
