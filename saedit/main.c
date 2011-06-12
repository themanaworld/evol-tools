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
#include "interface.h"

void kill_timeout(int tag) {
  if (tag > 0)
    g_source_remove(tag);
}

SpriteInfo *sprite_info_new(int index, int offsetX, int offsetY) {
  SpriteInfo *res = g_new0(SpriteInfo, 1);
  res->index = index;
  res->offsetX = offsetX;
  res->offsetY = offsetY;
  return res;
}

cairo_surface_t *get_grid_surface(int w, int h) {
  cairo_surface_t *surface = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, (w + 2) * GRID_SIZE, (h + 2) * GRID_SIZE);
  cairo_t *cr = cairo_create(surface);
  int x, y;

  for (x = 0; x < w; x++)
    for (y = 0; y < h; y++) {
    gdk_cairo_set_source_pixbuf(cr, gen_sae_info->imageset->ground, x * GRID_SIZE, y * GRID_SIZE);
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

gboolean darea_expose_event(GtkWidget *widget, GdkEventExpose *event, gpointer data) {
  int width = widget->allocation.width,
      height = widget->allocation.height;

  int w = 3, h = 3;

  cairo_t *cr = gdk_cairo_create(widget->window);

  cairo_surface_t *surface = get_grid_surface(w, h);
  cairo_set_source_surface(cr, surface, width/2 - GRID_SIZE * (w + 2) * 0.5, height/2 - GRID_SIZE * (h + 2) * 0.5);
  cairo_paint(cr);

  GdkPixbuf *pbuf = get_sprite_by_index(gen_sae_info->sprite->index);
  if (pbuf == NULL) return FALSE;
  gdk_cairo_set_source_pixbuf(cr, pbuf,
                              width/2 - gen_sae_info->imageset->width/2 + offsetX + gen_sae_info->sprite->offsetX + gen_sae_info->imageset->offsetX,
                              height/2 - gen_sae_info->imageset->height/2 + offsetY + gen_sae_info->sprite->offsetY + gen_sae_info->imageset->offsetY);
  cairo_paint(cr);

  cairo_destroy(cr);
  cairo_surface_destroy(surface);
  return FALSE;
}

gchar *markup_bold(gchar *str) {
  gchar *buffer[255];
  g_sprintf(buffer, "<b>%s</b>", str);
  return buffer;
}

void format_src_string(gchar *src) {
  gchar *str = g_strrstr(src, "|");
  if (str == NULL) return;
  strncpy(str, "\0", 1);
}

void open_xml_file(GtkButton *button, gpointer buffer) {
  gtk_widget_set_sensitive(xml_file_open_button, TRUE);
  gchar *buf;
  size_t len;
  g_file_get_contents(gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(xml_file_chooser_button)), &buf, &len, NULL);
  gtk_text_buffer_set_text((GtkTextBuffer *)buffer, buf, len);
  gtk_widget_set_sensitive(xml_file_save_button, TRUE);
}

void free_imagesets(SAEInfo *sae_info) {
  free_imageset(sae_info);
  sae_info->imagesets = NULL;
  if (sae_info->imagesets_combo_box != NULL)
    gtk_list_store_clear(GTK_LIST_STORE(gtk_combo_box_get_model(GTK_COMBO_BOX(sae_info->imagesets_combo_box))));
}

void free_imageset(SAEInfo *sae_info) {
  sae_info->imageset = imageset_info_new();
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
  sae_info->sprite = sprite_info_new(-1, 0, 0);
  set_sprite_by_index(0);
}

void save_to_xml_file(GtkButton *button, gpointer buffer) {
  g_file_set_contents(gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(xml_file_chooser_button)), buffer, sizeof(buffer), NULL);
}

void data_folder_set_handler(GtkFileChooserButton *widget, gpointer data)  {
  config->clientdata_folder = g_strjoin(SEPARATOR_SLASH, gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(data_folder_chooser_button)), POSTFIX_FOLDER, NULL);
  gtk_file_chooser_set_current_folder(GTK_FILE_CHOOSER(xml_file_chooser_button), gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(widget)));
}

