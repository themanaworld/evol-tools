#ifndef XML_H
#define XML_H

#include <stdio.h>
#include <glib.h>
#include "common.h"

typedef struct {
	gchar  *name;
	gchar  *text;
	gchar **attributes;
	gint    line_no;
	GList  *sub_nodes;
} XMLNode;


XMLNode *
xml_parse_file (
	const gchar *name
);

XMLNode *
xml_parse_buffer (
	const gchar *buffer,
	GError **error
);

void xml_free (XMLNode *node);
void xml_output (
	const XMLNode  *node,
	GString        *output
);

gchar **
xml_attr_new (
	const gchar *name,
	const gchar *value
);

gchar *
xml_node_get_attr_value (
	const XMLNode *node,
	const gchar   *attr_name
);

gint
xml_node_get_int_attr_value (
	const XMLNode *node,
	const gchar *attr_name,
	gint retval
);

gint
xml_node_get_int_attr_value_limited (
	const XMLNode *node,
	const gchar   *attr_name,
	gint           retval,
	gint           lower,
	gint           upper
);


gint	 xml_node_compare_with_name_func(gconstpointer a, gconstpointer b);

/*
gint	 xml_node_compare_with_action_node_by_imageset_name_func(gconstpointer a, gconstpointer b);
gint	 xml_node_compare_with_attr_func(const XMLNode *node, const gchar **attr);
*/

#endif
