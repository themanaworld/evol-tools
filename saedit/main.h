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

#include <stdlib.h>
#include <gtk/gtk.h>
#include <gtksourceview/gtksourceview.h>
#include <gtksourceview/gtksourcelanguagemanager.h>
#include <ibusxml.h>
#include <cairo.h>
#include <glib/gi18n.h>

const int MIN_WIDTH = 600;
const int MIN_HEIGHT = 600;
const int SPRITE_WIDTH_DEFAULT = 64;
const int SPRITE_HEIGHT_DEFAULT = 64;
const int GRID_SIZE = 32;
const gchar *DIR_GROUNDS = "grounds";
const gchar *FILE_ICON = "icon.svg";
const gchar *FILE_CONFIG = "saedit/config.ini";
const gchar *POSTFIX_FOLDER = "...";
const gchar *SEPARATOR_SLASH = "/";
const gchar *OPTION_SPRITES_DEFAULT = "graphics/sprites/";

const gboolean KEY_SHOW_GRID_DEFAULT = TRUE;
const gchar *KEY_CLIENTDATA_FOLDER_DEFAULT = "";

const int IMAGESET_PREVIEW_WINDOW_WIDTH = 200;
const int IMAGESET_PREVIEW_WINDOW_HEIGHT = 300;


typedef struct {
  XMLNode *node;
  GList *next;
  guint delay;
} sequence;

typedef struct {
  int index;
  int offsetX;
  int offsetY;
} sprite_info;
static sprite_info *sprite_info_new(int index, int offsetX, int offsetY);

typedef struct {
  gchar *sprites;
} options;

typedef struct {
  gchar *clientdata_folder;
  gboolean show_grid;
} keys;

static keys *keys_new() {
  keys *res = g_new0(keys, 1);
  res->clientdata_folder = KEY_CLIENTDATA_FOLDER_DEFAULT;
  res->show_grid = KEY_SHOW_GRID_DEFAULT;
}

typedef struct {
  XMLNode *node;
  int offsetX;
  int offsetY;
  GdkPixbuf *spriteset;
  GdkPixbuf *ground;
} imageset_info;
static imageset_info *imageset_info_new() {
  imageset_info *res = g_new0(imageset_info, 1);
  res->ground = gdk_pixbuf_new(GDK_COLORSPACE_RGB, TRUE, 8, GRID_SIZE * 3, GRID_SIZE * 3);
  gdk_pixbuf_fill(res->ground, 0x00000000);
  return res;
}

int sprite_width = 64, sprite_height = 64;
int spriteset_width, spriteset_height;
int offsetX = 0, offsetY = 0;

GtkWidget *win = NULL;
GtkWidget *darea = NULL;
GtkWidget *data_folder_chooser_button = NULL;
GtkWidget *xml_file_chooser_button = NULL;
GtkWidget *xml_file_open_button = NULL;
GtkWidget *xml_file_save_button = NULL;
GtkWidget *imagesets_combo_box = NULL;
GtkWidget *actions_combo_box = NULL;
GtkWidget *animations_combo_box = NULL;
GtkWidget *imageset_preview_menu_item = NULL;
GtkWidget *show_grid_menu_item = NULL;

GtkSourceBuffer *source_buffer = NULL;

GList *imagesets = NULL;
GList *actions = NULL;
GList *animations = NULL;

GdkPixbuf *icon = NULL;

XMLNode *root = NULL;
imageset_info *imageset = NULL;
sprite_info *current_sprite;
guint running_animation = 0;
options *paths;
keys *config;

static gboolean show_animation_by_sub_nodes (GList *sub_nodes);
static gchar *markup_bold(gchar *str);
static void format_src_string(gchar *src);
static void open_xml_file(GtkButton *button, gpointer buffer);
static void free_imagesets();
static void free_actions();
static void free_animations();
static void save_to_xml_file(GtkButton *button, gpointer buffer);
static void data_folder_set_handler(GtkFileChooserButton *widget, gpointer data);
static void show_wrong_source_buffer_dialog();
static gchar* xml_node_get_attr_value(const XMLNode *node, const gchar *attr_name);
static gint xml_node_compare_with_name(gconstpointer a, gconstpointer b);
static gint xml_node_compare_with_action_node_by_imageset_name_func(gconstpointer a, gconstpointer b);
static gint xml_node_compare_with_direction_attr(gconstpointer node, gconstpointer direction);
static gint xml_node_compare_with_name_attr(gconstpointer node, gconstpointer name);
static GdkPixbuf* get_sprite_by_index(size_t index);
static void set_sprite_by_index(size_t index);
static void set_up_actions_by_imageset_name(gchar *imageset_name);
static gboolean set_up_imagesets(const XMLNode *root);
static gboolean sequence_source_func(sequence *seq);
static gboolean show_general_animation();
static gboolean set_up_action_by_name(const gchar *name);
static void actions_combo_box_changed_handler(GtkComboBox *widget, gpointer user_data);
static void animations_combo_box_changed_handler(GtkComboBox *widget, gpointer user_data);
static void set_up_imageset_by_node(XMLNode *node);
static void imagesets_combo_box_changed_handler(GtkComboBox *widget, gpointer user_data);
static void parse_xml_buffer(GtkWidget *button, GtkSourceBuffer *buffer);
static void set_up_interface();
static void show_about_dialog();
static void show_imageset_window();
static gboolean frame_image_button_press_event(GtkWidget *widget, GdkEventButton *button, int index);
static cairo_surface_t *get_grid_surface(int w, int h);
static gboolean darea_expose_event(GtkWidget *widget, GdkEventExpose *event, gpointer data);
static void load_config();
static void save_config_and_quit();
static void load_options();
static void free_imageset();
static void kill_timeout(int tag);
static void show_grid_menu_item_toggled(GtkCheckMenuItem *checkmenuitem, gpointer user_data);
static void open_menu_item_activate(GtkMenuItem *menuitem, GtkFileChooserDialog *fcdialog);
