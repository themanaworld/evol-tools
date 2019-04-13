#include "main.h"
#include "errors.h"
#include "config.h"
#include "file.h"
#include "buffer.h"
#include <string.h>

void
store_append_action (const Action *action, gpointer user_data) {
	int hp;
	gchar *name;
	GtkTreeIter iter;

	action_get_hp_and_name (action, &hp, &name);
	gtk_list_store_append (store_actions, &iter);

	gtk_list_store_set (
		store_actions,
		&iter,
		0, name,
		1, hp,
		2, get_action_id (hp, name),
		-1
	);
}

void
parse_buffer_clicked_cb (
	GtkToolButton *button,
	gpointer user_data
) {
	gchar *buffer_text;
	GError *error = NULL;
	GList *actions;

	release_context ();

	buffer_text = buffer_get_text ();

	context = sprite_context_new (
		config_keys_get_data_folder_path ()
	);
	interactor = interactor_new (context);

	sprite_context_add_sprite (
		context,
		xml_parse_buffer (buffer_text, &error),
		-1
	);

	if (error != NULL) {
		post_error ("XML parser", error->message);
		g_error_free (error);
	}

	g_free (buffer_text);

	interactor_set_updated_callback (interactor, intr_updated);

	actions = sprite_context_get_actions (context);
	g_list_foreach (actions, (GFunc) store_append_action, NULL);
	g_list_free (actions);

	gtk_widget_queue_draw (d_area);
}

void
append_direction (const gchar *direction, gpointer user_data) {
	gchar *display;

	g_return_if_fail (direction != NULL);

	if (strlen (direction) == 0)
		display = g_strdup ("<empty>");
	else
		display = g_strdup (direction);

	gtk_combo_box_text_append (
		cb_directions,
		direction,
		display
	);

	g_free (display);
}

void
action_changed_cb (GtkComboBox *cbox, gpointer user_data) {
	GList *directions;
	GtkTreeIter iter;
	gint hp;
	gchar *name;
	const Action *action;
	gboolean w_run;

	g_return_if_fail (cbox == cb_actions);

	if (interactor == NULL)
		return;

	if (!gtk_combo_box_get_active_iter (cbox, &iter))
		return;

	gtk_tree_model_get (
		GTK_TREE_MODEL (store_actions),
		&iter,
		0, &name,
		1, &hp,
		-1
	);

	w_run = interactor_loop_running (interactor);
	if (w_run)
		interactor_loop_stop (interactor);

	gtk_combo_box_text_remove_all (cb_directions);

	action = sprite_context_get_action (context, hp, name);
	g_return_if_fail (action != NULL);

	directions = action_get_directions (action);
	g_list_foreach (directions, (GFunc) append_direction, NULL);
	g_list_free (directions);

	interactor_set_action (interactor, hp, name);

	if (w_run)
		interactor_loop_start (interactor, 10, 10);
}

void
direction_changed_cb (GtkComboBox *cbox, gpointer user_data) {
	gchar *active_text;

	g_return_if_fail (cbox == GTK_COMBO_BOX (cb_directions));

	if (interactor == NULL)
		return;

	active_text = gtk_combo_box_text_get_active_text (cb_directions);

	if (active_text == NULL)
		return;

	interactor_set_direction (
		interactor,
		active_text
	);
}

void 
play_pause_clicked_cb (
	GtkToolButton *button,
	gpointer user_data
) {
	if (interactor == NULL)
		return;

	if (interactor_loop_running (interactor))
		interactor_loop_stop (interactor);
	else
		interactor_loop_start (interactor, 10, 10);
}

void 
next_frame_clicked_cb (
	GtkToolButton *button,
	gpointer user_data
) {
	if (interactor == NULL)
		return;

	interactor_skip_current_frame (interactor);
}

void 
first_frame_clicked_cb (
	GtkToolButton *button,
	gpointer user_data
) {
	if (interactor == NULL)
		return;

	interactor_loop_stop (interactor);
	interactor_reset_animation (interactor);
}

void
choose_df_activated_cb (
	GtkMenuItem *item,
	gpointer user_data
) {
	TreeFolderView *tfview;
	GtkWidget *dialog;
	gint res;
	gchar *filename;

	g_return_if_fail (IS_TREE_FOLDER_VIEW (user_data));

	tfview = TREE_FOLDER_VIEW (user_data);
	dialog = gtk_file_chooser_dialog_new (
		"Choose data folder",
		GTK_WINDOW (main_window),
		GTK_FILE_CHOOSER_ACTION_SELECT_FOLDER,
		"Cancel", GTK_RESPONSE_CANCEL,
		"Open", GTK_RESPONSE_ACCEPT,
		NULL
	);

	gtk_file_chooser_set_filename (
		GTK_FILE_CHOOSER (dialog),
		tree_folder_view_get_filename (tfview)
	);

	res = gtk_dialog_run (GTK_DIALOG (dialog));

	if (res == GTK_RESPONSE_ACCEPT) {
		filename = gtk_file_chooser_get_filename (
			GTK_FILE_CHOOSER (dialog)
		);

		config_keys_set_data_folder_path (filename);
		config_keys_save ();

		tree_folder_view_set_filename (
			tfview,
			filename
		);

		g_free (filename);
	}
		
	gtk_widget_destroy (dialog);
}

