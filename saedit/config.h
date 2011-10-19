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

#ifndef CONFIG_H
#define CONFIG_H

#include <glib.h>
#include <ibusxml.h>
#include "common.h"
#include "xml.h"

#define OPTION_SPRITES_DEFAULT "graphics/sprites/"

#define KEY_SHOW_GRID_DEFAULT TRUE
#define KEY_CLIENTDATA_FOLDER_DEFAULT ""
#define KEYS_CONFIG_FILE g_strjoin(SEPARATOR_SLASH, g_get_user_config_dir(), "saedit/config.ini", NULL)

typedef struct {
  gchar *sprites;
} Options;

Options *config_options_new();
void config_options_load_from_file(Options *options,
                                   gchar *file,
                                   gchar *data_folder);

typedef struct {
  gchar *clientdata_folder;
  gboolean show_grid;
} Keys;

Keys *config_keys_new();
void config_keys_load(Keys *keys);
void config_keys_save(Keys *keys);

#endif
