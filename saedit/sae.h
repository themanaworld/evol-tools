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

#ifndef SAE_H
#define SAE_H

#include <gtk/gtk.h>
#include "common.h"
#include "xml.h"

void kill_timeout(guint tag);

typedef struct {
	int index;
	int offsetX;
	int offsetY;
	int delay;
	int line_number;
	GdkPixbuf *pixbuf;
	cairo_surface_t *surface;
} Frame;

Frame *frame_new(int index, int offsetX, int offsetY, int delay);

typedef struct {
	XMLNode *node;
	int offsetX;
	int offsetY;
	int width;
	int height;
	int spriteset_width;
	int spriteset_height;
	GdkPixbuf *spriteset;
} Imageset;

Imageset *imageset_new();

typedef struct {
	GList *imagesets;
	GList *actions;
	GList *animations;
	GList *animation;
	Imageset *imageset;
	Frame *sprite;
	guint anim_tag;
	XMLNode *root;
	GtkWidget *imagesets_combo_box;
	GtkWidget *actions_combo_box;
	GtkWidget *animations_combo_box;
	GdkPixbuf *ground;
	int offsetX;
	int offsetY;
} SAEInfo;

SAEInfo *sae_info_new();
GdkPixbuf *sae_info_ground_new();

GdkPixbuf* get_sprite_by_index(size_t index, SAEInfo *sae_info);
gboolean set_up_animation_by_direction(SAEInfo *sae_info, const gchar *direction);

#endif
