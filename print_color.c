//
// Created by Rosanne Feldspar on 12/02/2020.
//

#include "ft_printf.h"

t_print 	print_color(t_print node)
{
	int 	offset;

	if (!(ft_strncmp(node.input, "{red}", offset = 5)))
		write(1, RED, 5);
	else if (!(ft_strncmp(node.input, "{green}", offset = 7)))
		write(1, GREEN, 5);
	else if (!(ft_strncmp(node.input, "{yellow}", offset = 8)))
		write(1, YELLOW, 5);
	else if (!(ft_strncmp(node.input, "{blue}", offset = 6)))
		write(1, BLUE, 5);
	else if (!(ft_strncmp(node.input, "{purple}", offset = 8)))
		write(1, PURPLE, 5);
	else if (!(ft_strncmp(node.input, "{cyan}", offset = 6)))
		write(1, CYAN, 5);
	else if (!(ft_strncmp(node.input, "{eoc}", offset = 5)))
		write(1, EOC, 4);
	else
		offset = 1;
	node.input += offset;
	return (node);
}