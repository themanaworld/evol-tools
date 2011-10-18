/*=======================================*\
|  ____                         ____      |
| /    \         /\            |          |
| \____         /  \           |____      |
|      \       /____\          |          |
| \____/prite /      \nimation |____ditor |
|                                         |
|      Copyleft Vasily_Makarov 2011       |
|                                         |
\*=======================================*/

#ifndef MAIN_H
#define MAIN_H

const int MIN_WIDTH = 600;
const int MIN_HEIGHT = 600;

const gchar *DIR_GROUNDS = "grounds";
const gchar *DIR_PLAYERS = "players/";

const gchar *FILE_ICON = "icon.svg";

const int IMAGESET_PREVIEW_WINDOW_WIDTH = 200;
const int IMAGESET_PREVIEW_WINDOW_HEIGHT = 300;

GtkWidget *win = NULL;
GtkWidget *darea = NULL;
GtkWidget *data_folder_chooser_button = NULL;
GtkWidget *xml_file_chooser_button = NULL;
GtkWidget *xml_file_open_button = NULL;
GtkWidget *xml_file_save_button = NULL;
GtkWidget *imageset_preview_menu_item = NULL;
GtkWidget *show_grid_menu_item = NULL;
GtkWidget *source_view = NULL;

GtkSourceBuffer *source_buffer = NULL;

SAEInfo *gen_sae_info = NULL;
SAEInfo *player = NULL;

GdkPixbuf *icon = NULL;

Options *paths;
Keys *config;

gchar *markup_bold(gchar *str);
void format_src_string(gchar *src);
void open_xml_file(GtkButton *button);
void free_imagesets(SAEInfo *sae_info);
void free_actions(SAEInfo *sae_info);
void save_to_xml_file(gchar *filename);
void data_folder_set_callback(GtkFileChooserButton *widget, gpointer data);
void show_wrong_source_buffer_dialog();
void set_sprite_by_index(size_t index, SAEInfo *sae_info);
void set_up_actions_by_imageset_name(gchar *imageset_name, SAEInfo *sae_info);
gboolean set_up_imagesets(SAEInfo *sae_info);
gboolean show_general_animation(SAEInfo *sae_info);
gboolean set_up_action_by_name(const gchar *name, SAEInfo *sae_info);
void actions_combo_box_changed_callback(GtkComboBox *widget, gpointer user_data);
void animations_combo_box_changed_callback(GtkComboBox *widget, gpointer user_data);
void set_up_imageset_by_name(const gchar* name, SAEInfo *sae_info);
void imagesets_combo_box_changed_callback(GtkComboBox *widget, gpointer user_data);
void parse_xml_buffer(GtkWidget *button, GtkSourceBuffer *buffer);
void set_up_interface();
void show_about_dialog();
void show_imageset_dialog();
gboolean frame_image_button_press_event(GtkWidget *widget, GdkEventButton *button, int index);
cairo_surface_t *get_grid_surface(int w, int h);
gboolean darea_expose_event(GtkWidget *widget, GdkEventExpose *event, SAEInfo *sae_info);
void load_config();
void save_config_and_quit();
void load_options();
void free_imageset();
void show_grid_menu_item_toggled(GtkCheckMenuItem *checkmenuitem, gpointer user_data);
void open_menu_item_activate(GtkMenuItem *menuitem, GtkFileChooserDialog *fcdialog);
void parse_xml_text(gchar *text, SAEInfo *sae_info);
void show_animation(SAEInfo *sae_info);
void free_animations(SAEInfo *sae_info);

#endif
