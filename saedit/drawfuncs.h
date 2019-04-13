#ifndef _DRAW_FUNCS_H_
#define _DRAW_FUNCS_H_

#include "spritedrawingarea.h"

void
interactor_sprite_layer_draw_func (
	SDALayer *layer,
	cairo_t *cr,
	gpointer user_data
);

void
background_layer_draw_func (
	SDALayer *layer,
	cairo_t *cr,
	gpointer user_data
);

void
tile_grid_layer_draw_func (
	SDALayer *layer,
	cairo_t *cr,
	gpointer user_data
);

void
pixel_grid_layer_draw_func (
	SDALayer *layer,
	cairo_t *cr,
	gpointer user_data
);
#endif
