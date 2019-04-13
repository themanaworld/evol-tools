#ifndef COMMON_H
#define COMMON_H

#include <glib.h>

gboolean
try_strtoint (
	const gchar *str,
	gint        *result
);

#endif
