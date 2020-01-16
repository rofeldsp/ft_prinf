//
// Created by Rosanne Feldspar on 16/01/2020.
//

#include "ft_printf.h"

t_print 	parse_string(t_print node)
{
	char 	*str;
	int		i;

	i = 0;
	str = va_arg(node.ap, char *);
	while (str[i])
	{
//		if ((node.pointer + 1) % BUFF_SIZE == 0)
//			node.buffer = increase_buffer(&node.buffer, &node);
		node.buffer[node.pointer] = str[i];
		i++;
		node.pointer++;
	}
	return (node);
}

