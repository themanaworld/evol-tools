static void
tree_folder_view_init (
	TreeFolderView *tfview,
	TreeFolderViewClass *klass
) {
	GType *types;
	GtkCellRenderer *renderer;
	GtkTreeModel *model;
	GtkTreeStore *store;
	GtkTreeView *tview;
	GtkTreeViewColumn *col;

	tview = GTK_TREE_VIEW (tfview);

	/* Setting up TreeView properties */
	gtk_tree_view_set_headers_visible (tview, FALSE);
	gtk_tree_view_set_enable_tree_lines (tview, TRUE);
	
	/* Setting up only column */
	col = gtk_tree_view_column_new ();

	/* Filename renderer */
	renderer = gtk_cell_renderer_text_new ();
	gtk_tree_view_column_pack_end (col, renderer, TRUE);
	gtk_tree_view_column_set_attributes (
		col,
		renderer,
		"text", STORE_COLUMN_FILE_NAME,
		NULL
	);

	/* Filetype renderer */
	renderer = gtk_cell_renderer_pixbuf_new();
	gtk_tree_view_column_pack_end (col, renderer, FALSE);
	gtk_tree_view_column_set_attributes (
		col,
		renderer,
		"gicon", STORE_COLUMN_FILE_ICON,
		NULL
	);

	gtk_tree_view_append_column (tview, col);
	
	/* Setting up TreeStore */
	types = g_new (GType, STORE_COLUMN_COUNT);
	types [STORE_COLUMN_FILE_NAME] = G_TYPE_STRING;
	types [STORE_COLUMN_FILE_ICON] = G_TYPE_ICON;
	types [STORE_COLUMN_FILE_INFO] = G_TYPE_FILE_INFO;
	types [STORE_COLUMN_IS_FOLDER] = G_TYPE_BOOLEAN;
	types [STORE_COLUMN_WAS_EXPANDED] = G_TYPE_BOOLEAN;

	store = gtk_tree_store_newv (STORE_COLUMN_COUNT, types);
	g_free(types);

	gtk_tree_sortable_set_sort_func (
		GTK_TREE_SORTABLE (store),
		STORE_COLUMN_FILE_NAME,
		(GtkTreeIterCompareFunc) tree_store_iter_compare_func,
		NULL,
		NULL
	);

	gtk_tree_sortable_set_sort_column_id (
		GTK_TREE_SORTABLE (store),
		STORE_COLUMN_FILE_NAME,
		GTK_TREE_SORTABLE_DEFAULT_SORT_COLUMN_ID
	);

	/* Setting up TreeModelFilter */
	model = gtk_tree_model_filter_new (GTK_TREE_MODEL (store), NULL);
	gtk_tree_model_filter_set_visible_func (
		GTK_TREE_MODEL_FILTER (model),
		(GtkTreeModelFilterVisibleFunc) tree_model_filter_file_visible_func,
		(gpointer) tview,
		NULL
	);
	gtk_tree_view_set_model (tview, model);
	
	/* Setting up private */
	tfview->priv = G_TYPE_INSTANCE_GET_PRIVATE (
		tfview,
		TYPE_TREE_FOLDER_VIEW,
		TreeFolderViewPrivate
	);
}

static void
tree_folder_view_set_property (
	GObject *object,
	guint prop_id,
	const GValue *value,
	GParamSpec *pspec
) {
	TreeFolderView *tfview = TREE_FOLDER_VIEW (object);

	switch (prop_id) {
		case PROP_FILTER:
			tree_folder_view_set_filter (
				tfview,
				GTK_FILE_FILTER (g_value_get_object (value))
			);
			break;
		case PROP_FILENAME:
			tree_folder_view_set_filename (
				tfview,
				g_value_get_string (value)
			);
			break;
		case PROP_MODEL:
			g_warning(
				"\"model\" property of GtkTreeView is overriden "
				"in TreeFolderView and shouldn't be changed"
			);
			break;
		default:
			G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
			break;
	}
}

static void
tree_folder_view_get_property (
	GObject *object,
	guint prop_id,
	GValue *value,
	GParamSpec *pspec
) {
	TreeFolderView *tfview = TREE_FOLDER_VIEW (object);

	switch (prop_id) {
		case PROP_FILTER:
			g_value_set_object (
				value, tree_folder_view_get_filter (tfview)
			);
			break;
		case PROP_FILENAME:
			g_value_set_string (
				value, tree_folder_view_get_filename (tfview)
			);
			break;
		case PROP_MODEL:
			g_value_set_object (
				value, gtk_tree_view_get_model (GTK_TREE_VIEW (tfview))
			);
			break;
		default:
			G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
			break;
	}
}

static void
tree_folder_view_class_init (
	TreeFolderViewClass *klass,
	gpointer class_data
) {
	GObjectClass *object_class;
	GtkTreeViewClass *tree_view_class;
	
	object_class = G_OBJECT_CLASS (klass);
	tree_view_class = GTK_TREE_VIEW_CLASS (klass);

	tree_view_class->row_activated = tree_folder_view_row_activated;
	tree_view_class->row_expanded = tree_folder_view_row_expanded;

	tfview_signals [SIGNAL_FILE_ACTIVATED] = g_signal_new (
		"file-activated",
		TYPE_TREE_FOLDER_VIEW,
		G_SIGNAL_RUN_LAST | G_SIGNAL_ACTION,
		G_STRUCT_OFFSET (TreeFolderViewClass, file_activated),
		NULL, NULL, NULL,
		G_TYPE_NONE, 1,
		G_TYPE_STRING
	);

	g_type_class_add_private (klass, sizeof (TreeFolderViewPrivate));

	object_class->set_property = tree_folder_view_set_property;
	object_class->get_property = tree_folder_view_get_property;
 
	g_object_class_install_property (
		object_class,
		PROP_FILTER,
		g_param_spec_object (
			"filter",
			"File filter",
			"File filter for selecting "
			"which files should be displayed.",
			GTK_TYPE_FILE_FILTER,
			G_PARAM_READWRITE | G_PARAM_CONSTRUCT
		)
	);

	g_object_class_install_property (
		object_class,
		PROP_FILENAME,
		g_param_spec_string (
			"filename",
			"Folder filename",
			"Full path to a folder "
			"which contents are displayed.",
			NULL,
			G_PARAM_READWRITE | G_PARAM_CONSTRUCT
		)
	);

	g_object_class_override_property (
		object_class,
		PROP_MODEL,
		"model"
	);
}

GType
tree_folder_view_get_type (void) {
	static GType tfview_type = 0;

	if (tfview_type == 0) {
		const GTypeInfo tfview_info = {
			sizeof (TreeFolderViewClass),
			NULL, 	/* base_init */
			NULL, 	/* base_finalize */
			(GClassInitFunc) tree_folder_view_class_init,
			NULL, 	/* class_finalize */
			NULL,	/* class_data */
			sizeof (TreeFolderView),
			0,	/* n_preallocs */
			(GInstanceInitFunc) tree_folder_view_init,
			NULL,	/* value_table */
		};

		tfview_type = g_type_register_static (
			GTK_TYPE_TREE_VIEW,
			"TreeFolderView",
			&tfview_info,
			0
		);

	}

	return tfview_type;
}

GtkWidget *
tree_folder_view_new (void) {
	GtkWidget *tfview = GTK_WIDGET (
		g_object_new (TYPE_TREE_FOLDER_VIEW, NULL)
	);
	return tfview;
}
