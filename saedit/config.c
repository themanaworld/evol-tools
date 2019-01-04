#include "config.h"
#include "xml.h"
#include <unistd.h>
#include <sys/stat.h>

static GKeyFile *_config_keyfile = NULL;

gchar *
_config_get_config_folder (void) {
	return g_strjoin (
		"/",
		g_get_user_config_dir (),
		"saedit2",
		NULL
	);
}

gchar *
_config_get_key_file_path (void) {
	gchar *dir = _config_get_config_folder ();
	gchar *result;

	result = g_strjoin (
		"/",
		dir,
		"config.ini",
		NULL
	);

	g_free (dir);
	return result;
}

void
config_keys_load () {
	gchar *filename;

	_config_keyfile = g_key_file_new ();

	filename = _config_get_key_file_path ();

	g_key_file_load_from_file (
		_config_keyfile,
		filename,
		0,
		NULL
	);

	g_free (filename);
}

gchar *
config_keys_get_data_folder_path () {
	gchar *result;

	if (_config_keyfile == NULL)
		config_keys_load ();
	
	result = g_key_file_get_value (
		_config_keyfile,
		"Default",
		"Data Folder",
		NULL
	);

	if (result == NULL)
		result = g_strdup ("");

	return result;
}

void
config_keys_set_data_folder_path (const gchar *filename) {
	if (_config_keyfile == NULL)
		config_keys_load ();

	g_key_file_set_value (
		_config_keyfile,
		"Default",
		"Data Folder",
		filename
	);
}

gint
config_keys_get_tile_size () {
	/* TODO */
	return 32;
}

void
config_keys_save () {
	gchar *filename;

	if (_config_keyfile == NULL)
		return;

	filename = _config_get_config_folder ();
	mkdir (filename, S_IRWXU);
	g_free (filename);

	filename = _config_get_key_file_path ();

	g_key_file_save_to_file (
		_config_keyfile,
		filename,
		NULL
	);

	g_free (filename);
}

static XMLNode *_config_paths_xml_root = NULL;

void
config_data_paths_load () {
	gchar *filename;
	gchar *df_path;

	df_path = config_keys_get_data_folder_path ();

	filename = g_strjoin (
		"/",
		df_path,
		"paths.xml",
		NULL
	);

	_config_paths_xml_root = xml_parse_file (filename);

	g_free (df_path);
	g_free (filename);
}

gchar *
config_data_paths_get_sprites_path () {
	XMLNode *node;
	GList *list;
	gchar *name;

	if (_config_paths_xml_root == NULL)
		config_data_paths_load ();

	node = _config_paths_xml_root;
	
	if (node != NULL) {
		list = node->sub_nodes;
		while (TRUE) {
			list = g_list_find_custom (
					list,
					"option",
					xml_node_compare_with_name_func
			);

			if (list == NULL)
				break;

			name = xml_node_get_attr_value (list->data, "name");
			if (name != NULL && g_strcmp0 (name, "sprites") == 0) {
				g_free (name);
				return xml_node_get_attr_value (list->data, "value");
			}

			g_free(name);
			list = list->next;
		}
	}

	return g_strdup ("");
}

gchar *
config_data_path_get_full_sprite_path (const gchar *rel_path) {
	gchar *data_folder, *sprites_path, *filename;

	data_folder = config_keys_get_data_folder_path ();
	sprites_path = config_data_paths_get_sprites_path ();

	filename = g_strjoin (
		"/",
		data_folder,
		sprites_path,
		rel_path,
		NULL
	);

	g_free (sprites_path);
	g_free (data_folder);

	return filename;
}
