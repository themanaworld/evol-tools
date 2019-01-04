#include "main.h"
#include "xml.h"
#include "xmlsetup.h"
#include "config.h"
#include "drawfuncs.h"

GList *_xml_setup_layers = NULL;
GList *_xml_setup_interactors = NULL;

void
xml_setup_setup (XMLNode *node) {
	GList *l;
	
	g_return_if_fail (g_strcmp0 (node->name, "saedit") == 0);

	for (l = node->sub_nodes; l != NULL; l = l->next) {
		XMLNode *current = (XMLNode *) l->data;

		if (g_strcmp0 (current->name, "layer") == 0) {
			SDALayer *layer = NULL;
			gint z_index = -1;
			gint offset_x, offset_y;
			gchar *type = xml_node_get_attr_value (current, "type");

			if (type == NULL) {
				/* TODO: layer type is not specified */
				continue;
			} 

			if (g_strcmp0 (type, "repeater") == 0) {
				Interactor **repeater;
				SpriteContext *repeater_context;
				XMLNode *sprite = NULL;
				gchar *file;

				file = xml_node_get_attr_value (current, "file");

				if (file == NULL) {
					/* TODO: file is not specified */
				} else {
					gchar *filename =
						config_data_path_get_full_sprite_path (file);
					
					sprite = xml_parse_file (filename);


					g_free (file);
					g_free (filename);
				}

				repeater_context = sprite_context_new (
					config_keys_get_data_folder_path ()
				);

				sprite_context_add_sprite (repeater_context, sprite, 0);
				repeater = (Interactor **) g_new0 (gpointer, 1);
				*repeater = interactor_new (repeater_context);

				layer = sda_layer_new (
					interactor_sprite_layer_draw_func,
					repeater
				);

				interactor_add_repeater (interactor, *repeater);

				_xml_setup_interactors = g_list_append (
					_xml_setup_interactors,
					repeater
				);
			} else 
			if (g_strcmp0 (type, "background") == 0) {
				GdkRGBA *rgba = (GdkRGBA *) g_new0 (GdkRGBA, 1);
				gchar *color;

				color = xml_node_get_attr_value (current, "color");

				if (color != NULL && gdk_rgba_parse (rgba, color)) {
					layer = sda_layer_new (
						background_layer_draw_func,
						rgba
					);
				} else {
					/* TODO: color not specified or wrong */
				}
			} else {
				/* TODO: unknown type of layer */
			}

			g_free (type);

			if (layer == NULL) {
				continue;
			}

			z_index = xml_node_get_int_attr_value (
				current,
				"zindex",
				z_index
			);

			offset_x = xml_node_get_int_attr_value (
				current,
				"offsetX",
				0
			);

			offset_y = xml_node_get_int_attr_value (
				current,
				"offsetY",
				0
			);

			g_object_set (
				G_OBJECT (layer),
				"z-index", z_index,
				"offset-x", offset_x,
				"offset-y", offset_y,
				NULL
			);

			sprite_drawing_area_add_layer (
				SPRITE_DRAWING_AREA (d_area),
				layer
			);

			_xml_setup_layers = g_list_append (
				_xml_setup_layers,
				layer
			);
		} else {
			/* TODO: unknown tag in the setup */
		}
	}
}

void
xml_setup_clear () {
	GList *l;

	for (l = _xml_setup_interactors; l != NULL; l = l->next) {
		Interactor **intr = (Interactor **) l->data;
		interactor_free (*intr);
	}

	for (l = _xml_setup_layers; l != NULL; l = l->next) {
		SDALayer *layer = (SDALayer *) l->data;
		gpointer user_data;

		g_object_get (layer, "user-data", &user_data, NULL);
		g_free (user_data);

		sprite_drawing_area_remove_layer (
			SPRITE_DRAWING_AREA (d_area),
			layer
		);

		g_object_unref (layer);
	}

	g_list_free (_xml_setup_interactors);
	g_list_free (_xml_setup_layers);

	_xml_setup_interactors = NULL;
	_xml_setup_layers = NULL;
}
