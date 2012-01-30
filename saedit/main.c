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

#include "main.h"
#include "interface.c"

//Cairo functions

cairo_surface_t *get_grid_surface(int w, int h) {
  cairo_surface_t *surface = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, (w + 2) * GRID_SIZE, (h + 2) * GRID_SIZE);
  cairo_t *cr = cairo_create(surface);
  int x, y;

  for (x = 0; x < w; x++)
    for (y = 0; y < h; y++) {
    gdk_cairo_set_source_pixbuf(cr, gen_sae_info->ground, x * GRID_SIZE, y * GRID_SIZE);
    cairo_paint(cr);
  }

  if (config->show_grid) {
    cairo_surface_t *gridsurf = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, w * GRID_SIZE + 1, h * GRID_SIZE + 1);
    cairo_t *scr = cairo_create(gridsurf);
    cairo_set_line_width(scr, 1);
    cairo_set_source_rgba(scr, 0.5, 0.5, 0.5, 1);
    for (x = 0; x < w; x++)
      for (y = 0; y < h; y++) {
      cairo_rectangle(scr, x*GRID_SIZE+0.5, y*GRID_SIZE+0.5, GRID_SIZE, GRID_SIZE);
      cairo_stroke(scr);
    }
    cairo_set_source_surface(cr, gridsurf, GRID_SIZE, GRID_SIZE);
    cairo_paint(cr);
    cairo_destroy(scr);
    cairo_surface_destroy(gridsurf);
  }

  cairo_destroy(cr);
  return surface;
}

gboolean darea_expose_event(GtkWidget *widget, GdkEvent *event, SAEInfo *sae_info) {
  if (!(event->type == GDK_EXPOSE || event->type == GDK_DAMAGE)) return FALSE;
  if (sae_info == NULL)
	sae_info = gen_sae_info;

  int width = gtk_widget_get_allocated_width(widget),
      height = gtk_widget_get_allocated_height(widget);

  printf("W and H: %d %d\n", width, height);

  int w = 3, h = 3;

  cairo_t *cr = gdk_cairo_create(gtk_widget_get_parent_window(widget));

  cairo_surface_t *surface = get_grid_surface(w, h);
  cairo_set_source_surface(cr, surface, width/2 - GRID_SIZE * (w + 2) * 0.5, height/2 - GRID_SIZE * (h + 2) * 0.5);
  cairo_paint(cr);

  if (player != NULL) {
    GdkPixbuf *pbuf = player->sprite->pixbuf;
    if (pbuf == NULL) return FALSE;
    gdk_cairo_set_source_pixbuf(cr, pbuf,
                                width/2 - player->imageset->width/2 + player->offsetX + player->sprite->offsetX + player->imageset->offsetX,
                                height/2 + GRID_SIZE/2 - player->imageset->height + player->offsetY + player->sprite->offsetY + player->imageset->offsetY);
    cairo_paint(cr);
  }

  GdkPixbuf *pbuf = sae_info->sprite->pixbuf;
  if (pbuf == NULL) return FALSE;
  gdk_cairo_set_source_pixbuf(cr, pbuf,
                              width/2 - sae_info->imageset->width/2 + sae_info->offsetX + sae_info->sprite->offsetX + sae_info->imageset->offsetX,
                              height/2 +GRID_SIZE/2 - sae_info->imageset->height + sae_info->offsetY + sae_info->sprite->offsetY + sae_info->imageset->offsetY);
  cairo_paint(cr);

  cairo_destroy(cr);
  cairo_surface_destroy(surface);
  return FALSE;
}

//String functions (common)

gchar *markup_bold(gchar *str) {
  gchar buffer[255];
  g_sprintf(buffer, "<b>%s</b>", str);
  return buffer;
}

void format_src_string(gchar *src) {
  gchar *str = g_strrstr(src, "|");
  if (str == NULL) return;
  strncpy(str, "\0", 1);
}

//File working

void open_xml_file(GtkButton *button) {
  gtk_widget_set_sensitive(xml_file_open_button, TRUE);
  gtk_widget_set_sensitive(reload_menu_item, TRUE);
  gchar *buf;
  size_t len;
  g_file_get_contents(gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(xml_file_chooser_button)), &buf, &len, NULL);
  if (g_utf8_validate(buf, len, NULL)) {
    gtk_text_buffer_set_text(GTK_TEXT_BUFFER(source_buffer), buf, len);
    gtk_widget_set_sensitive(xml_file_save_button, TRUE);
  } else {
    gtk_file_chooser_unselect_all(GTK_FILE_CHOOSER(xml_file_chooser_button));
  }

  free_current_info();
}

