#include "common.h"

#include <stdlib.h>
#include <errno.h>

gboolean
try_strtoint (
	const gchar *str,
	gint        *result
) {
	gchar *endptr;
	gint   retval;

	errno = 0;
	retval = strtol (str, &endptr, 10);

	if (*endptr != 0 || errno != 0)
		return FALSE;

	*result = retval;
	return TRUE;
}
