//
// Created by Rosanne Feldspar on 22/01/2020.
//

#include "ft_printf.h"

t_print		adjust_to_width(t_print node, int len)
{
	int len2;

	len2 = node.width;
	if (node.width <= len)
		return (node);
	if ((node.pointer + node.width) >= 100 || (node.pointer + node.width) % 100
											  < node.pointer % 100)
		node.buffer = increase_buffer(&node.buffer, &node);
	while (len2 >= 0)
	{
		node.buffer[node.pointer + len2] = ' ';
		len2--;
	}
	return(node);
}

t_print 	adjust_to_flag(t_print node, int len)
{
	int	len_width;

	len_width = node.width;
	node.empty_space = node.width - len;
	if (node.flag == '0')
		while (len_width-- > len)
			node.buffer[node.pointer++] = '0';
	return (node);
}

t_print 	adjust_to_flag2(t_print node, int len)
{
	int	len_width;

	len_width = node.width;
	node.empty_space = node.width - len;
	if (node.flag == '0')
		while (len_width-- > len)
			node.buffer[node.pointer++] = '0';
	if (node.flag == '+')
	{
		if (node.number >= 0)
			node.buffer[node.pointer++] = '+';
	}
	return (node);
}
