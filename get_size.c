//
// Created by Rosanne Feldspar on 20/01/2020.
//

#include "ft_printf.h"

t_print		get_size(t_print node)
{
	node.size = 0;
	if (*node.input == 'h' || *node.input == 'l' || *node.input == 'L')
	{
		return (get_type(node));
	}
	return(get_type(node));
}