#include "interactor.h"
#include "drawfuncs.h"
#include "spritedrawingarea.h"
#include "config.h"

void
interactor_sprite_layer_draw_func (
	SDALayer *layer,
	cairo_t *cr,
	gpointer user_data
) {
	const GdkPixbuf *sprite;
	gint offsetX, offsetY;
	Interactor *interactor = *((Interactor **) user_data);

	if (interactor == NULL)
		return;

	sprite = interactor_get_sprite (interactor);

	if (sprite == NULL)
		return;

	interactor_get_offset (interactor, &offsetX, &offsetY);

	gdk_cairo_set_source_pixbuf (
		cr, sprite,
		offsetX,
		offsetY + config_keys_get_tile_size () / 2
	);
	cairo_pattern_set_filter (
		cairo_get_source (cr),
		CAIRO_FILTER_NEAREST
	);
	cairo_paint (cr);
}

void
background_layer_draw_func (
	SDALayer *layer,
	cairo_t *cr,
	gpointer user_data
) {
	GdkRGBA *rgba = (GdkRGBA *) user_data;

	gdk_cairo_set_source_rgba (cr, rgba);

	cairo_rectangle (
		cr,
		-SPRITE_DRAWING_AREA_FIELD_SIZE,
		-SPRITE_DRAWING_AREA_FIELD_SIZE,
		2 * SPRITE_DRAWING_AREA_FIELD_SIZE,
		2 * SPRITE_DRAWING_AREA_FIELD_SIZE
	);
	cairo_fill (cr);
}

void
tile_grid_layer_draw_func (
	SDALayer *layer,
	cairo_t *cr,
	gpointer user_data
) {
	gint x;
	gint field_size = SPRITE_DRAWING_AREA_FIELD_SIZE;
	gint tile_size = config_keys_get_tile_size ();

	cairo_set_line_width (cr, 1.0);
	cairo_set_operator (cr, CAIRO_OPERATOR_XOR);
	cairo_set_source_rgba (cr, 0, 0, 0, 0.5);
	cairo_translate (cr, 0.5, 0.5);

	x = -tile_size / 2;
	while (x >= -field_size)
		x -= tile_size;

	for (; x <= field_size; x += tile_size) {
		cairo_move_to (cr, x, -field_size);
		cairo_line_to (cr, x,  field_size);
		cairo_move_to (cr, -field_size, x);
		cairo_line_to (cr,  field_size, x);
	}

	cairo_stroke (cr);
}

void
pixel_grid_layer_draw_func (
	SDALayer *layer,
	cairo_t *cr,
	gpointer user_data
) {
	gint x;
	gint field_size = SPRITE_DRAWING_AREA_FIELD_SIZE;

	cairo_set_line_width (cr, 0.1);
	cairo_set_source_rgb (cr, 0, 0, 0);
	
	for (x = -field_size; x <= field_size; ++x) {
		cairo_move_to (cr, x, -field_size);
		cairo_line_to (cr, x,  field_size);
		cairo_move_to (cr, -field_size, x);
		cairo_line_to (cr,  field_size, x);
	}

	cairo_stroke (cr);
}