void save_to_xml_file(gchar *filename) {
  GtkTextIter start, end;
  gtk_text_buffer_get_start_iter(GTK_TEXT_BUFFER(source_buffer), &start);
  gtk_text_buffer_get_end_iter(GTK_TEXT_BUFFER(source_buffer), &end);
  g_file_set_contents(filename, gtk_text_buffer_get_text(GTK_TEXT_BUFFER(source_buffer), &start, &end, NULL), -1, NULL);
}

//SAEInfo functions (must be ported to sae.c)

void free_imagesets(SAEInfo *sae_info) {
  free_imageset(sae_info);
  sae_info->imagesets = NULL;
  gtk_list_store_clear(GTK_LIST_STORE(gtk_combo_box_get_model(GTK_COMBO_BOX(sae_info->imagesets_combo_box))));
}

void free_imageset(SAEInfo *sae_info) {
  sae_info->imageset = imageset_new();
  sae_info->ground = sae_info_ground_new();
  gtk_widget_set_sensitive(imageset_preview_menu_item, FALSE);
}

void free_actions(SAEInfo *sae_info) {
  sae_info->actions = NULL;
  if (sae_info->actions_combo_box != NULL)
    gtk_list_store_clear(GTK_LIST_STORE(gtk_combo_box_get_model(GTK_COMBO_BOX(sae_info->actions_combo_box))));
}

void free_animations(SAEInfo *sae_info) {
  sae_info->animations = NULL;

  if (sae_info->animations_combo_box != NULL)
    gtk_list_store_clear(GTK_LIST_STORE(gtk_combo_box_get_model(GTK_COMBO_BOX(sae_info->animations_combo_box))));

  kill_timeout(sae_info->anim_tag);
  sae_info->anim_tag = 0;
  sae_info->sprite = frame_new(-1, 0, 0, 0);
  set_sprite_by_index(0, sae_info);
}

void free_lists(SAEInfo *sae_info) {
  free_imagesets(sae_info);
  free_actions(sae_info);
  free_animations(sae_info);
}

void free_current_info() {
  free_lists(gen_sae_info);
  player = NULL;
}

//Callbacks

void data_folder_set_callback(GtkFileChooserButton *widget, gpointer data)  {
  config->clientdata_folder = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(data_folder_chooser_button));
  gtk_file_chooser_set_current_folder(GTK_FILE_CHOOSER(xml_file_chooser_button), gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(widget)));
}

void show_grid_menu_item_toggled_callback(GtkCheckMenuItem *checkmenuitem, gpointer user_data) {
  config->show_grid = gtk_check_menu_item_get_active(checkmenuitem);
  gtk_widget_queue_draw(darea);
}

void show_wrong_source_buffer_dialog() {
  GtkWidget *dialog = gtk_message_dialog_new(GTK_WINDOW(win),
                                             GTK_DIALOG_DESTROY_WITH_PARENT,
                                             GTK_MESSAGE_WARNING,
                                             GTK_BUTTONS_OK,
                                             NULL);
  gtk_message_dialog_set_markup(GTK_MESSAGE_DIALOG(dialog), markup_bold(_("Wrong source buffer! Could not parse XML!")));
  g_signal_connect(dialog, "response", G_CALLBACK(gtk_widget_destroy), NULL);
  gtk_widget_show_all(dialog);
}

void actions_combo_box_changed_callback(GtkComboBoxText *widget, gpointer user_data) {
  if (player != NULL)
    set_up_action_by_name(gtk_combo_box_text_get_active_text(widget), player);
  set_up_action_by_name(gtk_combo_box_text_get_active_text(widget), gen_sae_info);
}

void animations_combo_box_changed_callback(GtkComboBoxText *widget, gpointer user_data) {
  set_up_animation_by_direction(gen_sae_info, gtk_combo_box_text_get_active_text(widget));
  if (player != NULL) {
    set_up_animation_by_direction(player, gtk_combo_box_text_get_active_text(widget));
    show_animation(player);
  }
  show_animation(gen_sae_info);
}

void imagesets_combo_box_changed_callback(GtkComboBoxText *widget, gpointer user_data) {
  if (gtk_combo_box_text_get_active_text(widget) != NULL)
    set_up_imageset_by_name(gtk_combo_box_text_get_active_text(widget), gen_sae_info);
}