void show_grid_menu_item_toggled(GtkCheckMenuItem *checkmenuitem, gpointer user_data) {
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

gchar* xml_node_get_attr_value(const XMLNode *node, const gchar *attr_name) {
  gchar **attr = node->attributes;
  int i;
  for (i = 0; i < g_strv_length(attr); i += 2)
    if (g_str_equal(attr[i], attr_name))
      return attr[i + 1];
  return NULL;
}


gint xml_node_compare_with_name(gconstpointer a, gconstpointer b) {
  return g_strcmp0((gchar *)b, ((XMLNode *)a)->name);
}

gint xml_node_compare_with_action_node_by_imageset_name_func(gconstpointer a, gconstpointer b) {
  return g_strcmp0("action", ((XMLNode *)a)->name) ||
    g_strcmp0((gchar *)b, xml_node_get_attr_value((XMLNode *)a, "imageset"));
}

gint xml_node_compare_with_direction_attr(gconstpointer node, gconstpointer direction) {
  return g_strcmp0((gchar *)direction, xml_node_get_attr_value((XMLNode *)node, "direction"));
}

gint xml_node_compare_with_name_attr(gconstpointer node, gconstpointer name) {
  return g_strcmp0((gchar *)name, xml_node_get_attr_value((XMLNode *)node, "name"));
}

GdkPixbuf* get_sprite_by_index(size_t index) {
  size_t w = spriteset_width/gen_sae_info->imageset->width;
  if (gen_sae_info->imageset->spriteset == NULL) return NULL;
  return gdk_pixbuf_new_subpixbuf(gen_sae_info->imageset->spriteset, index%w*gen_sae_info->imageset->width, index/w*gen_sae_info->imageset->height, gen_sae_info->imageset->width, gen_sae_info->imageset->height);
}

void set_sprite_by_index(size_t index) {
  gen_sae_info->sprite->index = index;
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
      gtk_combo_box_append_text(GTK_COMBO_BOX(sae_info->actions_combo_box), xml_node_get_attr_value(node, "name"));
    list = list->next;
  }
}

gboolean set_up_imagesets(SAEInfo *sae_info) {
  GList *_imagesets_list = NULL;
  free_imagesets(sae_info);
  free_actions(sae_info);
  free_animations(sae_info);
  GList *list = sae_info->root->sub_nodes;
  XMLNode *node = NULL;
  while (TRUE) {
    list = g_list_find_custom(list, "imageset", xml_node_compare_with_name);
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
      gtk_combo_box_append_text(GTK_COMBO_BOX(sae_info->imagesets_combo_box), xml_node_get_attr_value(node, "name"));
    list = list->next;
  }
  if (_imagesets_list == NULL)
    return FALSE;
  if (sae_info->imagesets_combo_box != NULL)
    gtk_combo_box_set_active(GTK_COMBO_BOX(sae_info->imagesets_combo_box), 0);
  return TRUE;
}

gboolean sequence_source_func(SequenceInfo *seq) {
  if (gen_sae_info->sprite->index == seq->end) {
    if (seq->repeat <= 1) {
      guint *anim_tag = seq->anim_info->anim_tag;
      *anim_tag = g_timeout_add(seq->delay, show_animation_by_info, seq->anim_info);
      return FALSE;
    } else {
      seq->repeat--;
      gen_sae_info->sprite->index = seq->start - 1;
    }
  }
  set_sprite_by_index(gen_sae_info->sprite->index+1);
  return TRUE;
}

