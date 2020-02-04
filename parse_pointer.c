//
// Created by Rosanne Feldspar on 03/02/2020.
//

#include "ft_printf.h"

t_print		parse_pointer(t_print node)
{
	void	*pointer;
	char 	*str;
	int 	i;

	pointer = va_arg(node.ap, void *);
	str = ft_itoa_base((uint64_t)pointer, 16, 'a');
	node = adjust_to_width(node, (node.precision == -1 ? 0 : (node.flag & OCTO ? ft_strlen(str) + 2 : ft_strlen(str))));
	node = adjust_to_flag2(node, (node.precision == -1 ? 0 : (node.flag & OCTO ? ft_strlen(str) + 2 : ft_strlen(str))), 'a', str);
//	node.empty_space = (node.width > ft_strlen(str) ? node.width - ft_strlen(str) + 2 : 0);
	i = 0;
	if (node.empty_space != 0)
		node.pointer += node.empty_space - 2;
	node.buffer[node.pointer++] = '0';
	node.buffer[node.pointer++] = 'x';
	adjust_to_precision2(&node, &str);
	while (str[i])
		node.buffer[node.pointer++] = str[i++];
	if (node.flag & MINUS)
	{
		if ((node.empty_space = (node.width > (int)ft_strlen(str) + 2 ? node.width - ft_strlen(str) - 2 : 0)) != 0)
			node.pointer += node.empty_space;
	}
	node.input++;
	return (node);
}