gboolean frame_image_button_press_event_callback(GtkWidget *widget, GdkEventButton *button, int index) {
  gchar buf[10];
  gint len = g_sprintf(buf, "%d", index);
  gtk_text_buffer_insert_at_cursor(GTK_TEXT_BUFFER(source_buffer), buf, len);
  return FALSE;
}

void open_menu_item_activate_callback(GtkMenuItem *menuitem, GtkFileChooserDialog *fcdialog) {
  gtk_dialog_run(GTK_DIALOG(fcdialog));
}

//Dialogs

void show_about_dialog() {
  gtk_dialog_run(GTK_DIALOG(about_dialog));
  gtk_widget_hide(about_dialog);
}

void show_imageset_dialog() {
  if (gen_sae_info->imageset->spriteset == NULL) return;
  GtkWidget *dialog = gtk_dialog_new();
  GtkWidget *content_area = gtk_dialog_get_content_area(GTK_DIALOG(dialog));
  gtk_window_set_title(GTK_WINDOW(dialog), _("Imageset preview"));
  gtk_window_set_transient_for(GTK_WINDOW(dialog), GTK_WINDOW(win));

  int w = gen_sae_info->imageset->spriteset_width / gen_sae_info->imageset->width;
  int h = gen_sae_info->imageset->spriteset_height / gen_sae_info->imageset->height;

  GtkWidget *hbox = NULL;
  GtkWidget *image = NULL;
  GtkWidget *event_box = NULL;

  int x, y;
  for (y = 0; y < h; y++) {
    hbox = gtk_hbox_new(TRUE, 0);
    gtk_container_add(GTK_CONTAINER(content_area), hbox);
    for (x = 0; x < w; x++) {
      int id = w * y + x;
      event_box = gtk_event_box_new();
      g_signal_connect(G_OBJECT(event_box), "button-press-event", G_CALLBACK(frame_image_button_press_event_callback), &id);
      gtk_box_pack_start(GTK_BOX(hbox), event_box, TRUE, TRUE, 0);

      image = gtk_image_new_from_pixbuf(get_sprite_by_index(w * y + x, gen_sae_info));
      gtk_widget_add_events(image, GDK_BUTTON_PRESS_MASK);
      gtk_container_add(GTK_CONTAINER(event_box), image);
    }
  }
  gtk_widget_show_all(dialog);
}

//Main functions

void set_sprite_by_index(size_t index, SAEInfo *sae_info) {
  sae_info->sprite->pixbuf = get_sprite_by_index(index, sae_info);
  gtk_widget_queue_draw(darea);
}

void set_up_actions_by_imageset_name(gchar *imageset_name, SAEInfo *sae_info) {
  free_actions(sae_info);
  free_animations(sae_info);
  GList *_actions_list = NULL;
  GList *list = sae_info->root->sub_nodes;
  XMLNode *node = NULL;
  while (TRUE) {
    list = g_list_find_custom(list, imageset_name, xml_node_compare_with_action_node_by_imageset_name_func);
    if (list == NULL)
      break;
    if (_actions_list == NULL) {
      _actions_list = g_list_alloc();
      sae_info->actions = _actions_list;
      _actions_list->data = list->data;
    } else
      g_list_append(_actions_list, list->data);
    node = list->data;
    if (sae_info->actions_combo_box != NULL)
      gtk_combo_box_text_append_text(GTK_COMBO_BOX(sae_info->actions_combo_box), xml_node_get_attr_value(node, "name"));
    list = list->next;
  }
  if (sae_info->actions_combo_box != NULL);
    gtk_combo_box_set_active(GTK_COMBO_BOX(sae_info->actions_combo_box), 0);
}

gboolean set_up_imagesets(SAEInfo *sae_info) {
  GList *_imagesets_list = NULL;
  free_lists(sae_info);
  GList *list = sae_info->root->sub_nodes;
  XMLNode *node = NULL;
  while (TRUE) {
    list = g_list_find_custom(list, "imageset", xml_node_compare_with_name_func);
    if (list == NULL)
      break;
    if (_imagesets_list == NULL) {
      _imagesets_list = g_list_alloc();
      _imagesets_list->data = list->data;
      sae_info->imagesets = _imagesets_list;
    } else
      g_list_append(_imagesets_list, list->data);
    node = list->data;
    if (sae_info->imagesets_combo_box != NULL)
      gtk_combo_box_text_append_text(GTK_COMBO_BOX(sae_info->imagesets_combo_box), xml_node_get_attr_value(node, "name"));
    list = list->next;
  }
  if (_imagesets_list == NULL)
    return FALSE;
  if (sae_info->imagesets_combo_box != NULL)
    gtk_combo_box_set_active(GTK_COMBO_BOX(sae_info->imagesets_combo_box), 0);
  return TRUE;
}

