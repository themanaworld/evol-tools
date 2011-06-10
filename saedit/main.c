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

gboolean on_expose_event(GtkWidget *widget, GdkEventExpose *event, gpointer data) {
  int width = widget->allocation.width,
      height = widget->allocation.height;

  cairo_t *cr = gdk_cairo_create(widget->window);
  cairo_surface_t *gridsurf = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, width, height);
  cairo_t *scr = cairo_create(gridsurf);
  cairo_set_line_width(scr, 0.1);
  cairo_rectangle(scr, width/2 -GRID_SIZE/2, height/2, GRID_SIZE, GRID_SIZE);
  cairo_stroke(scr);
  cairo_set_source_surface(cr, gridsurf, 0, 0);
  cairo_paint(cr);

  GdkPixbuf *pbuf = get_sprite_by_index(current_sprite->index);
  if (pbuf == NULL) return FALSE;
  gdk_cairo_set_source_pixbuf(cr, pbuf, width/2 - sprite_width/2 + current_sprite->offsetX + imageset->offsetX, height/2 - sprite_height/2 + current_sprite->offsetY + imageset->offsetY);
  cairo_paint(cr);

  cairo_destroy(cr);
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
  gchar *buf;
  size_t len;
  g_file_get_contents(gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(xmlfcbutton)), &buf, &len, NULL);
  gtk_text_buffer_set_text((GtkTextBuffer *)buffer, buf, len);
  gtk_widget_set_sensitive(xmlfsbutton, TRUE);
}

void free_imagesets() {
  spriteset = NULL;
  imageset = imageset_info_new();
  imagesets = NULL;
  gtk_list_store_clear(GTK_LIST_STORE(gtk_combo_box_get_model(GTK_COMBO_BOX(imagesetscombobox))));
}

void free_actions() {
  actions = NULL;
  gtk_list_store_clear(GTK_LIST_STORE(gtk_combo_box_get_model(GTK_COMBO_BOX(actionscombobox))));
}

void free_animations() {
  animations = NULL;
  gtk_list_store_clear(GTK_LIST_STORE(gtk_combo_box_get_model(GTK_COMBO_BOX(animationscombobox))));
  g_source_remove(running_animation);
  running_animation = 0;
  set_sprite_by_index(0);
}

void save_to_xml_file(GtkButton *button, gpointer buffer) {
  g_file_set_contents(gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(xmlfcbutton)), buffer, sizeof(buffer), NULL);
}

void xml_file_set_handler(GtkFileChooserButton *widget, gpointer data)  {
  gtk_widget_set_sensitive(xmlfobutton, TRUE);
}

void data_folder_set_handler(GtkFileChooserButton *widget, gpointer data)  {
  gtk_file_chooser_set_current_folder(GTK_FILE_CHOOSER(xmlfcbutton), gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(widget)));
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
  if (spriteset == NULL) return NULL;
  return gdk_pixbuf_new_subpixbuf(spriteset, index%w*sprite_width, index/w*sprite_height, sprite_width, sprite_height);
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
    gtk_combo_box_append_text(GTK_COMBO_BOX(actionscombobox), xml_node_get_attr_value(node, "name"));
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
    gtk_combo_box_append_text(GTK_COMBO_BOX(imagesetscombobox), xml_node_get_attr_value(node, "name"));
    list = list->next;
  }
  if (imagesets == NULL)
    return FALSE;
  gtk_combo_box_set_active(GTK_COMBO_BOX(imagesetscombobox), 0);
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
      gtk_combo_box_append_text(GTK_COMBO_BOX(animationscombobox), direction);
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
  gchar *datapath = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(datafoldcbutton));
  gchar path[255];
  g_sprintf(path, "%s/%s", datapath, src);

  spriteset = gdk_pixbuf_new_from_file(path, NULL);
  spriteset_width = gdk_pixbuf_get_width(spriteset);
  spriteset_height = gdk_pixbuf_get_height(spriteset);

  gchar *width = xml_node_get_attr_value(imageset->node, "width");
  sscanf(width, "%d", &sprite_width);
  gchar *height = xml_node_get_attr_value(imageset->node, "height");
  sscanf(height, "%d", &sprite_height);

  set_sprite_by_index(0);
}

void imagesets_combo_box_changed_handler(GtkComboBox *widget, gpointer user_data) {
  GList *list = g_list_find_custom(imagesets, gtk_combo_box_get_active_text(widget), xml_node_compare_with_name_attr);
  if (list == NULL)
    return;
  set_up_imageset_by_node(list->data);
}

