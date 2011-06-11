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

sprite_info *sprite_info_new(int index, int offsetX, int offsetY) {
  sprite_info *res = g_new0(sprite_info, 1);
  res->index = index;
  res->offsetX = offsetX;
  res->offsetY = offsetY;
  return res;
}
cairo_surface_t *get_grid_surface(int w, int h) {
  cairo_surface_t *surface = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, (w + 2) * GRID_SIZE, (h + 2) * GRID_SIZE);
  cairo_t *cr = cairo_create(surface);
  int x, y;

  cairo_surface_t *gridsurf = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, w * GRID_SIZE + 1, h * GRID_SIZE + 1);
  cairo_t *scr = cairo_create(gridsurf);

  cairo_set_line_width(scr, 1);
  cairo_set_source_rgba(scr, 0.5, 0.5, 0.5, 1);

  for (x = 0; x < w; x++)
    for (y = 0; y < h; y++) {
    gdk_cairo_set_source_pixbuf(cr, imageset->ground, x * GRID_SIZE, y * GRID_SIZE);
    cairo_paint(cr);
    cairo_rectangle(scr, x*GRID_SIZE+0.5, y*GRID_SIZE+0.5, GRID_SIZE, GRID_SIZE);
    cairo_stroke(scr);
  }
  cairo_set_source_surface(cr, gridsurf, GRID_SIZE, GRID_SIZE);
  cairo_paint(cr);
  cairo_destroy(scr);
  cairo_destroy(cr);
  cairo_surface_destroy(gridsurf);
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

  GdkPixbuf *pbuf = get_sprite_by_index(current_sprite->index);
  if (pbuf == NULL) return FALSE;
  gdk_cairo_set_source_pixbuf(cr, pbuf, width/2 - sprite_width/2 + offsetX + current_sprite->offsetX + imageset->offsetX, height/2 - sprite_height/2 + offsetY + current_sprite->offsetY + imageset->offsetY);
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

void free_imagesets() {
  imageset = imageset_info_new();
  imagesets = NULL;
  gtk_list_store_clear(GTK_LIST_STORE(gtk_combo_box_get_model(GTK_COMBO_BOX(imagesets_combo_box))));
}

void free_actions() {
  actions = NULL;
  gtk_list_store_clear(GTK_LIST_STORE(gtk_combo_box_get_model(GTK_COMBO_BOX(actions_combo_box))));
}

void free_animations() {
  animations = NULL;
  gtk_list_store_clear(GTK_LIST_STORE(gtk_combo_box_get_model(GTK_COMBO_BOX(animations_combo_box))));
  g_source_remove(running_animation);
  running_animation = 0;
  set_sprite_by_index(0);
}

void save_to_xml_file(GtkButton *button, gpointer buffer) {
  g_file_set_contents(gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(xml_file_chooser_button)), buffer, sizeof(buffer), NULL);
}

void data_folder_set_handler(GtkFileChooserButton *widget, gpointer data)  {
  gtk_file_chooser_set_current_folder(GTK_FILE_CHOOSER(xml_file_chooser_button), gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(widget)));
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
  size_t w = spriteset_width/sprite_width;
  if (imageset->spriteset == NULL) return NULL;
  return gdk_pixbuf_new_subpixbuf(imageset->spriteset, index%w*sprite_width, index/w*sprite_height, sprite_width, sprite_height);
}

void set_sprite_by_index(size_t index) {
  current_sprite->index = index;
  gtk_widget_queue_draw(darea);
}

void set_up_actions_by_imageset_name(gchar *imageset_name) {
  free_actions();
  free_animations();
  actions = NULL;
  GList *list = root->sub_nodes;
  XMLNode *node = NULL;
  while (TRUE) {
    list = g_list_find_custom(list, imageset_name, xml_node_compare_with_action_node_by_imageset_name_func);
    if (list == NULL)
      break;
    if (actions == NULL) {
      actions = g_list_alloc();
      actions->data = list->data;
    } else
      g_list_append(actions, list->data);
    node = list->data;
    gtk_combo_box_append_text(GTK_COMBO_BOX(actions_combo_box), xml_node_get_attr_value(node, "name"));
    list = list->next;
  }
}

