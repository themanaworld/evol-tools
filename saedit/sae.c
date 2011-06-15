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

#include <gtk/gtk.h>
#include <ibusxml.h>
#include "common.h"
#include "sae.h"

Frame *frame_new(int index, int offsetX, int offsetY, int delay) {
  Frame *res = g_new0(Frame, 1);
  res->index = index;
  res->offsetX = offsetX;
  res->offsetY = offsetY;
  res->delay = delay;
  return res;
}

Imageset *imageset_new() {
  Imageset *res = g_new0(Imageset, 1);
  res->width = SPRITE_WIDTH_DEFAULT;
  res->height = SPRITE_HEIGHT_DEFAULT;
  return res;
}

SAEInfo *sae_info_new() {
  SAEInfo *res = g_new0(SAEInfo, 1);
  res->ground = sae_info_ground_new();
  res->sprite = frame_new(-1, 0, 0, 0);
  res->imageset = imageset_new();
  return res;
}

GdkPixbuf *sae_info_ground_new() {
  GdkPixbuf *ground = gdk_pixbuf_new(GDK_COLORSPACE_RGB, TRUE, 8, GRID_SIZE * 3, GRID_SIZE * 3);
  gdk_pixbuf_fill(ground, 0x00000000);
  return ground;
}
