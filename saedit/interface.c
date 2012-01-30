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
GtkWidget *find_dialog = NULL;

void find_menu_item_activate_callback(GtkWidget *menuitem, gpointer user_data) {
  gtk_dialog_run(GTK_DIALOG(find_dialog));
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
  GtkDialog *dialog = GTK_DIALOG(gtk_file_chooser_dialog_new(_("Save file as..."), GTK_WINDOW(win), GTK_FILE_CHOOSER_ACTION_SAVE, GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL, GTK_STOCK_SAVE, GTK_RESPONSE_ACCEPT, NULL));
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
  gtk_text_buffer_get_bounds(GTK_TEXT_BUFFER(source_buffer), &start, &end);
  gtk_text_buffer_delete(GTK_TEXT_BUFFER(source_buffer), &start, &end);
  gchar *temp;
  if (g_file_get_contents(FILE_TEMPLATE, &temp, NULL, NULL))
    gtk_text_buffer_set_text(GTK_TEXT_BUFFER(source_buffer), temp, -1);
  gtk_file_chooser_set_filename(GTK_FILE_CHOOSER(xml_file_chooser_button), "");
  gtk_widget_set_sensitive(reload_menu_item, FALSE);
  
  free_current_info();
}

void set_up_interface() {

  GtkBuilder *builder = gtk_builder_new();
  gtk_builder_add_from_file(builder, "interface.ui", NULL);
  gtk_builder_connect_signals(builder, NULL);

  //Setup main window
  win = GTK_WIDGET(gtk_builder_get_object(builder, "win_main"));

  //Setup GtkSourceView
  GtkSourceLanguageManager *langman = gtk_source_language_manager_get_default();
  source_buffer = gtk_source_buffer_new_with_language(gtk_source_language_manager_get_language(langman, "xml"));

  source_view = GTK_WIDGET(gtk_builder_get_object(builder, "source_view"));
  gtk_text_view_set_buffer(GTK_TEXT_VIEW(source_view), GTK_TEXT_BUFFER(source_buffer));
  search_init(source_view);

  //Setup GtkScrolledWindow
  GtkWidget *scrolled_window = NULL;
  scrolled_window = GTK_WIDGET(gtk_builder_get_object(builder, "scrolledwindow1"));
  gtk_scrolled_window_set_hadjustment(GTK_SCROLLED_WINDOW(scrolled_window), 
				      gtk_text_view_get_hadjustment(GTK_TEXT_VIEW(source_view)));
  gtk_scrolled_window_set_vadjustment(GTK_SCROLLED_WINDOW(scrolled_window), 
				      gtk_text_view_get_vadjustment(GTK_TEXT_VIEW(source_view)));

  //Setup GtkDrawingArea
  darea = GTK_WIDGET(gtk_builder_get_object(builder, "darea1"));

  reload_menu_item = GTK_WIDGET(gtk_builder_get_object(builder, "menuitem6"));
  show_grid_menu_item = GTK_WIDGET(gtk_builder_get_object(builder, "menuitem11"));
  imageset_preview_menu_item = GTK_WIDGET(gtk_builder_get_object(builder, "menuitem12"));

  data_folder_chooser_button = GTK_WIDGET(gtk_builder_get_object(builder, "datafcbutton"));
  xml_file_chooser_button = GTK_WIDGET(gtk_builder_get_object(builder, "xmlfcbutton"));
  xml_file_open_button = GTK_WIDGET(gtk_builder_get_object(builder, "xmlfobutton"));
  xml_file_save_button = GTK_WIDGET(gtk_builder_get_object(builder, "xmlfsbutton"));

  gen_sae_info->imagesets_combo_box = GTK_WIDGET(gtk_builder_get_object(builder, "imagesetscbox"));
  gen_sae_info->actions_combo_box = GTK_WIDGET(gtk_builder_get_object(builder, "actionscbox"));
  gen_sae_info->animations_combo_box = GTK_WIDGET(gtk_builder_get_object(builder, "animationscbox"));

  //Setup GtkAboutDialog
  about_dialog = GTK_WIDGET(gtk_builder_get_object(builder, "about_dialog"));

  //Setup Find dialog
  find_dialog = GTK_WIDGET(gtk_builder_get_object(builder, "find_dialog"));
  gtk_widget_hide(find_dialog);

  file_new();

  gtk_widget_show_all(win);
  gtk_widget_show_all(source_view);

  g_object_unref(builder);
}