gboolean show_animation_by_info(AnimationInfo *anim_info) {
  GList *sub_nodes = anim_info->sub_nodes;
  guint *anim_tag = anim_info->anim_tag;
  XMLNode *node = sub_nodes->data;
  if (node == NULL)
    return FALSE;

  GList *next = sub_nodes->next;
  if (next == NULL)
    next = g_list_first(sub_nodes);

  if (g_strcmp0(node->name, "end")) {
    int ofX = 0, ofY = 0;
    gchar *ofX_param, *ofY_param;
    ofX_param = xml_node_get_attr_value(node, "offsetX");
    if (ofX_param != NULL)
      sscanf(ofX_param, "%d", &ofX);
    ofY_param = xml_node_get_attr_value(node, "offsetY");
    if (ofY_param != NULL)
      sscanf(ofY_param, "%d", &ofY);
    gen_sae_info->sprite->offsetX = ofX;
    gen_sae_info->sprite->offsetY = ofY;
  }

  if (g_strcmp0(node->name, "frame") == 0) {
    gchar *index_attr = xml_node_get_attr_value(node, "index");
    if (index_attr == NULL)
      return FALSE;
    size_t index;
    sscanf(index_attr, "%d", &index);
    set_sprite_by_index(index);
    if (g_list_length(g_list_first(sub_nodes)) == 1)
      return FALSE;
    size_t delay = 0;
    gchar *delay_attr = xml_node_get_attr_value(node, "delay");
    if (delay_attr != NULL)
      sscanf(delay_attr, "%d", &delay);
    anim_info->sub_nodes = next;
    kill_timeout(*anim_tag);
    *anim_tag = g_timeout_add(delay, show_animation_by_info, anim_info);
    return FALSE;
  }
  if (g_strcmp0(node->name, "sequence") == 0) {
    gchar *start_attr = xml_node_get_attr_value(node, "start");
    if (start_attr == NULL)
      return FALSE;
    gchar *end_attr = xml_node_get_attr_value(node, "end");
    if (end_attr == NULL)
      return FALSE;
    gchar *delay_attr = xml_node_get_attr_value(node, "delay");
    if (delay_attr == NULL)
      return FALSE;
    gchar *repeat_attr = xml_node_get_attr_value(node, "repeat");

    size_t start;
    sscanf(start_attr, "%d", &start);
    size_t end;
    sscanf(end_attr, "%d", &end);
    size_t delay;
    sscanf(delay_attr, "%d", &delay);
    size_t repeat = 1;
    if (repeat_attr != NULL)
      sscanf(repeat_attr, "%d", &repeat);
    set_sprite_by_index(start);
    anim_info->sub_nodes = next;
    kill_timeout(*anim_tag);
    *anim_tag = g_timeout_add(delay, sequence_source_func, sequence_info_new(node, start, end, delay, anim_info, repeat));
    return FALSE;
  }
  return FALSE;
}

gboolean show_general_animation(SAEInfo *sae_info) {
  XMLNode *node = sae_info->animations->data;
  if (node == NULL)
    return FALSE;
  return show_animation_by_info(animation_info_new_with_params(node->sub_nodes, &sae_info->anim_tag));
}

gboolean set_up_action_by_name(const gchar *name, SAEInfo *sae_info) {
  free_animations(sae_info);
  GList *list = g_list_find_custom(sae_info->actions, name, xml_node_compare_with_name_attr);
  if (list == NULL) return FALSE;
  list = ((XMLNode *)list->data)->sub_nodes;
  gboolean was_direction = FALSE;
  while (TRUE) {
    list = g_list_find_custom(list, "animation", xml_node_compare_with_name);
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
        gtk_combo_box_append_text(GTK_COMBO_BOX(sae_info->animations_combo_box), direction);
      was_direction = TRUE;
    }
    list = list->next;
  }
  if (sae_info->animations == NULL)
    return FALSE;
  if (!was_direction)
    show_general_animation(sae_info);
  return TRUE;
}

void actions_combo_box_changed_handler(GtkComboBox *widget, gpointer user_data) {
  set_up_action_by_name(gtk_combo_box_get_active_text(widget), gen_sae_info);
}

void animations_combo_box_changed_handler(GtkComboBox *widget, gpointer user_data) {
  GList *list = g_list_find_custom(gen_sae_info->animations, gtk_combo_box_get_active_text(widget), xml_node_compare_with_direction_attr);
  if (list == NULL)
    return;
  XMLNode *node = list->data;
  show_animation_by_info(animation_info_new_with_params(node->sub_nodes, &gen_sae_info->anim_tag));
}

void set_up_imageset_by_node(XMLNode *node, SAEInfo *sae_info) {
  free_imageset(sae_info);
  free_actions(sae_info);
  free_animations(sae_info);

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
  set_up_actions_by_imageset_name(imageset_name, sae_info);
  if (sae_info->actions == NULL)
    return;

  gchar *src = xml_node_get_attr_value(sae_info->imageset->node, "src");
  format_src_string(src);
  gchar *datapath = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(data_folder_chooser_button));
  gchar path[255];
  g_sprintf(path, "%s/%s", datapath, src);

  sae_info->imageset->spriteset = gdk_pixbuf_new_from_file(path, NULL);
  if (sae_info->imageset->spriteset == NULL) {
    show_wrong_source_buffer_dialog();
    return;
  }
  gtk_widget_set_sensitive(imageset_preview_menu_item, TRUE);
  spriteset_width = gdk_pixbuf_get_width(sae_info->imageset->spriteset);
  spriteset_height = gdk_pixbuf_get_height(sae_info->imageset->spriteset);

  gchar *width = xml_node_get_attr_value(sae_info->imageset->node, "width");
  sscanf(width, "%d", &sae_info->imageset->width);
  gchar *height = xml_node_get_attr_value(sae_info->imageset->node, "height");
  sscanf(height, "%d", &sae_info->imageset->height);

  GList *list = g_list_find_custom(sae_info->root->sub_nodes, "sae", xml_node_compare_with_name);
  if (list != NULL) {
    gchar *ground_attr = xml_node_get_attr_value((XMLNode *)list->data, "ground");
    if (ground_attr != NULL) {
      ground_attr = g_strjoin(NULL, DIR_GROUNDS, SEPARATOR_SLASH, ground_attr, ".png", NULL);
      GdkPixbuf *pbuf = gdk_pixbuf_new_from_file(ground_attr, NULL);
      if(pbuf != NULL)
        sae_info->imageset->ground = pbuf;
    }
  }

  set_sprite_by_index(0);
}

