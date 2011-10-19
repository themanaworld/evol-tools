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

#include "config.h"

Options *config_options_new() {
  return g_new0(Options, 1);
}

void config_options_load_from_file(Options *options,
                                   gchar *file,
                                   gchar *data_folder) {
  options->sprites = NULL;

  XMLNode *node = ibus_xml_parse_file(file);

  if (node != NULL) {
    GList *list = node->sub_nodes;
    while (TRUE) {
      list = g_list_find_custom(list, "option", xml_node_compare_with_name_func);
      if (list == NULL)
        break;
      gchar *name_attr = xml_node_get_attr_value(list->data, "name");
      if (name_attr != NULL) {
        if (g_strcmp0(name_attr, "sprites") == 0)
          options->sprites = xml_node_get_attr_value(list->data, "value");
      }
      list = list->next;
    }
  }

  if (options->sprites == NULL) options->sprites = OPTION_SPRITES_DEFAULT;
  options->sprites = g_strjoin(SEPARATOR_SLASH, data_folder, options->sprites, NULL);
}

Keys *config_keys_new() {
  Keys *keys = g_new0(Keys, 1);
  keys->clientdata_folder = KEY_CLIENTDATA_FOLDER_DEFAULT;
  keys->show_grid = KEY_SHOW_GRID_DEFAULT;
  return keys;
}

void config_keys_save(Keys *keys) {
  GKeyFile *key_file = g_key_file_new();
  g_key_file_set_value(key_file, "General", "ClientdataFolder",
                       g_strjoin(SEPARATOR_SLASH,
                                 keys->clientdata_folder,
                                 POSTFIX_FOLDER,
                                 NULL));
  g_key_file_set_boolean(key_file, "General", "ShowGrid", keys->show_grid);

  mkdir(KEYS_CONFIG_DIR, S_IRWXU);
  int fd = g_creat(KEYS_CONFIG_FILE, S_IREAD | S_IWRITE);
  gchar *buf = g_key_file_to_data(key_file, NULL, NULL);
  write(fd, buf, strlen(buf), NULL);
  close(fd);

  g_key_file_free(key_file);
}

void config_keys_load(Keys *keys) {
  GKeyFile *key_file = g_key_file_new();

  g_key_file_load_from_file(key_file,
                            KEYS_CONFIG_FILE,
                            0,
                            NULL);
  if (g_key_file_has_key(key_file, "General", "ClientdataFolder", NULL))
    keys->clientdata_folder = g_key_file_get_value(key_file, "General", "ClientdataFolder", NULL);
  if (g_key_file_has_key(key_file, "General", "ShowGrid", NULL))
    keys->show_grid = g_key_file_get_boolean(key_file, "General", "ShowGrid", NULL);

  g_key_file_free(key_file);
}
