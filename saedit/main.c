#include <gtksourceview/gtksource.h>
#include "xml.h"
#include "config.h"
#include "spritedrawingarea.h"
#include "action.h"
#include "errors.h"
#include "file.h"
#include "buffer.h"
#include "xmlsetup.h"
#include "drawfuncs.h"

#include "main.h"
#include <string.h>

void
intr_updated (Interactor *interactor) {
	gtk_widget_queue_draw (d_area);

	gtk_tool_button_set_icon_name (
		GTK_TOOL_BUTTON (tbtn_play),
		interactor_loop_running (interactor) ?
			"media-playback-pause" :
			"media-playback-start"
	);

	if (interactor != NULL) {
		gboolean result;
		gint hp;
		gchar *id, *name;

		buffer_mark_line (
			interactor_get_line_no (interactor) - 1
		);

		result = interactor_get_action_hp_and_name (
			interactor,
			&hp, &name
		);

		if (!result)
			return;

		id = get_action_id (hp, name);
		gtk_combo_box_set_active_id (cb_actions, id);
		g_free (id);

		gtk_combo_box_set_active_id (
			GTK_COMBO_BOX (cb_directions),
			interactor_get_animation_direction (interactor)
		);
	} else
		buffer_mark_line (-1);
}

void
release_context () {
	xml_setup_clear ();

	if (interactor != NULL) {
		interactor_free (interactor);
		interactor = NULL;
		intr_updated (interactor);
	}

	gtk_combo_box_text_remove_all (cb_directions);
	gtk_list_store_clear (store_actions);

	if (context != NULL) {
		sprite_context_free (context);
		context = NULL;
	}
}

void
update_window_title () {
	gchar *title, *data_folder, *file_name;
	const gchar *opened_file_name;

	gboolean modified = buffer_get_modified ();
	data_folder = config_keys_get_data_folder_path ();
	opened_file_name = get_opened_file_name ();

	if (
		opened_file_name != NULL && 
		g_str_has_prefix (opened_file_name, data_folder)
	) {
		file_name = g_strconcat (
			"<Data Folder>",
			opened_file_name + strlen (data_folder),
			NULL
		);
	} else {
		file_name = g_strdup (opened_file_name);
	}

	if (file_name == NULL) {
		file_name = g_strdup ("New animation");
	}

	title = g_strconcat (
		modified ? "*" : "",
		file_name,
		NULL
	);

	gtk_window_set_title (GTK_WINDOW (main_window), title);
	g_free (title);
	g_free (file_name);
}

void
setup_source_view (GtkSourceView *source_view) {
	GtkSourceLanguageManager *langman;
	GtkSourceMarkAttributes  *attrs;
	
	langman = gtk_source_language_manager_get_default();

	gtk_source_buffer_set_language (
		GTK_SOURCE_BUFFER (
			gtk_text_view_get_buffer (
				GTK_TEXT_VIEW (source_view)
			)
		),
		gtk_source_language_manager_get_language (langman, "xml")
	);

	attrs = gtk_source_mark_attributes_new ();
	gtk_source_mark_attributes_set_icon_name (attrs, "media-record");
	gtk_source_view_set_mark_attributes (
		source_view, "active-line", attrs, 0 
	);

	gtk_widget_show_all (GTK_WIDGET (source_view));
}

GtkWidget *
gtk_builder_get_widget (
	GtkBuilder *builder,
	const gchar *name
) {
	return GTK_WIDGET (
		gtk_builder_get_object (builder, name)
	);
}

gboolean
window_main_delete_event_cb (
	GtkWidget *widget,
	GdkEvent *event,
	gpointer user_data
) {
	return show_unsaved_changes_dialog ();
}

int
main (int argc, char *argv[]) {
	GtkBuilder *builder;
	gchar *path;

	gtk_init (&argc, &argv);

	builder = gtk_builder_new ();
	gtk_builder_add_from_file (builder, "iface.ui", NULL);
	gtk_builder_connect_signals (builder, NULL);

	main_window   = gtk_builder_get_widget (builder,         "window-main");
	tf_view       = gtk_builder_get_widget (builder, "treefolderview-main");
	d_area        = gtk_builder_get_widget (builder,    "drawingarea-main");
	source_view   = gtk_builder_get_widget (builder,     "sourceview-main");
	tbtn_play     = gtk_builder_get_widget (builder,    "button-anim-play");

	cb_actions    = GTK_COMBO_BOX (
		gtk_builder_get_widget (builder,     "cbox-actions")
	);
	cb_directions = GTK_COMBO_BOX_TEXT (
		gtk_builder_get_widget (builder,  "cboxtext-directions")
	);

	store_actions = GTK_LIST_STORE (
		gtk_builder_get_object (builder, "liststore-actions")
	);

	zoom_adj = GTK_ADJUSTMENT (
		gtk_builder_get_object (builder, "zoom-adjustment")
	);

	g_object_unref (builder);

	setup_source_view (GTK_SOURCE_VIEW (source_view));

	update_window_title ();

	path = config_keys_get_data_folder_path ();
	tree_folder_view_set_filename (
		TREE_FOLDER_VIEW (tf_view),
		path
	);
	g_free (path);

	sprite_drawing_area_add_layer (
		SPRITE_DRAWING_AREA (d_area),
		sda_layer_new (interactor_sprite_layer_draw_func, &interactor)
	);

	tile_grid_layer = sda_layer_new (
		tile_grid_layer_draw_func,
		NULL
	);

	sda_layer_set_z_index (tile_grid_layer, 512);

	sprite_drawing_area_add_layer (
		SPRITE_DRAWING_AREA (d_area),
		tile_grid_layer
	);

	pixel_grid_layer = sda_layer_new (
		pixel_grid_layer_draw_func,
		NULL
	);

	sda_layer_set_z_index (pixel_grid_layer, 512 + 1);
	sda_layer_set_visible (pixel_grid_layer, FALSE);

	sprite_drawing_area_add_layer (
		SPRITE_DRAWING_AREA (d_area),
		pixel_grid_layer
	);

	gtk_widget_show_all (main_window);

	gtk_main();
	
	return 0;
}