void show_animation(SAEInfo *sae_info) {
  kill_timeout(sae_info->anim_tag);
  if (sae_info->animation == NULL)
    return;
  Frame *sprite = sae_info->animation->data;
  sae_info->sprite = sprite;
  gtk_widget_queue_draw(darea);
  sae_info->animation = sae_info->animation->next;
  sae_info->anim_tag = g_timeout_add(sprite->delay, show_animation, sae_info);
  return FALSE;
}

gboolean show_general_animation(SAEInfo *sae_info) {
  XMLNode *node = sae_info->animations->data;
  if (node == NULL)
    return FALSE;
  animations_combo_box_changed_callback(NULL, NULL);
}

gboolean set_up_action_by_name(const gchar *name, SAEInfo *sae_info) {
  free_animations(sae_info);
  GList *list = g_list_find_custom(sae_info->actions,
                                   xml_attr_new("name", name),
                                   xml_node_compare_with_attr_func);
  if (list == NULL) return FALSE;
  list = ((XMLNode *)list->data)->sub_nodes;
  gboolean was_direction = FALSE;
  while (TRUE) {
    list = g_list_find_custom(list, "animation", xml_node_compare_with_name_func);
    if (list == NULL)
      break;
    if (sae_info->animations == NULL) {
      sae_info->animations = g_list_alloc();
      sae_info->animations->data = list->data;
    } else
      g_list_append(sae_info->animations, list->data);
    XMLNode *node = list->data;
    gchar *direction = xml_node_get_attr_value(node, "direction");
    if (direction != NULL) {
      if (sae_info->animations_combo_box != NULL)
        gtk_combo_box_text_append_text(GTK_COMBO_BOX(sae_info->animations_combo_box), direction);
      was_direction = TRUE;
    }
    list = list->next;
  }
  if (sae_info->animations == NULL)
    return FALSE;
  if (!was_direction)
    show_general_animation(sae_info);
  else if (sae_info->animations_combo_box != NULL)
    gtk_combo_box_set_active(GTK_COMBO_BOX(sae_info->animations_combo_box), 0);
  return TRUE;
}

void set_up_imageset_by_name(const gchar *name, SAEInfo *sae_info) {
  free_imageset(sae_info);
  free_actions(sae_info);
  free_animations(sae_info);

  GList *list = g_list_find_custom(sae_info->imagesets,
                                   xml_attr_new("name", name),
                                   xml_node_compare_with_attr_func);

  if (list == NULL)
    return FALSE;

  XMLNode *node = list->data;
  if (node == NULL)
    return;

  sae_info->imageset->node = node;
  sae_info->imageset->offsetX = 0;
  sae_info->imageset->offsetY = 0;

  gchar *offset_attr = xml_node_get_attr_value(sae_info->imageset->node, "offsetX");
  if (offset_attr != NULL)
    sscanf(offset_attr, "%d", &sae_info->imageset->offsetX);

  offset_attr = xml_node_get_attr_value(sae_info->imageset->node, "offsetY");
  if (offset_attr != NULL)
    sscanf(offset_attr, "%d", &sae_info->imageset->offsetY);

  gchar *imageset_name = xml_node_get_attr_value(sae_info->imageset->node, "name");

  gchar *src = xml_node_get_attr_value(sae_info->imageset->node, "src");
  format_src_string(src);
  gchar *datapath = config->clientdata_folder;
  gchar *path = g_strjoin(SEPARATOR_SLASH, datapath, src, NULL);

  sae_info->imageset->spriteset = gdk_pixbuf_new_from_file(path, NULL);
  if (sae_info->imageset->spriteset == NULL) {
    show_wrong_source_buffer_dialog();
    return;
  }

  gtk_widget_set_sensitive(imageset_preview_menu_item, TRUE);
  sae_info->imageset->spriteset_width = gdk_pixbuf_get_width(sae_info->imageset->spriteset);
  sae_info->imageset->spriteset_height = gdk_pixbuf_get_height(sae_info->imageset->spriteset);

  gchar *width = xml_node_get_attr_value(sae_info->imageset->node, "width");
  sscanf(width, "%d", &sae_info->imageset->width);
  gchar *height = xml_node_get_attr_value(sae_info->imageset->node, "height");
  sscanf(height, "%d", &sae_info->imageset->height);

  list = g_list_find_custom(sae_info->root->sub_nodes, "sae", xml_node_compare_with_name_func);
  if (list != NULL) {
    gchar *ground_attr = xml_node_get_attr_value((XMLNode *)list->data, "ground");
    if (ground_attr != NULL) {
      ground_attr = g_strjoin(NULL, DIR_GROUNDS, SEPARATOR_SLASH, ground_attr, ".png", NULL);
      GdkPixbuf *pbuf = gdk_pixbuf_new_from_file(ground_attr, NULL);
      if(pbuf != NULL)
        sae_info->ground = pbuf;
    }
    gchar *player_attr = xml_node_get_attr_value((XMLNode *)list->data, "player");
    if (player_attr != NULL && player == NULL) {
      gchar *text;
      gchar *sprites_path = paths->sprites;
      gchar *player_file = g_strjoin(NULL, sprites_path, DIR_PLAYERS, player_attr, ".xml", NULL);
      if (g_file_get_contents(player_file, &text, NULL, NULL)) {
        player = sae_info_new();
        parse_xml_text(text, player);
        set_up_imageset_by_name("base", player);
      }
    }
  }
  set_up_actions_by_imageset_name(imageset_name, sae_info);
  if (sae_info->actions == NULL)
    return;
  set_sprite_by_index(0, sae_info);
}

