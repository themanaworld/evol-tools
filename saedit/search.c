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

#include "search.h"

GtkWidget *search_text_view = NULL;
gchar *search_last_text = NULL;

gboolean search_find_text(gchar *text) {
	search_last_text = text;

	GtkTextBuffer *text_buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(search_text_view));
	if (!GTK_IS_TEXT_BUFFER(text_buffer))
		return FALSE;

	gboolean found;

	GtkTextIter m_start, m_end, start;
	gtk_text_buffer_get_selection_bounds(text_buffer, NULL, &start);
	found = gtk_text_iter_forward_search(&start, text, 4, &m_start, &m_end, NULL);

	if (!found) {
		gtk_text_buffer_get_start_iter(text_buffer, &start);
		found = gtk_text_iter_forward_search(&start, text, 4, &m_start, &m_end, NULL);
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
	// here must return some thing
}

void search_find_dialog_response_callback(GtkWidget *dialog,
        gint response_id,
        gpointer entry) {

	if (response_id == GTK_RESPONSE_CANCEL || response_id == GTK_RESPONSE_DELETE_EVENT)
		gtk_widget_hide(dialog);
	else {

		g_return_if_fail(response_id == GTK_RESPONSE_ACCEPT);
		g_return_if_fail(GTK_IS_TEXT_VIEW(search_text_view));
		g_return_if_fail(GTK_IS_ENTRY(GTK_ENTRY(entry)));

		search_find_text(g_strdup(gtk_entry_get_text(GTK_ENTRY(entry))));

	}
}

void search_init(GtkWidget *text_view) {
	search_text_view = text_view;
}
