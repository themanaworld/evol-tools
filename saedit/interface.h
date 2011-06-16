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

GtkWidget *reload_menu_item = NULL;

void find_menu_item_activate_callback(GtkWidget *menuitem, gpointer user_data) {
  search_find_dialog_show(win, source_view);
}

void save_dialog_response_callback(GtkWidget *dialog, gint response_id, gpointer user_data) {
  if (response_id == GTK_RESPONSE_ACCEPT) {
    gchar *filename = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(dialog));
    if (filename != NULL) {
      save_to_xml_file(filename);
      gtk_file_chooser_set_filename(GTK_FILE_CHOOSER(xml_file_chooser_button), filename);
    }
  }
  gtk_widget_destroy(dialog);
}

void save_dialog_show() {
  GtkDialog *dialog = gtk_file_chooser_dialog_new(_("Save file as..."), win, GTK_FILE_CHOOSER_ACTION_SAVE, GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL, GTK_STOCK_SAVE, GTK_RESPONSE_ACCEPT, NULL);
  g_signal_connect(dialog, "response", G_CALLBACK(save_dialog_response_callback), NULL);
  gtk_dialog_run(dialog);
}

void save_menu_item_activate_callback(GtkWidget *menuitem, GtkWidget *fsdialog) {
  gchar *filename = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(xml_file_chooser_button));
  if (filename != NULL)
    save_to_xml_file(filename);
  else
    save_dialog_show();
}

void xml_file_save_button_callback(GtkWidget *button, gpointer user_data) {
  gchar *filename = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(xml_file_chooser_button));
  if (filename != NULL)
    save_to_xml_file(filename);
}

