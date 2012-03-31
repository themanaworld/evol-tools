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

Frame *frame_new(int index1, int offsetX, int offsetY, int delay) {
	Frame *res = g_new0(Frame, 1);
	res->index = index1;
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

GdkPixbuf* get_sprite_by_index(size_t index1, SAEInfo *sae_info) {
	// error because index1 is unsigned
	if (index1 == -1) {
		GdkPixbuf *res = gdk_pixbuf_new(GDK_COLORSPACE_RGB, TRUE, 8,
						sae_info->imageset->width,
						sae_info->imageset->height);
		gdk_pixbuf_fill(res, 0x00000000);
		return res;
	}

	// error because index1 is unsigned
	if (index1 >= 0) {
		size_t w = sae_info->imageset->spriteset_width/sae_info->imageset->width;
		if (sae_info->imageset->spriteset == NULL) return NULL;

		return gdk_pixbuf_new_subpixbuf(sae_info->imageset->spriteset,
						index1%w*sae_info->imageset->width,
						index1/w*sae_info->imageset->height,
						sae_info->imageset->width,
						sae_info->imageset->height);
	}

	return NULL;
}

inline void _add_frame(SAEInfo *sae_info, size_t index1, size_t offsetX, size_t offsetY, size_t delay, size_t line) {

	Frame *sprite = frame_new(index1, offsetX, offsetY, delay);
	sprite->line_number = line;
	sprite->pixbuf = get_sprite_by_index(index1, sae_info);

	if (sae_info->animation != NULL)
		sae_info->animation = g_list_append(sae_info->animation, sprite);
	else {
		sae_info->animation = g_list_alloc();
		sae_info->animation->data = sprite;
	}
}

gboolean set_up_animation_by_direction(SAEInfo *sae_info, const gchar *direction) {
	if (sae_info->imageset->spriteset == NULL)
		return FALSE;
	sae_info->animation = NULL;

	GList *list = g_list_find_custom(sae_info->animations,
	                                 xml_attr_new("direction", direction),
	                                 (GCompareFunc)xml_node_compare_with_attr_func);
	if (list == NULL)
		return FALSE;

	XMLNode *anode = list->data;
	list = anode->sub_nodes;

	while (list != NULL) {
		XMLNode *node = list->data;

		//sequence tag attributes
		int offsetX = 0, offsetY = 0,
		    delay = 0,
		    start = -1, end = -1,
		    repeat = 1;
		gchar *value = NULL;

		gchar *ofX_attr, *ofY_attr;
		ofX_attr = xml_node_get_attr_value(node, "offsetX");
		if (ofX_attr != NULL)
			sscanf(ofX_attr, "%d", &offsetX);

		ofY_attr = xml_node_get_attr_value(node, "offsetY");
		if (ofY_attr != NULL)
			sscanf(ofY_attr, "%d", &offsetY);

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

			value = xml_node_get_attr_value(node, "value");

			gchar *repeat_attr = xml_node_get_attr_value(node, "repeat");
			if (repeat_attr != NULL)
				sscanf(repeat_attr, "%d", &repeat);

		} else if (g_str_equal(node->name, "pause")) {

			value = (gchar *)"p";

			gchar *repeat_attr = xml_node_get_attr_value(node, "repeat");
			if (repeat_attr != NULL)
				sscanf(repeat_attr, "%d", &repeat);

		}

		if (start >= 0) {  //start-end case

			int r = 0, i = 0;
			for (r = 1; r <= repeat; r++) {
				for (i = start; i <= end; i++) {
					_add_frame(sae_info, i, offsetX, offsetY, delay, node->line_number);
				}
			}

		} else
		if (value != NULL) {  //value case

			gchar **values = g_strsplit(value, ",", 0);

			int r;
			for (r = 0; r < repeat; r++) { //TODO: remove multiparsing
				gchar **iter = values;
				while (*iter != NULL) {

					if (g_str_equal(*iter, "p")) { //pause

						_add_frame(sae_info, -1, 0, 0, delay, node->line_number);

					} else {

						unsigned f, s;

						if (sscanf(*iter, "%u-%u", &f, &s) == 2) {

							int i;
							for (i = f; i <= s; i++) {
								_add_frame(sae_info, i, offsetX, offsetY, delay, node->line_number);
							}

						} else if (sscanf(*iter, "%u", &f) == 1) {

							_add_frame(sae_info, f, offsetX, offsetY, delay, node->line_number);

						}

					}
					iter++;
				}
			}

			g_strfreev(values);

		}

		list = g_list_next(list);
	}
	if (sae_info->animation == NULL)
		return FALSE;

	return TRUE;
}
