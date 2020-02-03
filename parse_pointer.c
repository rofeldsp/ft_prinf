//
// Created by Rosanne Feldspar on 03/02/2020.
//

#include "ft_printf.h"

t_print		parse_pointer(t_print node)
{
	void	*pointer;

	pointer = va_arg(node.ap, void *);
	ft_putstr(pointer);
	return (node);
}