void
open_file_activated_cb (
	GtkMenuItem *item,
	gpointer user_data
) {
	GtkWidget *dialog;
	GtkFileChooser *chooser;
	gint res;
	gchar *data_folder;

	dialog = gtk_file_chooser_dialog_new (
		NULL,
		GTK_WINDOW (main_window),
		GTK_FILE_CHOOSER_ACTION_OPEN,
		"_Cancel", GTK_RESPONSE_CANCEL,
		"_Open", GTK_RESPONSE_ACCEPT,
		NULL
	);
	
	data_folder = config_keys_get_data_folder_path ();

	chooser = GTK_FILE_CHOOSER (dialog);
	gtk_file_chooser_set_current_folder (
		chooser,
		data_folder
	);

	res = gtk_dialog_run (GTK_DIALOG (dialog));

	if (res == GTK_RESPONSE_ACCEPT) {
		gchar *filename = gtk_file_chooser_get_filename (chooser);
		open_file (filename);
		g_free (filename);
	}

	gtk_widget_destroy (dialog);
	g_free (data_folder);
}

void save_file_as_activated_cb (
	GtkMenuItem *item,
	gpointer user_data
) {
	GtkWidget *dialog;
	GtkFileChooser *chooser;
	gint res;
	gchar *data_folder;

	dialog = gtk_file_chooser_dialog_new (
		NULL,
		GTK_WINDOW (main_window),
		GTK_FILE_CHOOSER_ACTION_SAVE,
		"_Cancel", GTK_RESPONSE_CANCEL,
		"_Save", GTK_RESPONSE_ACCEPT,
		NULL
	);
	
	data_folder = config_keys_get_data_folder_path ();

	chooser = GTK_FILE_CHOOSER (dialog);
	gtk_file_chooser_set_do_overwrite_confirmation (chooser, TRUE);

	if (get_opened_file_name () != NULL) {
		gtk_file_chooser_set_current_name (
			chooser,
			get_opened_file_name ()
		);
	} else {
		gtk_file_chooser_set_current_folder (
			chooser,
			data_folder
		);
	}

	res = gtk_dialog_run (GTK_DIALOG (dialog));

	if (res == GTK_RESPONSE_ACCEPT) {
		gchar *filename = gtk_file_chooser_get_filename (chooser);
		save_file (filename);
		g_free (filename);
	}

	gtk_widget_destroy (dialog);
	g_free (data_folder);
}

void
save_file_activated_cb (
	GtkMenuItem *item,
	gpointer user_data
) {
	const gchar *filename;

	filename = get_opened_file_name ();

	if (filename == NULL) {
		save_file_as_activated_cb (item, user_data);
		return;
	}

	save_file (NULL);
}

void
zoom_adjustment_value_changed_cb (
	GtkAdjustment *adjustment,
	gpointer user_data
) {
	sprite_drawing_area_set_scale_factor (
		SPRITE_DRAWING_AREA (user_data),
		gtk_adjustment_get_value (adjustment)
	);
	gtk_widget_queue_draw (GTK_WIDGET (user_data));
}

void
tfview_file_activated_cb (
	TreeFolderView *tfview,
	gchar *filename,
	gpointer user_data
) {
	open_file (filename);
}

void
sourceview_buffer_modified_changed_cb (
	GtkTextBuffer *textbuffer,
	gpointer user_data
) {
	update_window_title ();
}

void
new_file_activated_cb (
	GtkMenuItem *item,
	gpointer user_data
) {
	open_file (NULL);
}

void
view_reset_to_center_activate_cb (
	GtkMenuItem *item,
	gpointer user_data
) {
	sprite_drawing_area_set_center (
		SPRITE_DRAWING_AREA (d_area),
		0, 0
	);

	gtk_widget_queue_draw (d_area);
}

void
show_tile_grid_toggled_cb (
	GtkCheckMenuItem *item,
	gpointer user_data
) {
	sda_layer_set_visible (
		tile_grid_layer, 
		gtk_check_menu_item_get_active (item)
	);

	gtk_widget_queue_draw (d_area);
}

void
show_pixel_grid_toggled_cb (
	GtkCheckMenuItem *item,
	gpointer user_data
) {
	sda_layer_set_visible (
		pixel_grid_layer, 
		gtk_check_menu_item_get_active (item)
	);

	gtk_widget_queue_draw (d_area);
}

void
menuitem_about_activate_cb (
	GtkMenuItem *item,
	gpointer user_data
) {
	gtk_dialog_run (GTK_DIALOG (user_data));
}

void
about_dialog_response_cb (
	GtkDialog *dialog,
	gint response_id,
	gpointer user_data
) {
	if (response_id == GTK_RESPONSE_DELETE_EVENT) {
		gtk_widget_hide (GTK_WIDGET (dialog));
	}
}
