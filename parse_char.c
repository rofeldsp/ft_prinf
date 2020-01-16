//
// Created by Rosanne Feldspar on 16/01/2020.
//

#include "ft_printf.h"

t_print		parse_char(t_print node)
{
	char	c;

	c = va_arg(node.ap, int);
	node.buffer[node.pointer] = c;
	node.pointer += 1;
	return(node);
}