gboolean set_up_imagesets(const XMLNode *root) {
  free_imagesets();
  free_actions();
  free_animations();
  GList *list = root->sub_nodes;
  XMLNode *node = NULL;
  while (TRUE) {
    list = g_list_find_custom(list, "imageset", xml_node_compare_with_name);
    if (list == NULL)
      break;
    if (imagesets == NULL) {
      imagesets = g_list_alloc();
      imagesets->data = list->data;
    } else
      g_list_append(imagesets, list->data);
    node = list->data;
    gtk_combo_box_append_text(GTK_COMBO_BOX(imagesets_combo_box), xml_node_get_attr_value(node, "name"));
    list = list->next;
  }
  if (imagesets == NULL)
    return FALSE;
  gtk_combo_box_set_active(GTK_COMBO_BOX(imagesets_combo_box), 0);
  return TRUE;
}

gboolean sequence_source_func(sequence *seq) {
  gchar *end_attr = xml_node_get_attr_value(seq->node, "end");
  size_t end;
  sscanf(end_attr, "%d", &end);
  if (current_sprite->index == end) {
    running_animation = g_timeout_add(seq->delay, show_animation_by_sub_nodes, seq->next);
    return FALSE;
  }
  set_sprite_by_index(current_sprite->index+1);
  return TRUE;
}

gboolean show_animation_by_sub_nodes(GList *sub_nodes) {
  XMLNode *node = sub_nodes->data;
  if (node == NULL)
    return FALSE;

  GList *next = sub_nodes->next;
  if (next == NULL)
    next = g_list_first(sub_nodes);

  int ofX = 0, ofY = 0;
  gchar *ofX_param, *ofY_param;
  ofX_param = xml_node_get_attr_value(node, "offsetX");
  if (ofX_param != NULL)
    sscanf(ofX_param, "%d", &ofX);
  ofY_param = xml_node_get_attr_value(node, "offsetY");
  if (ofY_param != NULL)
    sscanf(ofY_param, "%d", &ofY);
  current_sprite->offsetX = ofX;
  current_sprite->offsetY = ofY;

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
    g_source_remove(running_animation);
    running_animation = g_timeout_add(delay, show_animation_by_sub_nodes, next);
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
    size_t start;
    sscanf(start_attr, "%d", &start);
    size_t end;
    sscanf(end_attr, "%d", &end);
    size_t delay;
    sscanf(delay_attr, "%d", &delay);
    set_sprite_by_index(start);
    sequence *seq = g_new0(sequence, 1);
    seq->delay = delay;
    seq->next = next;
    seq->node = node;
    g_source_remove(running_animation);
    running_animation = g_timeout_add(delay, sequence_source_func, seq);
  }
  return FALSE;
}

gboolean show_general_animation() {
  XMLNode *node = animations->data;
  if (node == NULL)
    return FALSE;
  return show_animation_by_sub_nodes(node->sub_nodes);
}

gboolean set_up_action_by_name(const gchar *name) {
  free_animations();
  GList *list = g_list_find_custom(actions, name, xml_node_compare_with_name_attr);
  if (list == NULL) return FALSE;
  list = ((XMLNode *)list->data)->sub_nodes;
  gboolean was_direction = FALSE;
  while (TRUE) {
    list = g_list_find_custom(list, "animation", xml_node_compare_with_name);
    if (list == NULL)
      break;
    if (animations == NULL) {
      animations = g_list_alloc();
      animations->data = list->data;
    } else
      g_list_append(animations, list->data);
    XMLNode *node = list->data;
    gchar *direction = xml_node_get_attr_value(node, "direction");
    if (direction != NULL) {
      gtk_combo_box_append_text(GTK_COMBO_BOX(animations_combo_box), direction);
      was_direction = TRUE;
    }
    list = list->next;
  }
  if (animations == NULL)
    return FALSE;
  if (!was_direction)
    show_general_animation();
  return TRUE;
}

void actions_combo_box_changed_handler(GtkComboBox *widget, gpointer user_data) {
  set_up_action_by_name(gtk_combo_box_get_active_text(widget));
}