void parse_xml_buffer(GtkWidget *button, GtkSourceBuffer *buffer) {
  GtkTextIter beg, end;
  gtk_text_buffer_get_start_iter(GTK_TEXT_BUFFER(buffer), &beg);
  gtk_text_buffer_get_end_iter(GTK_TEXT_BUFFER(buffer), &end);
  root = ibus_xml_parse_buffer(gtk_text_iter_get_text(&beg, &end));
  if (root == NULL) {
    show_wrong_source_buffer_dialog();
    return;
  }
  if (!set_up_imagesets(root)) {
    show_wrong_source_buffer_dialog();
    return;
  }
  set_up_imageset_by_node(imagesets->data);
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

  GtkSourceLanguageManager *langman = gtk_source_language_manager_get_default();
  sbuf = gtk_source_buffer_new_with_language(gtk_source_language_manager_get_language(langman, "xml"));

  win = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(win), "Sprite Animation Editor");
  gtk_window_set_position (GTK_WINDOW(win), GTK_WIN_POS_CENTER);
  gtk_widget_realize(win);
  g_signal_connect(win, "destroy", gtk_main_quit, NULL);
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

  datafoldcbutton = gtk_file_chooser_button_new(_("Clientdata folder"), 0);
  gtk_box_pack_start(GTK_BOX(vbbox), datafoldcbutton, TRUE, TRUE, 0);
  gtk_file_chooser_set_action(GTK_FILE_CHOOSER(datafoldcbutton), GTK_FILE_CHOOSER_ACTION_SELECT_FOLDER);
  g_signal_connect(datafoldcbutton, "file-set", G_CALLBACK(data_folder_set_handler), NULL);

  label = gtk_label_new("");
  gtk_label_set_markup(GTK_LABEL(label), markup_bold(_("XML source file")));
  gtk_box_pack_start(GTK_BOX(vbbox), label, TRUE, TRUE, 0);

  xmlfcbutton = gtk_file_chooser_button_new(_("XML source file"), 0);
  gtk_box_pack_start(GTK_BOX(vbbox), xmlfcbutton, TRUE, TRUE, 0);

  xmlfobutton = gtk_button_new_from_stock(GTK_STOCK_OPEN);
  gtk_widget_set_sensitive(xmlfobutton, FALSE);
  gtk_box_pack_start(GTK_BOX(vbbox), xmlfobutton, TRUE, TRUE, 0);
  g_signal_connect(xmlfobutton, "clicked", G_CALLBACK(open_xml_file), sbuf);

  xmlfsbutton = gtk_button_new_from_stock(GTK_STOCK_SAVE);
  gtk_widget_set_sensitive(xmlfsbutton, FALSE);
  gtk_box_pack_start(GTK_BOX(vbbox), xmlfsbutton, TRUE, TRUE, 0);
  g_signal_connect(xmlfsbutton, "clicked", G_CALLBACK(save_to_xml_file), sbuf);

  g_signal_connect(xmlfcbutton, "file-set", G_CALLBACK(xml_file_set_handler), NULL);

  button = gtk_button_new_with_label("Parse XML buffer");
  gtk_box_pack_start(GTK_BOX(vbbox), button, TRUE, TRUE, 0);
  g_signal_connect(button, "clicked", G_CALLBACK(parse_xml_buffer), sbuf);

  label = gtk_label_new("");
  gtk_label_set_markup(GTK_LABEL(label), markup_bold(_("Imagesets")));
  gtk_box_pack_start(GTK_BOX(vbbox), label, TRUE, TRUE, 0);

  imagesetscombobox = gtk_combo_box_new_text();
  g_signal_connect(imagesetscombobox, "changed", G_CALLBACK(imagesets_combo_box_changed_handler), NULL);
  gtk_box_pack_start(GTK_BOX(vbbox), imagesetscombobox, TRUE, TRUE, 0);

  label = gtk_label_new("");
  gtk_label_set_markup(GTK_LABEL(label), markup_bold(_("Actions")));
  gtk_box_pack_start(GTK_BOX(vbbox), label, TRUE, TRUE, 0);

  actionscombobox = gtk_combo_box_new_text();
  g_signal_connect(actionscombobox, "changed", G_CALLBACK(actions_combo_box_changed_handler), NULL);
  gtk_box_pack_start(GTK_BOX(vbbox), actionscombobox, TRUE, TRUE, 0);

  label = gtk_label_new("");
  gtk_label_set_markup(GTK_LABEL(label), markup_bold(_("Directions")));
  gtk_box_pack_start(GTK_BOX(vbbox), label, TRUE, TRUE, 0);

  animationscombobox = gtk_combo_box_new_text();
  g_signal_connect(animationscombobox, "changed", G_CALLBACK(animations_combo_box_changed_handler), NULL);
  gtk_box_pack_start(GTK_BOX(vbbox), animationscombobox, TRUE, TRUE, 0);

  vbox = gtk_vpaned_new();
  gtk_box_pack_end(GTK_BOX(hbox), vbox, TRUE, TRUE, 0);

  darea = gtk_drawing_area_new();
  gtk_paned_pack1(GTK_PANED(vbox), darea, FALSE, FALSE);
  gtk_widget_set_size_request(darea, -1, 120);
  g_signal_connect(darea, "expose-event", G_CALLBACK(on_expose_event), NULL);

  text = gtk_source_view_new_with_buffer(sbuf);
  gtk_source_view_set_show_line_numbers(GTK_SOURCE_VIEW(text), TRUE);
  gtk_paned_pack2(GTK_PANED(vbox), text, TRUE, FALSE);
  gtk_widget_set_size_request(text, -1, 50);

  gtk_widget_show_all(win);
  gtk_widget_show_all(text);
}

gboolean frame_image_button_press_event(GtkWidget *widget, GdkEventButton *button, int index) {
  gchar buf[10];
  gint len = g_sprintf(buf, "%d", index);
  gtk_text_buffer_insert_at_cursor(GTK_TEXT_BUFFER(sbuf), buf, len);
  return FALSE;
}

void show_imageset_window() {
  if (spriteset == NULL) return;
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

int main (int argc, char *argv[]) {

  gtk_init(&argc, &argv);

  current_sprite = sprite_info_new(-1, 0, 0);
  imageset = imageset_info_new();

  set_up_interface();

  show_imageset_window();

  gtk_main();

  return 0;
}
