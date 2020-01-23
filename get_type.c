//
// Created by Rosanne Feldspar on 21/01/2020.
//

#include "ft_printf.h"

t_print		get_type(t_print node)
{
	if (*node.input == 'c')
		return(parse_char(node));
	else if (*node.input == 's')
		return(parse_string(node));
	else if (*node.input == 'd')
	{
		if (node.size & L)
			node.number = va_arg(node.ap, long int);
		else if (node.size & LL)
			node.number = va_arg(node.ap, long long int);
		else if (node.size & H)
			node.number = (short)va_arg(node.ap, int);
		else
			node.number = va_arg(node.ap, int);
	}
	return(parse_decimal(node));
}
