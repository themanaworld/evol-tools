#ifndef _MAIN_H_
#define _MAIN_H_

#include <gtk/gtk.h>
#include "treefolderview.h"
#include "context.h"
#include "interactor.h"
#include "spritedrawingarea.h"

GtkWidget  *main_window;
GtkWidget  *d_area;
GtkWidget  *source_view;
GtkWidget  *tf_view;
GtkWidget  *tbtn_play;

GtkComboBox     *cb_actions;
GtkComboBoxText *cb_directions;
GtkListStore    *store_actions;
GtkAdjustment	*zoom_adj;

SpriteContext *context;
Interactor    *interactor;

SDALayer *tile_grid_layer;
SDALayer *pixel_grid_layer;

void
buffer_set_modified (gboolean modified);

gboolean
buffer_get_modified (void);

void
release_context (void);

void
intr_updated (Interactor *interactor);

void
update_window_title (void);

GtkWidget *
window_main_get_source_view (void);

void
update_window_title (void);

void
release_context (void);

#endif
