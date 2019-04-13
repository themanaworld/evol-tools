#ifndef __TREE_FOLDER_VIEW_PRIVATE_H__
#define __TREE_FOLDER_VIEW_PRIVATE_H__

enum {
	PROP_0,
	PROP_FILTER,
	PROP_FILENAME,
	PROP_MODEL,
	PROP_COUNT
};

static GtkTreeStore *
tree_folder_view_get_store (TreeFolderView *tfview);

static gchar *
tree_folder_view_get_file_path_from_tree_path (
	TreeFolderView *tfview,
	GtkTreePath *path
);

static gchar *
tree_folder_view_get_file_path_from_iter (
	TreeFolderView *tfview,
	GtkTreeIter *file_iter
);

static void
tree_store_append_file_children (
	GtkTreeStore *store,
	GtkTreeIter *iter,
	const gchar *path,
	gboolean expanded
);

static gint
tree_store_append_file_recursive (
	GtkTreeStore *store,
	GtkTreeIter *parent_iter,
	const gchar *path,
	const gchar *display_name,
	gboolean append_children
);

#endif

