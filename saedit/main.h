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
const gchar *DIR_PLAYERS = "players/";

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
  int offsetX;
  int offsetY;
  int width;
  int height;
  int spriteset_width;
  int spriteset_height;
  GdkPixbuf *spriteset;
} ImagesetInfo;

typedef struct {
  int index;
  int offsetX;
  int offsetY;
} SpriteInfo;
static SpriteInfo *sprite_info_new(int index, int offsetX, int offsetY);

static ImagesetInfo *imageset_info_new() {
  ImagesetInfo *res = g_new0(ImagesetInfo, 1);
  res->width = SPRITE_WIDTH_DEFAULT;
  res->height = SPRITE_HEIGHT_DEFAULT;
  return res;
}

typedef struct {
  GList *imagesets;
  GList *actions;
  GList *animations;
  ImagesetInfo *imageset;
  SpriteInfo *sprite;
  guint anim_tag;
  XMLNode *root;
  GtkWidget *imagesets_combo_box;
  GtkWidget *actions_combo_box;
  GtkWidget *animations_combo_box;
  GdkPixbuf *ground;
  int offsetX;
  int offsetY;
} SAEInfo;


typedef struct {
  GList *sub_nodes;
  guint *anim_tag;
  SAEInfo *sae_info;
} AnimationInfo;

static AnimationInfo *animation_info_new() {
  return g_new0(AnimationInfo, 1);
}

static AnimationInfo *animation_info_new_with_params(GList *sub_nodes_new, guint *anim_tag_new, SAEInfo *sae_info) {
  AnimationInfo *res = animation_info_new();
  res->sub_nodes = sub_nodes_new;
  res->anim_tag = anim_tag_new;
  res->sae_info = sae_info;
  return res;
}

typedef struct {
  XMLNode *node;
  int start;
  int end;
  guint delay;
  AnimationInfo *anim_info;
  int repeat;
} SequenceInfo;

static SequenceInfo *sequence_info_new(XMLNode *node, int start, int end, guint delay, AnimationInfo *anim_info, int repeat) {
  SequenceInfo *res = g_new0(SequenceInfo, 1);
  res->start = start;
  res->end = end;
  res->node = node;
  res->delay = delay;
  res->anim_info = anim_info;
  res->repeat = repeat;
  return res;
}

typedef struct {
  gchar *sprites;
} Options;

typedef struct {
  gchar *clientdata_folder;
  gboolean show_grid;
} Keys;

static Keys *keys_new() {
  Keys *res = g_new0(Keys, 1);
  res->clientdata_folder = KEY_CLIENTDATA_FOLDER_DEFAULT;
  res->show_grid = KEY_SHOW_GRID_DEFAULT;
  return res;
}

static GdkPixbuf *sae_info_ground_new() {
  GdkPixbuf *ground = gdk_pixbuf_new(GDK_COLORSPACE_RGB, TRUE, 8, GRID_SIZE * 3, GRID_SIZE * 3);
  gdk_pixbuf_fill(ground, 0x00000000);
  return ground;
}

static SAEInfo *sae_info_new() {
  SAEInfo *res = g_new0(SAEInfo, 1);
  res->ground = sae_info_ground_new();
  res->sprite = sprite_info_new(-1, 0, 0);
  res->imageset = imageset_info_new();
  return res;
}


GtkWidget *win = NULL;
GtkWidget *darea = NULL;
GtkWidget *data_folder_chooser_button = NULL;
GtkWidget *xml_file_chooser_button = NULL;
GtkWidget *xml_file_open_button = NULL;
GtkWidget *xml_file_save_button = NULL;
GtkWidget *imageset_preview_menu_item = NULL;
GtkWidget *show_grid_menu_item = NULL;

GtkSourceBuffer *source_buffer = NULL;

//GList *imagesets = NULL;
//GList *actions = NULL;
//GList *animations = NULL;
SAEInfo *gen_sae_info = NULL;
SAEInfo *player = NULL;

GdkPixbuf *icon = NULL;

//XMLNode *root = NULL;
//ImagesetInfo *imageset = NULL;
//guint running_animation = 0;
Options *paths;
Keys *config;

static gboolean show_animation_by_info(AnimationInfo *anim_info);
static gchar *markup_bold(gchar *str);
static void format_src_string(gchar *src);
static void open_xml_file(GtkButton *button, gpointer buffer);
static void free_imagesets(SAEInfo *sae_info);
static void free_actions(SAEInfo *sae_info);
static void free_animations(SAEInfo *sae_info);
static void save_to_xml_file(GtkButton *button, gpointer buffer);
static void data_folder_set_handler(GtkFileChooserButton *widget, gpointer data);
static void show_wrong_source_buffer_dialog();
static gchar* xml_node_get_attr_value(const XMLNode *node, const gchar *attr_name);
static gint xml_node_compare_with_name(gconstpointer a, gconstpointer b);
static gint xml_node_compare_with_action_node_by_imageset_name_func(gconstpointer a, gconstpointer b);
static gint xml_node_compare_with_direction_attr(gconstpointer node, gconstpointer direction);
static gint xml_node_compare_with_name_attr(gconstpointer node, gconstpointer name);
static GdkPixbuf* get_sprite_by_index(size_t index, SAEInfo *sae_info);
static void set_sprite_by_index(size_t index, SAEInfo *sae_info);
static void set_up_actions_by_imageset_name(gchar *imageset_name, SAEInfo *sae_info);
static gboolean set_up_imagesets(SAEInfo *sae_info);
static gboolean sequence_source_func(SequenceInfo *seq);
static gboolean show_general_animation(SAEInfo *sae_info);
static gboolean set_up_action_by_name(const gchar *name, SAEInfo *sae_info);
static void actions_combo_box_changed_handler(GtkComboBox *widget, gpointer user_data);
static void animations_combo_box_changed_handler(GtkComboBox *widget, gpointer user_data);
static void set_up_imageset_by_node(XMLNode *node, SAEInfo *sae_info);
static void imagesets_combo_box_changed_handler(GtkComboBox *widget, gpointer user_data);
static void parse_xml_buffer(GtkWidget *button, GtkSourceBuffer *buffer);
static void set_up_interface();
static void show_about_dialog();
static void show_imageset_window();
static gboolean frame_image_button_press_event(GtkWidget *widget, GdkEventButton *button, int index);
static cairo_surface_t *get_grid_surface(int w, int h);
static gboolean darea_expose_event(GtkWidget *widget, GdkEventExpose *event, SAEInfo *sae_info);
static void load_config();
static void save_config_and_quit();
static void load_options();
static void free_imageset();
static void kill_timeout(int tag);
static void show_grid_menu_item_toggled(GtkCheckMenuItem *checkmenuitem, gpointer user_data);
static void open_menu_item_activate(GtkMenuItem *menuitem, GtkFileChooserDialog *fcdialog);
static void parse_xml_text(gchar *text, SAEInfo *sae_info);
