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

static gchar *markup_bold(gchar *str);
static void format_src_string(gchar *src);
static void open_xml_file(GtkButton *button, gpointer buffer);
static void free_imagesets(SAEInfo *sae_info);
static void free_actions(SAEInfo *sae_info);
static void free_animations(SAEInfo *sae_info);
static void save_to_xml_file(GtkButton *button, gpointer buffer);
static void data_folder_set_callback(GtkFileChooserButton *widget, gpointer data);
static void show_wrong_source_buffer_dialog();
static GdkPixbuf* get_sprite_by_index(size_t index, SAEInfo *sae_info);
static void set_sprite_by_index(size_t index, SAEInfo *sae_info);
static void set_up_actions_by_imageset_name(gchar *imageset_name, SAEInfo *sae_info);
static gboolean set_up_imagesets(SAEInfo *sae_info);
static gboolean show_general_animation(SAEInfo *sae_info);
static gboolean set_up_action_by_name(const gchar *name, SAEInfo *sae_info);
static void actions_combo_box_changed_callback(GtkComboBox *widget, gpointer user_data);
static void animations_combo_box_changed_callback(GtkComboBox *widget, gpointer user_data);
static void set_up_imageset_by_name(const gchar* name, SAEInfo *sae_info);
static void imagesets_combo_box_changed_callback(GtkComboBox *widget, gpointer user_data);
static void parse_xml_buffer(GtkWidget *button, GtkSourceBuffer *buffer);
static void set_up_interface();
static void show_about_dialog();
static void show_imageset_dialog();
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
static void show_animation(SAEInfo *sae_info);
static gboolean set_up_animation_by_direction(SAEInfo *sae_info, const gchar *direction);
