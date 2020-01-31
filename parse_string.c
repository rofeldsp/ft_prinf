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
	if (str == NULL)
		str = "(null)";
	node = adjust_to_width(node, ft_strlen(str));
	node = adjust_to_flag(node, ft_strlen(str));
	node.pointer += node.empty_space;
	adjust_to_precision2(&node, &str);
//	if (node.precision >= 0 && node.width != (int)ft_strlen(str))
//		node.pointer += (node.width - ft_strlen(str));
	while (str[i])
	{
		if ((node.pointer + 1) % BUFF_SIZE == 0)
			node.buffer = increase_buffer(&node.buffer, &node);
		node.buffer[node.pointer] = str[i];
		i++;
		node.pointer++;
	}
	node.input++;
	if (node.flag & MINUS)
		node.pointer = node.end_of_field;
	return (node);
}

