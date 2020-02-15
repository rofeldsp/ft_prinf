//
// Created by Rosanne Feldspar on 16/01/2020.
//

#include "ft_printf.h"

t_print		parse_char(t_print node)
{
	int		i;
	char	c;

	i = 0;
	c = va_arg(node.ap, int);
	node = adjust_to_width(node, 1);
	node = adjust_to_flag(node, 1);
	node.pointer += node.empty_space;
	node.buffer[node.pointer++] = c;
	if (c == 0)
		node.count_nulls++;
	if (node.flag & MINUS)
	{
		if ((node.empty_space = (node.width > 1 ? node.width - 1 : 0)) != 0)
			node.pointer += node.empty_space;
	}
	node.input++;
	return (node);
}
