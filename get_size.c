//
// Created by Rosanne Feldspar on 20/01/2020.
//

#include "ft_printf.h"

t_print		get_size(t_print node)
{
	node.size = 0;
	if (*node.input == 'l' || *node.input == 'h')
	{
		if (*node.input == 'l') {
			if (*(node.input + 1) == 'l') {
				node.size |= LL;
				node.input++;
			} else
				node.size |= L;
		}
		if (*node.input == 'h') {
			if (*(node.input + 1) == 'h') {
				node.size |= HH;
				node.input++;
			} else
				node.size |= H;
		}
		node.input++;
	}
//	(*(node.input + 1) == 'l') ? (node.size = LL) : (node.size = L);
//	if (*node.input == 'h')
//		(*(node.input + 1) == 'h') ? (node.size = HH) : (node.size = H);
	return(get_type(node));
}