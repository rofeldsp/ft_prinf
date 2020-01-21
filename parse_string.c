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

t_print		adjust_to_width(t_print node, int len)
{
	int len2;

	len2 = node.width;
	if (node.width <= len)
		return (node);
	if ((node.pointer + node.width) >= 100 || (node.pointer + node.width) % 100
		< node.pointer % 100)
		node.buffer = increase_buffer(&node.buffer, &node);
	while (len2 >= 0)
	{
		node.buffer[node.pointer + len2] = ' ';
		len2--;
	}
	return(node);
}

t_print 	adjust_to_flag(t_print node, int len)
{
	int	len_width;

	len_width = node.width;
	if (node.flag == '0')
	{
		while (len_width-- > len)
			node.buffer[node.pointer++] = '0';
	}
	node.empty_space = node.width - len;
	return (node);
}
