#include "treefolderview.h"
#include "treefolderviewprivate.h"

enum {
	STORE_COLUMN_FILE_NAME,
	STORE_COLUMN_IS_FOLDER,
	STORE_COLUMN_FILE_ICON,
	STORE_COLUMN_FILE_INFO,
	STORE_COLUMN_WAS_EXPANDED,
	STORE_COLUMN_COUNT
};

enum {
	SIGNAL_FILE_ACTIVATED,
	SIGNAL_COUNT
};

struct _TreeFolderViewPrivate {
	gchar *filename;
	GtkFileFilter *file_filter;
};

static guint tfview_signals [SIGNAL_COUNT] = { 0 };

static GtkTreeStore *
tree_folder_view_get_store (TreeFolderView *tfview) {
	GtkTreeModelFilter *model;
	
	model = GTK_TREE_MODEL_FILTER (gtk_tree_view_get_model (GTK_TREE_VIEW (tfview)));
	return GTK_TREE_STORE (gtk_tree_model_filter_get_model (model));
}

static gboolean
file_filter_filter_file_info (GtkFileFilter *filter, GFileInfo *info) {
	gboolean result;
	gchar *mimetype = NULL;
	GtkFileFilterFlags required;
	GtkFileFilterInfo filter_info = { 0, };

	if (filter == NULL)
		return TRUE;

	required = gtk_file_filter_get_needed (filter);

	filter_info.contains |= GTK_FILE_FILTER_DISPLAY_NAME;
	filter_info.display_name = g_file_info_get_display_name (info);

	if (required & GTK_FILE_FILTER_MIME_TYPE) {
		const gchar *ctype = g_file_info_get_content_type (info);
		if (ctype != NULL) {
			mimetype = g_content_type_get_mime_type (ctype);
			if (mimetype != NULL) {
				filter_info.contains |= GTK_FILE_FILTER_MIME_TYPE;
				filter_info.mime_type = mimetype;
			}
		}
	}

	if (required & GTK_FILE_FILTER_FILENAME) {
		filter_info.filename = g_file_info_get_name (info);
		filter_info.contains |= GTK_FILE_FILTER_FILENAME;
	}

	result = gtk_file_filter_filter (filter, &filter_info);

	g_free(mimetype);

	return result;
}

static gchar *
tree_folder_view_get_file_path_from_tree_path (
	TreeFolderView *tfview,
	GtkTreePath *path
) {
	GtkTreeIter iter;
	GtkTreeModel *model;

	model = GTK_TREE_MODEL (tree_folder_view_get_store (tfview));
	gtk_tree_model_get_iter (model, &iter, path);

	return tree_folder_view_get_file_path_from_iter (tfview, &iter);
}

static gchar *
tree_folder_view_get_file_path_from_iter (
	TreeFolderView *tfview,
	GtkTreeIter *file_iter
) {
	gchar *result, *data;
	GPtrArray *names;
	GtkTreeIter iter;
	GtkTreeModel *model;
	GtkTreePath *_path;

	model = GTK_TREE_MODEL (tree_folder_view_get_store (tfview));
	_path = gtk_tree_model_get_path (model, file_iter);

	names = g_ptr_array_new_with_free_func ((GDestroyNotify) g_free);

	while (gtk_tree_path_get_depth (_path) > 0)  {
		gtk_tree_model_get_iter (model, &iter, _path);
		gtk_tree_model_get (
			model, &iter, 
			STORE_COLUMN_FILE_NAME, &data, -1
		);
		g_ptr_array_insert (names, 0, data);
		gtk_tree_path_up (_path);
	}

	g_ptr_array_insert (names, 0, g_strdup (tfview->priv->filename));
	g_ptr_array_add (names, NULL);
	result = g_strjoinv ("/", (gchar **) names->pdata);

	g_ptr_array_free (names, TRUE);
	gtk_tree_path_free (_path);

	return result;
}

static void
tree_folder_view_row_expanded (
	GtkTreeView *tree_view,
	GtkTreeIter *filter_iter,
	GtkTreePath *path
) {
	gboolean w_exp;
	gchar *file_path;
	GtkTreeIter iter, citer;
	GtkTreeStore *store;

	gtk_tree_model_filter_convert_iter_to_child_iter (
		GTK_TREE_MODEL_FILTER (gtk_tree_view_get_model (tree_view)),
		&iter,
		filter_iter
	);

	store = tree_folder_view_get_store (
		TREE_FOLDER_VIEW (tree_view)
	);
	
	gtk_tree_model_get (
		GTK_TREE_MODEL (store), &iter,
		STORE_COLUMN_WAS_EXPANDED, &w_exp,
		-1
	);

	if (w_exp)
		return;

	gtk_tree_store_set (
		store, &iter,
		STORE_COLUMN_WAS_EXPANDED, TRUE,
		-1
	);

	if (!gtk_tree_model_iter_has_child (GTK_TREE_MODEL (store), &iter))
		return;

	gtk_tree_model_iter_children (GTK_TREE_MODEL (store), &citer, &iter);
	do {
		file_path = tree_folder_view_get_file_path_from_iter (
			TREE_FOLDER_VIEW (tree_view),
			&citer
		);

		tree_store_append_file_children (
			store,
			&citer,
			file_path,
			FALSE
		);

		g_free (file_path);
	} while (gtk_tree_model_iter_next (GTK_TREE_MODEL (store), &citer));
}

