//
// Created by Rosanne Feldspar on 23/01/2020.
//

#include "ft_printf.h"

t_print		parse_percent(t_print node)
{
	char *str;

	str = "\0";
	node = adjust_to_width(node, 1);
	node = adjust_to_flag2(node, 1, '0', str);
	node.pointer += node.empty_space;
	node = adjust_to_precision(node, 1, &str);
	if ((node.pointer + 1) % BUFF_SIZE == 0)
		node.buffer = increase_buffer(&node.buffer, &node);
	node.buffer[node.pointer++] = '%';
	node.input++;
	return (node);
}