void imagesets_combo_box_changed_handler(GtkComboBox *widget, gpointer user_data) {
  GList *list = g_list_find_custom(gen_sae_info->imagesets, gtk_combo_box_get_active_text(widget), xml_node_compare_with_name_attr);
  if (list == NULL)
    return;
  set_up_imageset_by_node(list->data, gen_sae_info);
}

void load_options() {
  paths->sprites = NULL;
  gchar *datapath = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(data_folder_chooser_button));
  gchar *path = g_strjoin(SEPARATOR_SLASH, datapath, "paths.xml", NULL);
  XMLNode *node = ibus_xml_parse_file(path);
  if (node != NULL) {
    GList *list = node->sub_nodes;
    while (TRUE) {
      list = g_list_find_custom(list, "option", xml_node_compare_with_name);
      if (list == NULL)
        break;
      gchar *name_attr = xml_node_get_attr_value(list->data, "name");
      if (name_attr != NULL) {
        if (g_strcmp0(name_attr, "sprites") == 0)
          paths->sprites = xml_node_get_attr_value(list->data, "value");
      }
      list = list->next;
    }
  }
  if (paths->sprites == NULL) paths->sprites = OPTION_SPRITES_DEFAULT;
  paths->sprites = g_strjoin(SEPARATOR_SLASH, datapath, paths->sprites, NULL);
}

void parse_xml_text(gchar *text, SAEInfo *sae_info) {
  XMLNode *_root_node = ibus_xml_parse_buffer(text);
  sae_info->root = _root_node;
  if (_root_node == NULL) {
    show_wrong_source_buffer_dialog();
    return;
  }

  printf("%s", paths->sprites);
  GList *list = g_list_find_custom(_root_node->sub_nodes, "include", xml_node_compare_with_name);
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
      list = g_list_find_custom(list->next, "include", xml_node_compare_with_name);
    else
      list = NULL;
  }

  offsetX = 0;
  offsetY = 0;
  gchar *name_attr = xml_node_get_attr_value(_root_node, "name");
  gchar *action_attr = xml_node_get_attr_value(_root_node, "action");
  if (name_attr != NULL && action_attr != NULL)
    if (g_strcmp0(name_attr, "player") == 0 &&
        g_strcmp0(action_attr, "stand") == 0)
          offsetY = -16;

  if (!set_up_imagesets(sae_info)) {
    show_wrong_source_buffer_dialog();
    return;
  }
}

void parse_xml_buffer(GtkWidget *button, GtkSourceBuffer *buffer) {
  free_imagesets(gen_sae_info);
  free_actions(gen_sae_info);
  free_animations(gen_sae_info);
  load_options();

  GtkTextIter beg, end;
  gtk_text_buffer_get_start_iter(GTK_TEXT_BUFFER(buffer), &beg);
  gtk_text_buffer_get_end_iter(GTK_TEXT_BUFFER(buffer), &end);
  parse_xml_text(gtk_text_iter_get_text(&beg, &end), gen_sae_info);
}

void show_about_dialog() {
  gchar *authors[] = {"Dan Sagunov <danilka.pro@gmail.com>",
                      "Reid Yaro <reidyaro@gmail.com>",
                      NULL};
  gtk_show_about_dialog(GTK_WINDOW(win),
                        "authors", authors,
                        "comments", _("Sprite Animation Editor could be used to edit animations from Evol and The Mana World projects"),
                        "copyright", "Copyleft \u2184 Vasily_Makarov 2011",
                        "program-name", "Sprite Animation Editor",
                        "version", "0.1 prealpha",
                        "logo", icon,
                        NULL);
}

