#include "errors.h"
#include "main.h"

void
post_error (
	const gchar *error_context,
	const gchar *error_message
) {
	GtkWidget *dialog;

	dialog = gtk_message_dialog_new_with_markup (
		GTK_WINDOW (main_window),
		GTK_DIALOG_MODAL | GTK_DIALOG_DESTROY_WITH_PARENT,
		GTK_MESSAGE_ERROR,
		GTK_BUTTONS_CLOSE,
		"<b>%s error:</b> %s",
		error_context,
		error_message
	);

	gtk_dialog_run (GTK_DIALOG (dialog));
	gtk_widget_destroy (dialog);
}