void file_new() {
  GtkTextIter start, end;
  gtk_text_buffer_get_bounds(source_buffer, &start, &end);
  gtk_text_buffer_delete(source_buffer, &start, &end);
  gchar *temp;
  if (g_file_get_contents(FILE_TEMPLATE, &temp, NULL, NULL))
    gtk_text_buffer_set_text(GTK_TEXT_BUFFER(source_buffer), temp, -1);
  gtk_file_chooser_set_filename(GTK_FILE_CHOOSER(xml_file_chooser_button), "");
  gtk_widget_set_sensitive(reload_menu_item, FALSE);
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
  GtkWidget *scrolled_window = NULL;
  GtkWidget *fcdialog = NULL;

  GtkSourceLanguageManager *langman = gtk_source_language_manager_get_default();

  source_buffer = gtk_source_buffer_new_with_language(gtk_source_language_manager_get_language(langman, "xml"));
  text = gtk_source_view_new_with_buffer(source_buffer);
  source_view = text;

  win = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(win), "Sprite Animation Editor");
  gtk_window_set_position(GTK_WINDOW(win), GTK_WIN_POS_CENTER);
  gtk_window_set_icon(GTK_WINDOW(win), icon);
  gtk_widget_realize(win);
  g_signal_connect(win, "destroy", G_CALLBACK(save_config_and_quit), NULL);
  gtk_widget_set_size_request(win, MIN_WIDTH, MIN_HEIGHT);
  GtkAccelGroup *ag = gtk_accel_group_new();
  gtk_window_add_accel_group(win, ag);

  fcdialog = gtk_file_chooser_dialog_new(_("Open file"), win, GTK_FILE_CHOOSER_ACTION_OPEN, GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL, GTK_STOCK_OPEN, GTK_RESPONSE_ACCEPT, NULL);

  vbox = gtk_vbox_new(FALSE, 0);
  gtk_container_add(GTK_CONTAINER(win), vbox);

  //Menubar setup
  menubar = gtk_menu_bar_new();
  gtk_box_pack_start(GTK_BOX(vbox), menubar, FALSE, TRUE, 0);

  //File menu
  menu = gtk_menu_new();
  gtk_menu_set_accel_group(menu, ag);

  menuitem = gtk_menu_item_new_with_label(_("New"));
  g_signal_connect(menuitem, "activate", G_CALLBACK(file_new), NULL);
  gtk_menu_shell_append(GTK_MENU_SHELL(menu), menuitem);

  gtk_menu_item_set_accel_path(GTK_MENU_ITEM(menuitem), "<MenuItems>/File/New");
  gtk_accel_map_change_entry("<MenuItems>/File/New", gdk_keyval_from_name("N"), GDK_CONTROL_MASK, TRUE);

  menuitem = gtk_menu_item_new_with_label(_("Open..."));
  g_signal_connect(menuitem, "activate", open_menu_item_activate, fcdialog);
  gtk_menu_shell_append(GTK_MENU_SHELL(menu), menuitem);

  gtk_menu_item_set_accel_path(GTK_MENU_ITEM(menuitem), "<MenuItems>/File/Open");
  gtk_accel_map_change_entry("<MenuItems>/File/Open", gdk_keyval_from_name("O"), GDK_CONTROL_MASK, TRUE);

  menuitem = gtk_menu_item_new_with_label(_("Reload"));
  gtk_widget_set_sensitive(menuitem, FALSE);
  g_signal_connect(menuitem, "activate", G_CALLBACK(open_xml_file), source_buffer);
  gtk_menu_shell_append(GTK_MENU_SHELL(menu), menuitem);

  gtk_menu_item_set_accel_path(GTK_MENU_ITEM(menuitem), "<MenuItems>/File/Reload");
  gtk_accel_map_change_entry("<MenuItems>/File/Reload", gdk_keyval_from_name("R"), GDK_CONTROL_MASK, TRUE);

  reload_menu_item = menuitem;

  gtk_menu_shell_append(GTK_MENU_SHELL(menu), gtk_separator_menu_item_new());

  menuitem = gtk_menu_item_new_with_label(_("Save"));
  g_signal_connect(menuitem, "activate", G_CALLBACK(save_menu_item_activate_callback), NULL);
  gtk_menu_shell_append(GTK_MENU_SHELL(menu), menuitem);

  gtk_menu_item_set_accel_path(GTK_MENU_ITEM(menuitem), "<MenuItems>/File/Save");
  gtk_accel_map_change_entry("<MenuItems>/File/Save", gdk_keyval_from_name("S"), GDK_CONTROL_MASK, TRUE);

  menuitem = gtk_menu_item_new_with_label(_("Save as..."));
  g_signal_connect(menuitem, "activate", G_CALLBACK(save_dialog_show), NULL);
  gtk_menu_shell_append(GTK_MENU_SHELL(menu), menuitem);

  gtk_menu_item_set_accel_path(GTK_MENU_ITEM(menuitem), "<MenuItems>/File/SaveAs");
  gtk_accel_map_change_entry("<MenuItems>/File/SaveAs", gdk_keyval_from_name("S"), GDK_CONTROL_MASK + GDK_SHIFT_MASK, TRUE);

  menuitem = gtk_menu_item_new_with_label(_("File"));
  gtk_menu_item_set_submenu(GTK_MENU_ITEM(menuitem), menu);
  gtk_menu_shell_append(GTK_MENU_SHELL(menubar), menuitem);

  //Search menu
  menu = gtk_menu_new();
  gtk_menu_set_accel_group(menu, ag);

  menuitem = gtk_menu_item_new_with_label(_("Find..."));
  g_signal_connect(menuitem, "activate", find_menu_item_activate_callback, NULL);
  gtk_menu_shell_append(GTK_MENU_SHELL(menu), menuitem);

  gtk_menu_item_set_accel_path(GTK_MENU_ITEM(menuitem), "<MenuItems>/Search/Find");
  gtk_accel_map_change_entry("<MenuItems>/Search/Find", gdk_keyval_from_name("F"), GDK_CONTROL_MASK, TRUE);

  menuitem = gtk_menu_item_new_with_label(_("Find next"));
  g_signal_connect(menuitem, "activate", search_find_next, NULL);
  gtk_menu_shell_append(GTK_MENU_SHELL(menu), menuitem);

  gtk_menu_item_set_accel_path(GTK_MENU_ITEM(menuitem), "<MenuItems>/Search/FindNext");
  gtk_accel_map_change_entry("<MenuItems>/Search/FindNext", gdk_keyval_from_name("F3"), 0, TRUE);

  menuitem = gtk_menu_item_new_with_label(_("Search"));
  gtk_menu_item_set_submenu(GTK_MENU_ITEM(menuitem), menu);
  gtk_menu_shell_append(GTK_MENU_SHELL(menubar), menuitem);

  //View menu
  menu = gtk_menu_new();
  gtk_menu_set_accel_group(menu, ag);

  menuitem = gtk_check_menu_item_new_with_label(_("Show grid"));
  gtk_menu_shell_append(GTK_MENU_SHELL(menu), menuitem);

  g_signal_connect(menuitem, "toggled", show_grid_menu_item_toggled, NULL);

  gtk_menu_item_set_accel_path(menuitem, "<MenuItems>/View/ShowGrid");
  gtk_accel_map_change_entry("<MenuItems>/View/ShowGrid", gdk_keyval_from_name("G"), GDK_CONTROL_MASK, TRUE);

  show_grid_menu_item = menuitem;

  menuitem = gtk_menu_item_new_with_label(_("Imageset preview"));
  gtk_widget_set_sensitive(menuitem, FALSE);
  g_signal_connect(G_OBJECT(menuitem), "activate", G_CALLBACK(show_imageset_dialog), NULL);
  gtk_menu_shell_append(GTK_MENU_SHELL(menu), menuitem);

  gtk_menu_item_set_accel_path(menuitem, "<MenuItems>/View/ImagesetPreview");
  gtk_accel_map_change_entry("<MenuItems>/View/ImagesetPreview", gdk_keyval_from_name("I"), GDK_CONTROL_MASK, TRUE);

  imageset_preview_menu_item = menuitem;

  menuitem = gtk_menu_item_new_with_label(_("View"));
  gtk_menu_item_set_submenu(GTK_MENU_ITEM(menuitem), menu);
  gtk_menu_shell_append(GTK_MENU_SHELL(menubar), menuitem);

  //Help menu
  menu = gtk_menu_new();
  menuitem = gtk_menu_item_new_with_label(_("About"));
  g_signal_connect(menuitem, "activate", show_about_dialog, NULL);
  gtk_menu_shell_append(GTK_MENU_SHELL(menu), menuitem);

  menuitem = gtk_menu_item_new_with_label(_("Help"));
  gtk_menu_item_set_submenu(GTK_MENU_ITEM(menuitem), menu);
  gtk_menu_shell_append(GTK_MENU_SHELL(menubar), menuitem);

  hbox = gtk_hbox_new(FALSE, 0);
  gtk_box_pack_start(GTK_BOX(vbox), hbox, TRUE, TRUE, 0);

  //Left part setup
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
  g_signal_connect(data_folder_chooser_button, "selection-changed", G_CALLBACK(data_folder_set_callback), NULL);

  label = gtk_label_new("");
  gtk_label_set_markup(GTK_LABEL(label), markup_bold(_("XML source file")));
  gtk_box_pack_start(GTK_BOX(vbbox), label, TRUE, TRUE, 0);

  xml_file_chooser_button = gtk_file_chooser_button_new_with_dialog(fcdialog);
  gtk_box_pack_start(GTK_BOX(vbbox), xml_file_chooser_button, TRUE, TRUE, 0);
  g_signal_connect(xml_file_chooser_button, "file-set", G_CALLBACK(open_xml_file), source_buffer);

  xml_file_open_button = gtk_button_new_from_stock(GTK_STOCK_OPEN);
  gtk_widget_set_sensitive(xml_file_open_button, FALSE);
  gtk_box_pack_start(GTK_BOX(vbbox), xml_file_open_button, TRUE, TRUE, 0);
  g_signal_connect(xml_file_open_button, "clicked", G_CALLBACK(open_xml_file), source_buffer);

  xml_file_save_button = gtk_button_new_from_stock(GTK_STOCK_SAVE);
  gtk_widget_set_sensitive(xml_file_save_button, FALSE);
  gtk_box_pack_start(GTK_BOX(vbbox), xml_file_save_button, TRUE, TRUE, 0);
  g_signal_connect(xml_file_save_button, "clicked", G_CALLBACK(xml_file_save_button_callback), NULL);
  gtk_widget_set_accel_path(xml_file_save_button, "<Buttons>/SaveXMLBuffer", ag);
  //gtk_accel_map_change_entry("<Buttons>/SaveXMLBuffer", gdk_keyval_from_name("S"), GDK_CONTROL_MASK, TRUE);

  button = gtk_button_new_with_label(_("Parse XML buffer"));
  gtk_box_pack_start(GTK_BOX(vbbox), button, TRUE, TRUE, 0);
  g_signal_connect(button, "clicked", G_CALLBACK(parse_xml_buffer), source_buffer);
  gtk_widget_set_accel_path(button, "<Buttons>/ParseXMLBuffer", ag);
  gtk_accel_map_change_entry("<Buttons>/ParseXMLBuffer", gdk_keyval_from_name("P"), GDK_CONTROL_MASK, TRUE);

  label = gtk_label_new("");
  gtk_label_set_markup(GTK_LABEL(label), markup_bold(_("Imagesets")));
  gtk_box_pack_start(GTK_BOX(vbbox), label, TRUE, TRUE, 0);

  gen_sae_info->imagesets_combo_box = gtk_combo_box_new_text();
  g_signal_connect(gen_sae_info->imagesets_combo_box, "changed", G_CALLBACK(imagesets_combo_box_changed_callback), NULL);
  gtk_box_pack_start(GTK_BOX(vbbox), gen_sae_info->imagesets_combo_box, TRUE, TRUE, 0);

  label = gtk_label_new("");
  gtk_label_set_markup(GTK_LABEL(label), markup_bold(_("Actions")));
  gtk_box_pack_start(GTK_BOX(vbbox), label, TRUE, TRUE, 0);

  gen_sae_info->actions_combo_box = gtk_combo_box_new_text();
  g_signal_connect(gen_sae_info->actions_combo_box, "changed", G_CALLBACK(actions_combo_box_changed_callback), NULL);
  gtk_box_pack_start(GTK_BOX(vbbox), gen_sae_info->actions_combo_box, TRUE, TRUE, 0);

  label = gtk_label_new("");
  gtk_label_set_markup(GTK_LABEL(label), markup_bold(_("Directions")));
  gtk_box_pack_start(GTK_BOX(vbbox), label, TRUE, TRUE, 0);

  gen_sae_info->animations_combo_box = gtk_combo_box_new_text();
  g_signal_connect(gen_sae_info->animations_combo_box, "changed", G_CALLBACK(animations_combo_box_changed_callback), NULL);
  gtk_box_pack_start(GTK_BOX(vbbox), gen_sae_info->animations_combo_box, TRUE, TRUE, 0);

  //Right part setup
  vpaned = gtk_vpaned_new();
  gtk_box_pack_end(GTK_BOX(hbox), vpaned, TRUE, TRUE, 0);

  darea = gtk_drawing_area_new();
  gtk_paned_pack1(GTK_PANED(vpaned), darea, FALSE, FALSE);
  gtk_widget_set_size_request(darea, -1, 120);
  g_signal_connect(darea, "expose-event", G_CALLBACK(darea_expose_event), gen_sae_info);

  source_view = text;
  gtk_source_view_set_show_line_numbers(GTK_SOURCE_VIEW(text), TRUE);

  scrolled_window = gtk_scrolled_window_new(gtk_text_view_get_hadjustment(text), gtk_text_view_get_vadjustment(text));
  gtk_paned_pack2(GTK_PANED(vpaned), scrolled_window, TRUE, FALSE);
  gtk_widget_set_size_request(scrolled_window, -1, 50);

  file_new();

  gtk_container_add(scrolled_window, text);

  gtk_widget_show_all(win);
  gtk_widget_show_all(text);
}
