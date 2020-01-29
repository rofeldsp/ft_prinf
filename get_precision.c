//
// Created by Rosanne Feldspar on 20/01/2020.
//
#include "ft_printf.h"

t_print		get_precision(t_print node)
{
	node.precision = 0;
	if (*node.input == '.')
	{
		node.input++;
		if (*node.input < '0' || *node.input > '9')
			return(get_size(node));
		node.precision = *node.input - '0';
		node.input++;
		while (*node.input >= '0' && *node.input <= '9')
		{
			node.precision = node.precision * 10 + (*node.input - '0');
			node.input++;
		}
	}
	else if (*node.input == '*')
	{
		node.precision = va_arg(node.ap, int);
		node.input++;
	}
	return(get_size(node));
}