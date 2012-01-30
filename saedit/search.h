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

#ifndef SEARCH_H
#define SEARCH_H

#include <gtk/gtk.h>
#include <gtksourceview/gtksourceview.h>
#include "common.h"

void search_init(GtkWidget *text_view);
gboolean search_find_text(gchar *text);
gboolean search_find_next();
void search_find_dialog_response_callback(GtkWidget *dialog,
                   gint response_id,
                   gpointer entry);

#endif
