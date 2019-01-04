#ifndef __TREE_FOLDER_VIEW_H__
#define __TREE_FOLDER_VIEW_H__

#include <gdk/gdk.h>
#include <gtk/gtk.h>

G_BEGIN_DECLS

#define TYPE_TREE_FOLDER_VIEW (tree_folder_view_get_type ())
#define TREE_FOLDER_VIEW(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_TREE_FOLDER_VIEW, TreeFolderView))
#define TREE_FOLDER_VIEW_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_TREE_FOLDER_VIEW, TreeFolderViewClass))
#define IS_TREE_FOLDER_VIEW(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_TREE_FOLDER_VIEW))
#define IS_TREE_FOLDER_VIEW_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_TREE_FOLDER_VIEW))
#define TREE_FOLDER_VIEW_GET_CLASS(obj) ((obj), TYPE_TREE_FOLDER_VIEW, TreeFolderViewClass)

typedef struct _TreeFolderView TreeFolderView;
typedef struct _TreeFolderViewPrivate TreeFolderViewPrivate;
typedef struct _TreeFolderViewClass TreeFolderViewClass;

struct _TreeFolderView {
	GtkTreeView tview;

	TreeFolderViewPrivate *priv;
};

struct _TreeFolderViewClass {
	GtkTreeViewClass tview_class;

	void (* file_activated) (
		TreeFolderView *tfview,
		gchar *filename
	);
};

GType
tree_folder_view_get_type (void);

GtkWidget*
tree_folder_view_new (void);

void
tree_folder_view_set_filename  (
	TreeFolderView *tfview,
	const gchar    *filename
);

GtkFileFilter*
tree_folder_view_get_filter  (TreeFolderView *tfview);

void
tree_folder_view_set_filter  (
	TreeFolderView *tfview,
	GtkFileFilter *filter
);

gchar *
tree_folder_view_get_filename (TreeFolderView *tfview);

gchar *
tree_folder_view_get_display_name (TreeFolderView *tfview);

G_END_DECLS

#endif
