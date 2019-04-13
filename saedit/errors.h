#ifndef _ERRORS_H_
#define _ERRORS_H_

#include <glib.h>

void
post_error (
	const gchar *error_context,
	const gchar *error_message
);

#endif
