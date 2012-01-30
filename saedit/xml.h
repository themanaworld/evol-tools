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
#ifndef XML_H
#define XML_H

#include <glib.h>
#include <ibus.h>
#include "common.h"

gchar **xml_attr_new(gchar *name, gchar *value);
gchar *xml_node_get_attr_value(XMLNode *node, gchar *attr_name);
gint xml_node_compare_with_name_func(gconstpointer a, gconstpointer b);
gint xml_node_compare_with_action_node_by_imageset_name_func(gconstpointer a, gconstpointer b);
gint xml_node_compare_with_attr_func(const XMLNode *node, const gchar **attr);

#endif
