//
// Created by Rosanne Feldspar on 20/01/2020.
//

#include "ft_printf.h"

t_print		get_flag(t_print node)
{
	if (!(node.flag = strchr(" -+#0", *node.input)))
		node.input++;
	node = get_width(node);
	return (node);
}