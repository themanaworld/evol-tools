#include <gtksourceview/gtksource.h>
#include "errors.h"
#include "buffer.h"
#include "main.h"
#include "file.h"

#include <string.h>


gchar *opened_file_name = NULL;

gboolean
show_unsaved_changes_dialog () {
	gint result;
	GtkWidget *dialog;

	if (!buffer_get_modified ()) {
		return FALSE;
	}
	
	dialog = gtk_message_dialog_new (
		GTK_WINDOW (main_window),
		GTK_DIALOG_MODAL,
		GTK_MESSAGE_WARNING,
		GTK_BUTTONS_YES_NO,
		"There are unsaved changes in the current file. "
		"Do you wish to proceed?"
	);

	result = gtk_dialog_run (GTK_DIALOG (dialog));
	gtk_widget_destroy (dialog);

	return result == GTK_RESPONSE_NO;
}

void
open_file (
	const gchar *filename
) {
	gsize len;
	gchar *text;

	if (show_unsaved_changes_dialog ())
		return;

	release_context ();

	if (filename != NULL) {
		g_file_get_contents (
			filename,
			&text,
			&len,
			NULL
		);
	} else {
		text = g_strdup ("");
		len = 0;
	}

	g_free (opened_file_name);
	opened_file_name = g_strdup (filename);

	buffer_set_text (text, len);
	buffer_set_modified (FALSE);

	update_window_title ();

	g_free (text);
}

void
save_file (const gchar *filename) {
	GError *error = NULL;
	gboolean success;
	gchar *text = buffer_get_text ();

	success = g_file_set_contents (
		filename == NULL ? opened_file_name : filename,
		text,
		strlen (text),
		&error
	);

	if (!success) {
		post_error ("Saving", error->message);
	} else {
		if (filename != NULL) {
			g_free (opened_file_name);
			opened_file_name = g_strdup (filename);
		}

		buffer_set_modified (FALSE);
		update_window_title ();
	}

	g_free (text);
}

const gchar *
get_opened_file_name () {
	return opened_file_name;
}

