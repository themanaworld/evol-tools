#ifndef _CONFIG_H_
#define _CONFIG_H_

#include <glib.h>

void
config_keys_load (void);

void
config_keys_save (void);

gchar *
config_keys_get_data_folder_path (void);

void
config_keys_set_data_folder_path (
	const gchar *filename
);

gint
config_keys_get_tile_size (void);

void
config_data_paths_load (void);

gchar *
config_data_paths_get_sprites_path (void);

gchar *
config_data_path_get_full_sprite_path (const gchar *rel_path);

#endif
