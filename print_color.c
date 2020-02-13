//
// Created by Rosanne Feldspar on 12/02/2020.
//

#include "ft_printf.h"

t_print 	print_color(t_print node)
{
	int 	offset;

	if (!(ft_strncmp(node.input, "{red}", offset = 5)))
		buffer_color(&node, RED);
	else if (!(ft_strncmp(node.input, "{green}", offset = 7)))
		buffer_color(&node, GREEN);
	else if (!(ft_strncmp(node.input, "{yellow}", offset = 8)))
		buffer_color(&node, YELLOW);
	else if (!(ft_strncmp(node.input, "{blue}", offset = 6)))
		buffer_color(&node, BLUE);
	else if (!(ft_strncmp(node.input, "{purple}", offset = 8)))
		buffer_color(&node, PURPLE);
	else if (!(ft_strncmp(node.input, "{cyan}", offset = 6)))
		buffer_color(&node, CYAN);
	else if (!(ft_strncmp(node.input, "{eoc}", offset = 5)))
		buffer_color(&node, EOC);
	else
	{
		offset = 1;
		node.buffer[node.pointer++] = '{';
	}
	node.input += offset;
	return (node);
}

void 		buffer_color(t_print *node, const char *color)
{
	int i;

	i = 0;
	while (color[i])
		node->buffer[node->pointer++] = color[i++];
}
