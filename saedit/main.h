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

#include <stdlib.h>
#include <gtk/gtk.h>
#include <gtksourceview/gtksourceview.h>
#include <gtksourceview/gtksourcelanguagemanager.h>
#include <cairo.h>
#include <glib/gi18n.h>

#include "common.h"
#include "xml.h"
#include "config.h"
#include "sae.h"
#include "search.h"

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
GtkWidget *about_dialog = NULL;

GtkSourceBuffer *source_buffer = NULL;

SAEInfo *gen_sae_info = NULL;
SAEInfo *player = NULL;

GdkPixbuf *icon = NULL;

Options *paths;
Keys *config;

//Cairo functions
cairo_surface_t *get_grid_surface(int w, int h);
gboolean darea_expose_event(GtkWidget *widget, GdkEvent *event, SAEInfo *sae_info);

//String functions (common)
gchar *markup_bold(gchar *str);
void format_src_string(gchar *src);

//File working
void open_xml_file(GtkButton *button);
void save_to_xml_file(gchar *filename);

//SAEInfo functions
void free_imagesets(SAEInfo *sae_info);
void free_actions(SAEInfo *sae_info);
void free_animations(SAEInfo *sae_info);
void free_imageset(SAEInfo *sae_info);
void free_lists(SAEInfo *sae_info);

void free_current_info();

//Callbacks
void data_folder_set_callback(GtkFileChooserButton *widget, gpointer data);
void show_wrong_source_buffer_dialog();
void show_grid_menu_item_toggled_callback(GtkCheckMenuItem *checkmenuitem, gpointer user_data);
void actions_combo_box_changed_callback(GtkComboBoxText *widget, gpointer user_data);
void imagesets_combo_box_changed_callback(GtkComboBoxText *widget, gpointer user_data);
void open_menu_item_activate_callback(GtkMenuItem *menuitem, GtkFileChooserDialog *fcdialog);
gboolean frame_image_button_press_event_callback(GtkWidget *widget, GdkEventButton *button, int index);

//Dialogs
void show_imageset_dialog();
void show_about_dialog();

void set_sprite_by_index(size_t index, SAEInfo *sae_info);
void set_up_actions_by_imageset_name(gchar *imageset_name, SAEInfo *sae_info);
gboolean set_up_imagesets(SAEInfo *sae_info);
gboolean show_general_animation(SAEInfo *sae_info);
gboolean set_up_action_by_name(const gchar *name, SAEInfo *sae_info);
void animations_combo_box_changed_callback(GtkComboBoxText *widget, gpointer user_data);
void set_up_imageset_by_name(const gchar* name, SAEInfo *sae_info);
void parse_xml_buffer(GtkWidget *button, GtkSourceBuffer *buffer);
void set_up_interface();
void load_config();
void save_config_and_quit();
void load_options();
void parse_xml_text(gchar *text, SAEInfo *sae_info);
void show_animation(SAEInfo *sae_info);

#endif