static gboolean
tree_model_filter_file_visible_func (
	GtkTreeModel *model,
	GtkTreeIter *iter,
	gpointer data
) {
	gboolean is_folder;
	GFileInfo *info;
	GtkFileFilter *filter;
	TreeFolderView *tfview;

	tfview = TREE_FOLDER_VIEW (data);

	gtk_tree_model_get (
		model, iter,
		STORE_COLUMN_FILE_INFO, &info,
		STORE_COLUMN_IS_FOLDER, &is_folder,
		-1
	);

	if (info == NULL)
		return FALSE;

	if (g_file_info_get_is_hidden (info))
		return FALSE;

	if (is_folder)
		return TRUE;

	filter = tree_folder_view_get_filter (tfview);
	return file_filter_filter_file_info (filter, info);
}

static void
tree_store_append_file_children (
	GtkTreeStore *store,
	GtkTreeIter *iter,
	const gchar *path,
	gboolean expanded
) {
	gchar *npath;
	const gchar *name;
	GDir *dir;

	dir = g_dir_open (path, 0, NULL);

	if (dir == NULL)
		return;

	while ((name = g_dir_read_name (dir)) != NULL) {
		npath = g_strconcat (path, "/", name, NULL);
		
		tree_store_append_file_recursive (
			store,
			iter,
			npath,
			name,
			expanded
		);
			
		g_free(npath);
	}

	g_dir_close (dir);
}

static gint
tree_store_append_file_recursive (
	GtkTreeStore *store,
	GtkTreeIter *parent_iter,
	const gchar *path,
	const gchar *display_name,
	gboolean append_children
) {
	GFile *file;
	GFileInfo *info;
	GtkTreeIter iter;

	file = g_file_new_for_path (path);
	info = g_file_query_info (file, "*", 0, NULL, NULL);
	g_object_unref (file);

	gtk_tree_store_append (store, &iter, parent_iter);
	gtk_tree_store_set (
		store, &iter,
		STORE_COLUMN_FILE_NAME, display_name,
		STORE_COLUMN_FILE_ICON, g_content_type_get_icon (g_file_info_get_content_type (info)),
		STORE_COLUMN_FILE_INFO, info,
		STORE_COLUMN_IS_FOLDER, FALSE, 
		STORE_COLUMN_WAS_EXPANDED, FALSE,
		-1
	);

	if (g_file_info_get_file_type (info) != G_FILE_TYPE_DIRECTORY)
		return 0;

	gtk_tree_store_set (
		store, &iter, 
		STORE_COLUMN_IS_FOLDER, TRUE,
		STORE_COLUMN_FILE_ICON, g_themed_icon_new ("folder"), -1
	);

	if (!append_children)
		return 1;

	tree_store_append_file_children (store, &iter, path, FALSE);
	
	return 1;
}

static gint
tree_store_iter_compare_func (
	GtkTreeModel *model,
	GtkTreeIter *a,
	GtkTreeIter *b,
	gpointer user_data
) {
	gboolean isf_a, isf_b;
	gint cmp;
	gchar *val_a, *val_b;

	gtk_tree_model_get (model, a, STORE_COLUMN_IS_FOLDER, &isf_a, -1);
	gtk_tree_model_get (model, b, STORE_COLUMN_IS_FOLDER, &isf_b, -1);

	if (isf_a != isf_b)
		return isf_b;
	
	gtk_tree_model_get (model, a, STORE_COLUMN_FILE_NAME, &val_a, -1);
	gtk_tree_model_get (model, b, STORE_COLUMN_FILE_NAME, &val_b, -1);

	cmp = g_strcmp0 (val_a, val_b);
	g_free (val_a);
	g_free (val_b);

	return cmp;
}

static void
tree_folder_view_row_activated (
	GtkTreeView *tree_view, 
	GtkTreePath *filter_path, 
	GtkTreeViewColumn *col
) {
	gboolean is_folder;
	GtkTreeIter iter;
	GtkTreePath *path;
	GtkTreeStore *store;

	path = gtk_tree_model_filter_convert_path_to_child_path (
		GTK_TREE_MODEL_FILTER (gtk_tree_view_get_model (tree_view)),
		filter_path
	);
	
	store = tree_folder_view_get_store (TREE_FOLDER_VIEW (tree_view));

	gtk_tree_model_get_iter (GTK_TREE_MODEL (store), &iter, path);
	gtk_tree_model_get (
		GTK_TREE_MODEL (store), &iter,
		STORE_COLUMN_IS_FOLDER, &is_folder, -1
	);

	if (is_folder)
		return;

	g_signal_emit (
		tree_view, 
		tfview_signals[SIGNAL_FILE_ACTIVATED], 
		0,
		tree_folder_view_get_file_path_from_tree_path (
			TREE_FOLDER_VIEW (tree_view),
			path
		)
	);

	gtk_tree_path_free (path);
}

void
tree_folder_view_set_filename (
	TreeFolderView *tfview, 
	const gchar *filename
) {
	GtkTreeStore *store = tree_folder_view_get_store (tfview);

	/* TODO: values inside are not freed */
	gtk_tree_store_clear (store);

	g_free (tfview->priv->filename);
	tfview->priv->filename = g_strdup (filename);

	if (filename != NULL) {
		tree_store_append_file_children (
			store,
			NULL,
			filename,
			TRUE
		);
	}
}

GtkFileFilter *
tree_folder_view_get_filter (TreeFolderView *tfview) {
	return tfview->priv->file_filter;
}

void
tree_folder_view_set_filter (TreeFolderView *tfview, GtkFileFilter *filter) {
	if (G_IS_OBJECT (tfview->priv->file_filter))
		g_object_unref (tfview->priv->file_filter);
	
	tfview->priv->file_filter = filter;
	g_object_ref (filter);
	
	gtk_tree_model_filter_refilter (
		GTK_TREE_MODEL_FILTER (gtk_tree_view_get_model (GTK_TREE_VIEW (tfview))));
}

gchar *
tree_folder_view_get_filename (TreeFolderView *tfview) {
	return g_strdup (tfview->priv->filename);
}

#include "type.c"
