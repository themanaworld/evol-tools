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

#include "sae.h"

void kill_timeout(guint tag) {
  if (tag > 0)
    g_source_remove(tag);
}

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

GdkPixbuf* get_sprite_by_index(size_t index, SAEInfo *sae_info) {
  size_t w = sae_info->imageset->spriteset_width/sae_info->imageset->width;
  if (sae_info->imageset->spriteset == NULL) return NULL;
  return gdk_pixbuf_new_subpixbuf(sae_info->imageset->spriteset, index%w*sae_info->imageset->width, index/w*sae_info->imageset->height, sae_info->imageset->width, sae_info->imageset->height);
}

gboolean set_up_animation_by_direction(SAEInfo *sae_info, const gchar *direction) {
  if (sae_info->imageset->spriteset == NULL)
    return FALSE;
  sae_info->animation = NULL;

  GList *list = g_list_find_custom(sae_info->animations,
                                   xml_attr_new("direction", direction),
                                   xml_node_compare_with_attr_func);
  if (list == NULL)
    return FALSE;
  int count = 0;
  XMLNode *anode = list->data;
  list = anode->sub_nodes;

  while (list != NULL) {
    XMLNode *node = list->data;

    int offsetX = 0, offsetY = 0,
        delay = 0,
        start = -1, end = -1,
        repeat = 1;

    gchar *ofX_param, *ofY_param;
    ofX_param = xml_node_get_attr_value(node, "offsetX");
    if (ofX_param != NULL)
      sscanf(ofX_param, "%d", &offsetX);
    ofY_param = xml_node_get_attr_value(node, "offsetY");
    if (ofY_param != NULL)
      sscanf(ofY_param, "%d", &offsetY);

    gchar *delay_attr = xml_node_get_attr_value(node, "delay");
    if (delay_attr != NULL)
      sscanf(delay_attr, "%d", &delay);

    if (g_str_equal(node->name, "frame")) {
      gchar *index_attr = xml_node_get_attr_value(node, "index");
      if (index_attr != NULL) {
        sscanf(index_attr, "%d", &start);
        end = start;
      }
    } else if (g_str_equal(node->name, "sequence")) {

      gchar *start_attr = xml_node_get_attr_value(node, "start");
      if (start_attr != NULL)
        sscanf(start_attr, "%d", &start);

      gchar *end_attr = xml_node_get_attr_value(node, "end");
      if (end_attr != NULL)
        sscanf(end_attr, "%d", &end);

      gchar *repeat_attr = xml_node_get_attr_value(node, "repeat");
      if (repeat_attr != NULL)
        sscanf(repeat_attr, "%d", &repeat);
    }

    if (start >= 0) {
      int r = 0, i = 0;
      for (r = 1; r <= repeat; r++) {
        for (i = start; i <= end; i++) {
          Frame *sprite = frame_new(i, offsetX, offsetY, delay);
          sprite->pixbuf = get_sprite_by_index(i, sae_info);
          count++;
          if (sae_info->animation != NULL)
            g_list_append(sae_info->animation, sprite);
          else {
            sae_info->animation = g_list_alloc();
            sae_info->animation->data = sprite;
          }
        }
      }
    }
    list = list->next;
  }
  if (sae_info->animation == NULL)
    return FALSE;
  if (count > 1)
    g_list_last(sae_info->animation)->next = g_list_first(sae_info->animation);
  return TRUE;
}
