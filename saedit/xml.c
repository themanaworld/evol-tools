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

#include <glib.h>
#include <ibusxml.h>
#include "common.h"
#include "xml.h"

gchar **xml_attr_new(gchar *name, gchar *value) {
  gchar **attr = g_new0(gchar*, 2);
  attr[0] = name;
  attr[1] = value;
  return attr;
}

gchar* xml_node_get_attr_value(XMLNode *node, gchar *attr_name) {
  gchar **attr = node->attributes;
  int i;
  for (i = 0; i < g_strv_length(attr); i += 2)
    if (g_str_equal(attr[i], attr_name))
      return attr[i + 1];
  return NULL;
}


gint xml_node_compare_with_name_func(gconstpointer a, gconstpointer b) {
  return g_strcmp0((gchar *)b, ((XMLNode *)a)->name);
}

gint xml_node_compare_with_action_node_by_imageset_name_func(gconstpointer a, gconstpointer b) {
  return g_strcmp0("action", ((XMLNode *)a)->name) ||
         g_strcmp0((gchar *)b, xml_node_get_attr_value((XMLNode *)a, "imageset"));
}

gint xml_node_compare_with_attr_func(const XMLNode *node, const gchar **attr) {
  return g_strcmp0(attr[1],
                   xml_node_get_attr_value(node, attr[0]));
}