void load_options() {
  gchar *datapath = config->clientdata_folder;
  gchar *path = g_strjoin(SEPARATOR_SLASH, datapath, "paths.xml", NULL);
  config_options_load_from_file(paths, path, datapath);
}

void parse_xml_text(gchar *text, SAEInfo *sae_info) {
  free_lists(sae_info);

  XMLNode *_root_node = ibus_xml_parse_buffer(text);
  sae_info->root = _root_node;
  if (_root_node == NULL) {
    show_wrong_source_buffer_dialog();
    return;
  }

  GList *list = g_list_find_custom(_root_node->sub_nodes, "include", xml_node_compare_with_name_func);
  while (list != NULL) {
    XMLNode *node = list->data;
    gchar *file_attr = xml_node_get_attr_value(node, "file");
    if (file_attr != NULL) {
      file_attr = g_strjoin(NULL, paths->sprites, file_attr, NULL);
      gchar *buf;
      if (g_file_get_contents(file_attr, &buf, NULL, NULL))
        g_list_concat(_root_node->sub_nodes, ibus_xml_parse_buffer(buf)->sub_nodes);
    }
    if (list->next != NULL)
      list = g_list_find_custom(list->next, "include", xml_node_compare_with_name_func);
    else
      list = NULL;
  }

  sae_info->offsetX = 0;
  sae_info->offsetY = 0;

  if (!set_up_imagesets(sae_info)) {
    show_wrong_source_buffer_dialog();
    return;
  }
}

void parse_xml_buffer(GtkWidget *button, GtkSourceBuffer *buffer) {
  if (buffer == NULL)
	buffer = source_buffer;

  player = NULL;
  load_options();

  GtkTextIter beg, end;
  gtk_text_buffer_get_start_iter(GTK_TEXT_BUFFER(buffer), &beg);
  gtk_text_buffer_get_end_iter(GTK_TEXT_BUFFER(buffer), &end);
  parse_xml_text(gtk_text_iter_get_text(&beg, &end), gen_sae_info);
}

void load_config() {
  config_keys_load(config);
  gtk_file_chooser_select_filename(GTK_FILE_CHOOSER(data_folder_chooser_button), config->clientdata_folder);
  gtk_check_menu_item_set_active(GTK_CHECK_MENU_ITEM(show_grid_menu_item), config->show_grid);
}

void save_config_and_quit() {
  config_keys_save(config);
  gtk_main_quit();
}

int main(int argc, char *argv[]) {

  gtk_init(&argc, &argv);

  icon = gdk_pixbuf_new_from_file(FILE_ICON, NULL);

  gen_sae_info = sae_info_new();
  config = config_keys_new();
  paths = config_options_new();

  set_up_interface();
  load_config();

  gtk_main();

  return 0;
}
