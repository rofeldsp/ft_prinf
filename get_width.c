//
// Created by Rosanne Feldspar on 20/01/2020.
//

#include "ft_printf.h"

t_print		get_width(t_print node)
{
	node.width = 0;
	if (*node.input >= '1' && *node.input <= '9')
	{
		node.width = *node.input - '0';
		node.input++;
		while (*node.input >= '0' && *node.input <= '9')
		{
			node.width = node.width * 10 + *node.input - '0';
			node.input++;
		}
	}
	else if (*node.input == '*')
	{
		node.width = va_arg(node.ap, int);
		node.input++;
	}
	return(get_precision(node));
}