void animations_combo_box_changed_handler(GtkComboBox *widget, gpointer user_data) {
  GList *list = g_list_find_custom(animations, gtk_combo_box_get_active_text(widget), xml_node_compare_with_direction_attr);
  if (list == NULL)
    return;
  XMLNode *node = list->data;
  show_animation_by_sub_nodes(node->sub_nodes);
}

void set_up_imageset_by_node(XMLNode *node) {
  free_actions();
  free_animations();

  imageset->node = node;
  imageset->offsetX = 0;
  imageset->offsetY = 0;

  gchar *offset_attr = xml_node_get_attr_value(imageset->node, "offsetX");
  if (offset_attr != NULL)
    sscanf(offset_attr, "%d", &imageset->offsetX);

  offset_attr = xml_node_get_attr_value(imageset->node, "offsetY");
  if (offset_attr != NULL)
    sscanf(offset_attr, "%d", &imageset->offsetY);

  gchar *imageset_name = xml_node_get_attr_value(imageset->node, "name");
  set_up_actions_by_imageset_name(imageset_name);
  if (actions == NULL)
    return;

  gchar *src = xml_node_get_attr_value(imageset->node, "src");
  format_src_string(src);
  gchar *datapath = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(data_folder_chooser_button));
  gchar path[255];
  g_sprintf(path, "%s/%s", datapath, src);

  imageset->spriteset = gdk_pixbuf_new_from_file(path, NULL);
  spriteset_width = gdk_pixbuf_get_width(imageset->spriteset);
  spriteset_height = gdk_pixbuf_get_height(imageset->spriteset);

  gchar *width = xml_node_get_attr_value(imageset->node, "width");
  sscanf(width, "%d", &sprite_width);
  gchar *height = xml_node_get_attr_value(imageset->node, "height");
  sscanf(height, "%d", &sprite_height);

  GList *list = g_list_find_custom(root->sub_nodes, "background", xml_node_compare_with_name);
  if (list != NULL) {
    gchar *image_attr = xml_node_get_attr_value((XMLNode *)list->data, "image");
    if (image_attr != NULL) {
      image_attr = g_strjoin(NULL, BACKGROUNDS_DIR, "/", image_attr, ".png", NULL);
      GdkPixbuf *pbuf = gdk_pixbuf_new_from_file(image_attr, NULL);
      if(pbuf != NULL)
        imageset->ground = pbuf;
    }
  }

  set_sprite_by_index(0);
}

void imagesets_combo_box_changed_handler(GtkComboBox *widget, gpointer user_data) {
  GList *list = g_list_find_custom(imagesets, gtk_combo_box_get_active_text(widget), xml_node_compare_with_name_attr);
  if (list == NULL)
    return;
  set_up_imageset_by_node(list->data);
}

void load_options() {
  paths->sprites = NULL;
  gchar *datapath = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(data_folder_chooser_button));
  gchar *path = g_strjoin(SLASH_SEPARATOR, datapath, "paths.xml", NULL);
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
  paths->sprites = g_strjoin(SLASH_SEPARATOR, datapath, paths->sprites, NULL);
}

void parse_xml_buffer(GtkWidget *button, GtkSourceBuffer *buffer) {
  load_options();

  GtkTextIter beg, end;
  gtk_text_buffer_get_start_iter(GTK_TEXT_BUFFER(buffer), &beg);
  gtk_text_buffer_get_end_iter(GTK_TEXT_BUFFER(buffer), &end);
  root = ibus_xml_parse_buffer(gtk_text_iter_get_text(&beg, &end));

  if (root == NULL) {
    show_wrong_source_buffer_dialog();
    return;
  }

  printf("%s", paths->sprites);
  GList *list = g_list_find_custom(root->sub_nodes, "include", xml_node_compare_with_name);
  while (list != NULL) {
    XMLNode *node = list->data;
    gchar *file_attr = xml_node_get_attr_value(node, "file");
    if (file_attr != NULL) {
      file_attr = g_strjoin(NULL, paths->sprites, file_attr, NULL);
      gchar *buf;
      if (g_file_get_contents(file_attr, &buf, NULL, NULL))
        g_list_concat(root->sub_nodes, ibus_xml_parse_buffer(buf)->sub_nodes);
    }
    if (list->next != NULL)
      list = g_list_find_custom(list->next, "include", xml_node_compare_with_name);
    else
      list = NULL;
  }

  offsetX = 0;
  offsetY = 0;
  gchar *name_attr = xml_node_get_attr_value(root, "name");
  gchar *action_attr = xml_node_get_attr_value(root, "action");
  if (name_attr != NULL && action_attr != NULL)
    if (g_strcmp0(name_attr, "player") == 0 &&
        g_strcmp0(action_attr, "stand") == 0)
          offsetY = -16;

  if (!set_up_imagesets(root)) {
    show_wrong_source_buffer_dialog();
    return;
  }
}

