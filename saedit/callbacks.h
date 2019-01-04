#ifndef _CALLBACKS_H_
#define _CALLBACKS_H_

void
parse_buffer_clicked_cb (
	GtkToolButton *button,
	gpointer user_data
);

void
action_changed_cb (GtkComboBox *cbox, gpointer user_data);

void
direction_changed_cb (GtkComboBox *cbox, gpointer user_data) {

void 
play_pause_clicked_cb (
	GtkToolButton *button,
	gpointer user_data
);

void 
first_frame_clicked_cb (
	GtkToolButton *button,
	gpointer user_data
);

void
choose_df_activated_cb (
	GtkMenuItem *item,
	gpointer user_data
);

void
open_file_activated_cb (
	GtkMenuIterm *item,
	gpointer user_data
);

void
save_file_activated_cb (
	GtkMenuIterm *item,
	gpointer user_data
);

void
zoom_adjustment_value_changed_cb (
	GtkAdjustment *adjustment,
	gpointer user_data
);

void
tfview_file_activated_cb (
	TreeFolderView *tfview,
	gchar *filename,
	gpointer user_data
);

void
new_file_activated_cb (
	GtkMenuItem *item,
	gpointer user_data
);

void
save_file_as_activated_cb (
	GtkMenuItem *item,
	gpointer user_data
);

void
show_tile_grid_toggled_cb (
	GtkCheckMenuItem *item,
	gpointer user_data
);

void
show_pixel_grid_toggled_cb (
	GtkCheckMenuItem *item,
	gpointer user_data
);

void
menuitem_about_activate_cb (
	GtkMenuItem *item,
	gpointer user_data
);

void
about_dialog_response_cb (
	GtkDialog *dialog,
	gint response_id,
	gpointer user_data
);

#endif
