#ifndef _FILE_H_
#define _FILE_H_

gboolean
show_unsaved_changes_dialog (void);

const gchar *
get_opened_file_name (void);

void
open_file (const gchar *filename);

void
save_file (const gchar *filename);

#endif