void show_about_dialog() {
  gchar *authors[] = {"Dan Sagunov <danilka.pro@gmail.com>",
                      "Reid Yaro <reidyaro@gmail.com>",
                      NULL};
  gtk_show_about_dialog(GTK_WINDOW(win),
                        "authors", authors,
                        "comments", _("Sprite Animation Editor could be used to edit animations from Evol and The Mana World projects"),
                        "copyright", "Copyleft Vasily_Makarov 2011",
                        "program-name", "Sprite Animation Editor",
                        "version", "0.1 prealpha",
                        "logo", icon,
                        NULL);
}

void set_up_interface() {
  GtkWidget *button = NULL;
  GtkWidget *hbox = NULL;
  GtkWidget *vbox = NULL;
  GtkWidget *vbbox = NULL;
  GtkWidget *text = NULL;
  GtkWidget *label = NULL;
  GtkWidget *menubar = NULL;
  GtkWidget *menuitem = NULL;
  GtkWidget *menu = NULL;
  GtkWidget *vpaned = NULL;
  GtkWidget *hscrollbar = NULL;
  GtkWidget *vscrollbar = NULL;

  GtkSourceLanguageManager *langman = gtk_source_language_manager_get_default();
  source_buffer = gtk_source_buffer_new_with_language(gtk_source_language_manager_get_language(langman, "xml"));

  win = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(win), "Sprite Animation Editor");
  gtk_window_set_position(GTK_WINDOW(win), GTK_WIN_POS_CENTER);
  gtk_window_set_icon(GTK_WINDOW(win), icon);
  gtk_widget_realize(win);
  g_signal_connect(win, "destroy", G_CALLBACK(save_config_and_quit), NULL);
  gtk_widget_set_size_request(win, MIN_WIDTH, MIN_HEIGHT);

  vbox = gtk_vbox_new(FALSE, 0);
  gtk_container_add(GTK_CONTAINER(win), vbox);

  menubar = gtk_menu_bar_new();
  gtk_box_pack_start(GTK_BOX(vbox), menubar, FALSE, TRUE, 0);

  menu = gtk_menu_new();
  menuitem = gtk_menu_item_new_with_label(_("Imageset preview"));
  g_signal_connect(G_OBJECT(menuitem), "activate", G_CALLBACK(show_imageset_window), NULL);
  gtk_menu_shell_append(GTK_MENU_SHELL(menu), menuitem);

  menuitem = gtk_menu_item_new_with_label(_("View"));
  gtk_menu_item_set_submenu(GTK_MENU_ITEM(menuitem), menu);
  gtk_menu_shell_append(GTK_MENU_SHELL(menubar), menuitem);

  menu = gtk_menu_new();
  menuitem = gtk_menu_item_new_with_label(_("About"));
  g_signal_connect(menuitem, "activate", show_about_dialog, NULL);
  gtk_menu_shell_append(GTK_MENU_SHELL(menu), menuitem);

  menuitem = gtk_menu_item_new_with_label(_("Help"));
  gtk_menu_item_set_submenu(GTK_MENU_ITEM(menuitem), menu);
  gtk_menu_shell_append(GTK_MENU_SHELL(menubar), menuitem);

  hbox = gtk_hbox_new(FALSE, 0);
  gtk_box_pack_start(GTK_BOX(vbox), hbox, TRUE, TRUE, 0);

  vbbox = gtk_vbutton_box_new();
  gtk_button_box_set_layout(GTK_BUTTON_BOX(vbbox), GTK_BUTTONBOX_START);
  gtk_button_box_set_child_size(GTK_BUTTON_BOX(vbbox), 180, 0);
  gtk_box_pack_start(GTK_BOX(hbox), vbbox, FALSE, TRUE, 0);

  label = gtk_label_new("");
  gtk_label_set_markup(GTK_LABEL(label), markup_bold(_("Clientdata folder")));
  gtk_box_pack_start(GTK_BOX(vbbox), label, TRUE, TRUE, 0);

  data_folder_chooser_button = gtk_file_chooser_button_new(_("Clientdata folder"), 0);
  gtk_box_pack_start(GTK_BOX(vbbox), data_folder_chooser_button, TRUE, TRUE, 0);
  gtk_file_chooser_set_action(GTK_FILE_CHOOSER(data_folder_chooser_button), GTK_FILE_CHOOSER_ACTION_SELECT_FOLDER);
  g_signal_connect(data_folder_chooser_button, "selection-changed", G_CALLBACK(data_folder_set_handler), NULL);

  label = gtk_label_new("");
  gtk_label_set_markup(GTK_LABEL(label), markup_bold(_("XML source file")));
  gtk_box_pack_start(GTK_BOX(vbbox), label, TRUE, TRUE, 0);

  xml_file_chooser_button = gtk_file_chooser_button_new(_("XML source file"), 0);
  gtk_box_pack_start(GTK_BOX(vbbox), xml_file_chooser_button, TRUE, TRUE, 0);
  g_signal_connect(xml_file_chooser_button, "file-set", G_CALLBACK(open_xml_file), source_buffer);

  xml_file_open_button = gtk_button_new_from_stock(GTK_STOCK_OPEN);
  gtk_widget_set_sensitive(xml_file_open_button, FALSE);
  gtk_box_pack_start(GTK_BOX(vbbox), xml_file_open_button, TRUE, TRUE, 0);
  g_signal_connect(xml_file_open_button, "clicked", G_CALLBACK(open_xml_file), source_buffer);

  xml_file_save_button = gtk_button_new_from_stock(GTK_STOCK_SAVE);
  gtk_widget_set_sensitive(xml_file_save_button, FALSE);
  gtk_box_pack_start(GTK_BOX(vbbox), xml_file_save_button, TRUE, TRUE, 0);
  g_signal_connect(xml_file_save_button, "clicked", G_CALLBACK(save_to_xml_file), source_buffer);

  button = gtk_button_new_with_label("Parse XML buffer");
  gtk_box_pack_start(GTK_BOX(vbbox), button, TRUE, TRUE, 0);
  g_signal_connect(button, "clicked", G_CALLBACK(parse_xml_buffer), source_buffer);

  label = gtk_label_new("");
  gtk_label_set_markup(GTK_LABEL(label), markup_bold(_("Imagesets")));
  gtk_box_pack_start(GTK_BOX(vbbox), label, TRUE, TRUE, 0);

  imagesets_combo_box = gtk_combo_box_new_text();
  g_signal_connect(imagesets_combo_box, "changed", G_CALLBACK(imagesets_combo_box_changed_handler), NULL);
  gtk_box_pack_start(GTK_BOX(vbbox), imagesets_combo_box, TRUE, TRUE, 0);

  label = gtk_label_new("");
  gtk_label_set_markup(GTK_LABEL(label), markup_bold(_("Actions")));
  gtk_box_pack_start(GTK_BOX(vbbox), label, TRUE, TRUE, 0);

  actions_combo_box = gtk_combo_box_new_text();
  g_signal_connect(actions_combo_box, "changed", G_CALLBACK(actions_combo_box_changed_handler), NULL);
  gtk_box_pack_start(GTK_BOX(vbbox), actions_combo_box, TRUE, TRUE, 0);

  label = gtk_label_new("");
  gtk_label_set_markup(GTK_LABEL(label), markup_bold(_("Directions")));
  gtk_box_pack_start(GTK_BOX(vbbox), label, TRUE, TRUE, 0);

  animations_combo_box = gtk_combo_box_new_text();
  g_signal_connect(animations_combo_box, "changed", G_CALLBACK(animations_combo_box_changed_handler), NULL);
  gtk_box_pack_start(GTK_BOX(vbbox), animations_combo_box, TRUE, TRUE, 0);

  vpaned = gtk_vpaned_new();
  gtk_box_pack_end(GTK_BOX(hbox), vpaned, TRUE, TRUE, 0);

  darea = gtk_drawing_area_new();
  gtk_paned_pack1(GTK_PANED(vpaned), darea, FALSE, FALSE);
  gtk_widget_set_size_request(darea, -1, 120);
  g_signal_connect(darea, "expose-event", G_CALLBACK(darea_expose_event), NULL);

  hbox = gtk_hbox_new(FALSE, 0);
  gtk_paned_pack2(GTK_PANED(vpaned), hbox, TRUE, FALSE);
  gtk_widget_set_size_request(hbox, -1, 50);

  vbox = gtk_vbox_new(FALSE, 0);
  gtk_box_pack_start(GTK_BOX(hbox), vbox, TRUE, TRUE, 0);

  text = gtk_source_view_new_with_buffer(source_buffer);
  gtk_source_view_set_show_line_numbers(GTK_SOURCE_VIEW(text), TRUE);
  gtk_box_pack_start(GTK_BOX(vbox), text, TRUE, TRUE, 0);

  hscrollbar = gtk_hscrollbar_new(gtk_text_view_get_hadjustment(text));
  gtk_box_pack_start(GTK_BOX(vbox), hscrollbar, FALSE, TRUE, 0);

  vscrollbar = gtk_vscrollbar_new(gtk_text_view_get_vadjustment(text));
  gtk_box_pack_start(GTK_BOX(hbox), vscrollbar, FALSE, TRUE, 0);

  gtk_widget_show_all(win);
  gtk_widget_show_all(text);
}

