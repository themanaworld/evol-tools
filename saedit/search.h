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

static gboolean find_text() {
  gboolean found;
  gchar *text = gtk_entry_get_text(find_entry);

  GtkTextIter m_start, m_end, start;
  gtk_text_buffer_get_selection_bounds(source_buffer, NULL, &start);
  found = gtk_source_iter_forward_search(&start, text, 0, &m_start, &m_end, NULL);

  if (!found) {
    gtk_text_buffer_get_start_iter(source_buffer, &start);
    found = gtk_source_iter_forward_search(&start, text, 0, &m_start, &m_end, NULL);
  }
  if (found) {
    gtk_text_buffer_place_cursor(source_buffer, &m_start);
    gtk_text_buffer_move_mark_by_name(source_buffer, "selection_bound", &m_end);
    gtk_text_view_scroll_to_mark (GTK_TEXT_VIEW (source_view),
                                  gtk_text_buffer_get_insert (source_buffer),
                                  0.25,
                                  FALSE,
                                  0.0,
                                  0.0);
    return TRUE;
  } else
    return FALSE;
}

static GtkWidget *show_find_dialog() {
  GtkWidget *dialog;
  GtkWidget *vbox;
  GtkWidget *entry;
  GtkWidget *content_area;
  GtkWidget *label;

  dialog = gtk_dialog_new_with_buttons (_("Find"),
                                         win,
                                         GTK_DIALOG_DESTROY_WITH_PARENT,
                                         GTK_STOCK_FIND,
                                         GTK_RESPONSE_NONE,
                                         NULL);
  content_area = gtk_dialog_get_content_area(GTK_DIALOG(dialog));

  label = gtk_label_new(_("Text:"));
  gtk_container_add(GTK_CONTAINER(content_area), label);

  entry = gtk_entry_new();
  gtk_container_add(GTK_CONTAINER(content_area), entry);
  find_entry = entry;

  g_signal_connect(dialog,
                   "response",
                   G_CALLBACK(find_text),
                   NULL);
  gtk_widget_show_all(dialog);
}
