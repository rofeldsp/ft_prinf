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
	node = adjust_to_width(node, ft_strlen(str));
	node = adjust_to_flag(node, ft_strlen(str));
	while (str[i])
	{
		if ((node.pointer + 1) % BUFF_SIZE == 0)
			node.buffer = increase_buffer(&node.buffer, &node);
		node.buffer[node.pointer] = str[i];
		i++;
		node.pointer++;
	}
	node.input++;
	node.pointer += node.empty_space;
	return (node);
}

