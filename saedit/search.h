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

GtkWidget *find_entry;

static gboolean find_text(GtkWidget *button, gpointer user_data) {
  GtkTextIter beg, end, start;
  gtk_text_buffer_get_start_iter(source_buffer, &start);
  if (!gtk_source_iter_forward_search(&start, gtk_entry_get_text(find_entry), 0, &beg, &end, NULL))
    return FALSE;
  gtk_text_buffer_place_cursor(source_buffer, &beg);
  gtk_text_view_set_cursor_visible(source_view, FALSE);
  gtk_text_buffer_move_mark_by_name(source_buffer, "selection_bound", &end);
  gtk_text_mark_set_visible(gtk_text_buffer_get_insert (source_buffer), TRUE);
	gtk_text_view_scroll_to_mark (GTK_TEXT_VIEW (source_view),
	                              gtk_text_buffer_get_insert (source_buffer),
	                              0.25,
	                              FALSE,
	                              0.0,
	                              0.0);
  gtk_text_buffer_place_cursor(source_buffer, &end);
}

static GtkWidget *find_window_new(GtkWindow *parent) {
  GtkWidget *window;
  GtkWidget *vbox;
  GtkWidget *entry;
  GtkWidget *button;

  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_transient_for(window, parent);
  gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
  gtk_window_set_title(GTK_WINDOW(window), _("Find"));
  gtk_widget_set_size_request(window, 250, 100);
  gtk_container_set_border_width(window, 4);
  gtk_window_set_resizable(GTK_WINDOW(window), FALSE);
  gtk_widget_realize(window);

  vbox = gtk_vbox_new(FALSE, 4);
  gtk_container_add(window, vbox);

  entry = gtk_entry_new();
  gtk_box_pack_start(GTK_BOX(vbox), entry, FALSE, FALSE, 0);
  find_entry = entry;

  button = gtk_button_new_with_label(_("Find"));
  gtk_widget_set_size_request(button, 64, 32);
  gtk_box_pack_start(GTK_BOX(vbox), button, FALSE, FALSE, 0);
  g_signal_connect(button, "clicked", find_text, NULL);

  gtk_widget_show_all(window);
}
