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

gboolean search_find_text(gchar *text);
gboolean search_find_next();
void search_find_dialog_show(GtkWindow *parent,
                             GtkWidget *text_view);

#endif
