#include <gtksourceview/gtksource.h>
#include "main.h"
#include "buffer.h"

gchar *
buffer_get_text () {
	GtkTextIter start, end;
	GtkTextBuffer *buffer =
		GTK_TEXT_BUFFER (gtk_text_view_get_buffer (
			GTK_TEXT_VIEW (source_view)
		));

	gtk_text_buffer_get_start_iter (buffer, &start);
	gtk_text_buffer_get_end_iter (buffer, &end);

	return gtk_text_buffer_get_text (buffer, &start, &end, TRUE);
}

void
buffer_set_text (
	const gchar *text,
	const guint len
) {
	GtkTextBuffer *buffer =
		GTK_TEXT_BUFFER (gtk_text_view_get_buffer (
			GTK_TEXT_VIEW (source_view)
		));

	gtk_text_buffer_set_text (buffer, text, len);
}

void
buffer_mark_line (gint line_no) {
	GtkTextIter iter, end;
	GtkSourceBuffer *buffer = GTK_SOURCE_BUFFER (
		gtk_text_view_get_buffer (GTK_TEXT_VIEW (source_view))
	);

	gtk_text_buffer_get_start_iter (GTK_TEXT_BUFFER (buffer), &iter);
	gtk_text_buffer_get_end_iter   (GTK_TEXT_BUFFER (buffer),  &end);

	gtk_source_buffer_remove_source_marks (
		buffer,
		&iter,
		&end,
		"active-line"
	);

	if (line_no == -1)
		return;

	gtk_text_iter_set_line (&iter, line_no);
	gtk_text_view_scroll_to_mark (
		GTK_TEXT_VIEW (source_view),
		(GtkTextMark *) gtk_source_buffer_create_source_mark (
			buffer,
			NULL, 
			"active-line", 
			&iter
		),
		0.0,
		TRUE,
		0.0,
		0.5
	);
}


void
buffer_set_modified (gboolean modified) {
	GtkTextBuffer *buffer =
		GTK_TEXT_BUFFER (gtk_text_view_get_buffer (
			GTK_TEXT_VIEW (source_view)
		));

	gtk_text_buffer_set_modified (buffer, modified);
}

gboolean
buffer_get_modified () {
	GtkTextBuffer *buffer =
		GTK_TEXT_BUFFER (gtk_text_view_get_buffer (
			GTK_TEXT_VIEW (source_view)
		));

	return gtk_text_buffer_get_modified (buffer);
}
