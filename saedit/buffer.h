#ifndef _BUFFER_H_
#define _BUFFER_H_

gchar *
buffer_get_text (void);

void
buffer_set_text (
	const gchar *text,
	const guint len
);

void
buffer_mark_line (gint line_no);

void
buffer_set_modified (gboolean modified);

gboolean
buffer_get_modified (void);

#endif
