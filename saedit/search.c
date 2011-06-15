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

#include <gtk/gtk.h>
#include "common.h"
#include "search.h"

GtkWidget *search_text_view = NULL;
GtkWidget *search_find_dialog_entry = NULL;
gchar *search_last_text = NULL;

gboolean search_find_text(gchar *text) {
  search_last_text = text;

  GtkTextBuffer *text_buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(search_text_view));
  if (!GTK_IS_TEXT_BUFFER(text_buffer))
    return FALSE;

  gboolean found;

  GtkTextIter m_start, m_end, start;
  gtk_text_buffer_get_selection_bounds(text_buffer, NULL, &start);
  found = gtk_source_iter_forward_search(&start, text, 0, &m_start, &m_end, NULL);

  if (!found) {
    gtk_text_buffer_get_start_iter(text_buffer, &start);
    found = gtk_source_iter_forward_search(&start, text, 0, &m_start, &m_end, NULL);
  }

  if (found) {
    gtk_text_buffer_place_cursor(text_buffer, &m_start);
    gtk_text_buffer_move_mark_by_name(text_buffer, "selection_bound", &m_end);
    gtk_text_view_scroll_to_mark (GTK_TEXT_VIEW(search_text_view),
                                  gtk_text_buffer_get_insert(text_buffer),
                                  0.25,
                                  FALSE,
                                  0.0,
                                  0.0);
    return TRUE;
  } else
    return FALSE;
}

gboolean search_find_next() {
  if (search_last_text != NULL)
    search_find_text(search_last_text);
}

void search_find_dialog_response_callback(GtkDialog *dialog,
                   gint response_id,
                   gpointer user_data) {
  if (response_id != GTK_RESPONSE_ACCEPT)
    return;

  if (!GTK_IS_TEXT_VIEW(search_text_view))
    return;

  if (GTK_IS_ENTRY(search_find_dialog_entry))
    search_find_text(g_strdup(gtk_entry_get_text(GTK_ENTRY(search_find_dialog_entry))));
}

void search_find_dialog_show(GtkWindow *parent,
                             GtkWidget *text_view) {
  GtkWidget *dialog;
  GtkWidget *vbox;
  GtkWidget *entry;
  GtkWidget *content_area;
  GtkWidget *label;

  dialog = gtk_dialog_new_with_buttons(_("Find"),
                                       parent,
                                       GTK_DIALOG_DESTROY_WITH_PARENT,
                                       GTK_STOCK_FIND,
                                       GTK_RESPONSE_ACCEPT,
                                       NULL);
  gtk_widget_set_size_request(dialog, 240, 80);
  gtk_window_set_resizable(GTK_WINDOW(dialog), FALSE);
  content_area = gtk_dialog_get_content_area(GTK_DIALOG(dialog));

  entry = gtk_entry_new();
  gtk_container_add(GTK_CONTAINER(content_area), entry);

  g_signal_connect(dialog,
                   "response",
                   G_CALLBACK(search_find_dialog_response_callback),
                   NULL);

  search_text_view = text_view;
  search_find_dialog_entry = entry;

  gtk_widget_show_all(dialog);
}