gboolean frame_image_button_press_event(GtkWidget *widget, GdkEventButton *button, int index) {
  gchar buf[10];
  gint len = g_sprintf(buf, "%d", index);
  gtk_text_buffer_insert_at_cursor(GTK_TEXT_BUFFER(source_buffer), buf, len);
  return FALSE;
}

void show_imageset_window() {
  if (imageset->spriteset == NULL) return;
  GtkWidget *iwin = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(iwin), "Imageset preview");
  gtk_window_set_position(GTK_WINDOW(iwin), GTK_WIN_POS_CENTER);
  gtk_widget_add_events(iwin, GDK_BUTTON_PRESS_MASK);
  gtk_widget_realize(win);
  int w = spriteset_width / sprite_width;
  int h = spriteset_height / sprite_height;

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
  if (g_key_file_load_from_file(key_file, g_strjoin(NULL, g_get_user_config_dir(), CONFIG_FILE, NULL), G_KEY_FILE_NONE, NULL) &&
      g_key_file_has_group(key_file, "General") &&
      g_key_file_has_key(key_file, "General", "ClientdataFolder", NULL)) {
      } else {
        g_key_file_set_value(key_file, "General", "ClientdataFolder", g_strjoin(NULL, g_get_user_data_dir(), FOLDER_POSTFIX, NULL));
      }
  gtk_file_chooser_select_filename(GTK_FILE_CHOOSER(data_folder_chooser_button), g_key_file_get_value(key_file, "General", "ClientdataFolder", NULL));
  g_key_file_free(key_file);
}

void save_config_and_quit() {
  GKeyFile *key_file = g_key_file_new();
  g_key_file_set_value(key_file, "General", "ClientdataFolder", g_strjoin(NULL, gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(data_folder_chooser_button)), FOLDER_POSTFIX, NULL));
  g_file_set_contents(g_strjoin(NULL, g_get_user_config_dir(), CONFIG_FILE, NULL), g_key_file_to_data(key_file, NULL, NULL), -1, NULL);
  g_key_file_free(key_file);
  gtk_main_quit();
}

int main(int argc, char *argv[]) {

  gtk_init(&argc, &argv);

  icon = gdk_pixbuf_new_from_file(ICON_FILE, NULL);

  paths = g_new0(options, 1);
  current_sprite = sprite_info_new(-1, 0, 0);
  imageset = imageset_info_new();

  set_up_interface();
  load_config();

  show_imageset_window();

  gtk_main();

  return 0;
}
