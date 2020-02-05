//
// Created by Rosanne Feldspar on 16/01/2020.
//

#include "ft_printf.h"

t_print		parse_char(t_print node)
//{
//	char	c;
//
//	c = va_arg(node.ap, int);
//	node.buffer[node.pointer] = c;
//	node.pointer += 1;
//	node.input++;
//	return(node);
//}
{
	int		i;
	char	c;

	i = 0;
	c = va_arg(node.ap, int);
//	if (c == NULL)
//		c = '\0';
	node = adjust_to_width(node, 1);
	node = adjust_to_flag(node, 1);
	node.pointer += node.empty_space;
//	adjust_to_precision2(&node, &str);
//	if (node.precision >= 0 && node.width != (int)ft_strlen(str))
//		node.pointer += (node.width - ft_strlen(str));
//	while (str[i])
//	{
//		if ((node.pointer + 1) % BUFF_SIZE == 0)
//			node.buffer = increase_buffer(&node.buffer, &node);
//		node.buffer[node.pointer] = str[i];
//		i++;
//		node.pointer++;
//	}
//	node.input++;
//	if (node.flag & MINUS)
//		node.pointer = node.end_of_field;
	node.buffer[node.pointer++] = c;
	if (c == 0)
		node.count_nulls++;
	if (node.flag & MINUS)
	{
		if ((node.empty_space = (node.width > 1 ? node.width - 1 : 0)) != 0)
			node.pointer += node.empty_space;
	}
	node.input++;
	return (node);
}