void open_menu_item_activate(GtkMenuItem *menuitem, GtkFileChooserDialog *fcdialog) {
  gtk_dialog_run(fcdialog);
}

gboolean frame_image_button_press_event(GtkWidget *widget, GdkEventButton *button, int index) {
  gchar buf[10];
  gint len = g_sprintf(buf, "%d", index);
  gtk_text_buffer_insert_at_cursor(GTK_TEXT_BUFFER(source_buffer), buf, len);
  return FALSE;
}

void show_imageset_window() {
  if (gen_sae_info->imageset->spriteset == NULL) return;
  GtkWidget *iwin = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(iwin), "Imageset preview");
  gtk_window_set_position(GTK_WINDOW(iwin), GTK_WIN_POS_CENTER);
  gtk_widget_add_events(iwin, GDK_BUTTON_PRESS_MASK);
  gtk_widget_set_size_request(iwin, IMAGESET_PREVIEW_WINDOW_WIDTH, IMAGESET_PREVIEW_WINDOW_HEIGHT);
  gtk_widget_realize(win);
  int w = spriteset_width / gen_sae_info->imageset->width;
  int h = spriteset_height / gen_sae_info->imageset->height;

  GtkWidget *vbox = gtk_vbox_new(TRUE, 0);
  GtkWidget *hbox = NULL;
  GtkWidget *image = NULL;
  GtkWidget *event_box = NULL;

  int x, y;
  for (y = 0; y < h; y++) {
    hbox = gtk_hbox_new(TRUE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), hbox, TRUE, TRUE, 0);
    for (x = 0; x < w; x++) {
      event_box = gtk_event_box_new();
      g_signal_connect(G_OBJECT(event_box), "button-press-event", G_CALLBACK(frame_image_button_press_event), w * y + x);
      gtk_box_pack_start(GTK_BOX(hbox), event_box, TRUE, TRUE, 0);

      image = gtk_image_new_from_pixbuf(get_sprite_by_index(w * y + x));
      gtk_widget_add_events(image, GDK_BUTTON_PRESS_MASK);
      gtk_container_add(GTK_CONTAINER(event_box), image);
    }
  }
  gtk_container_add(GTK_CONTAINER(iwin), vbox);
  gtk_widget_show_all(iwin);
}

void load_config() {
  GKeyFile *key_file = g_key_file_new();

  g_key_file_load_from_file(key_file, g_strjoin(SEPARATOR_SLASH, g_get_user_config_dir(), FILE_CONFIG, NULL), G_KEY_FILE_NONE, NULL);
  if (g_key_file_has_key(key_file, "General", "ClientdataFolder", NULL))
    config->clientdata_folder = g_key_file_get_value(key_file, "General", "ClientdataFolder", NULL);
  if (g_key_file_has_key(key_file, "General", "ShowGrid", NULL))
    config->show_grid = g_key_file_get_boolean(key_file, "General", "ShowGrid", NULL);

  gtk_file_chooser_select_filename(GTK_FILE_CHOOSER(data_folder_chooser_button), config->clientdata_folder);
  gtk_check_menu_item_set_active(GTK_CHECK_MENU_ITEM(show_grid_menu_item), config->show_grid);

  g_key_file_free(key_file);
}

void save_config_and_quit() {
  GKeyFile *key_file = g_key_file_new();
  g_key_file_set_value(key_file, "General", "ClientdataFolder", config->clientdata_folder);
  g_key_file_set_boolean(key_file, "General", "ShowGrid", config->show_grid);
  g_file_set_contents(g_strjoin(SEPARATOR_SLASH, g_get_user_config_dir(), FILE_CONFIG, NULL), g_key_file_to_data(key_file, NULL, NULL), -1, NULL);
  g_key_file_free(key_file);
  gtk_main_quit();
}

int main(int argc, char *argv[]) {

  gtk_init(&argc, &argv);

  icon = gdk_pixbuf_new_from_file(FILE_ICON, NULL);

  config = keys_new();
  paths = g_new0(Options, 1);
  gen_sae_info = sae_info_new();
  gen_sae_info->sprite = sprite_info_new(-1, 0, 0);
  gen_sae_info->imageset = imageset_info_new();

  set_up_interface();
  load_config();

  show_imageset_window();

  gtk_main();

  return 0;
}
