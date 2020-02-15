//
// Created by Rosanne Feldspar on 16/01/2020.
//

#include "ft_printf.h"

t_print 	parse_string(t_print node)
{
	char 	*str;
//	char 	*str2;
	int		i;

	i = 0;
	str = va_arg(node.ap, char *);
	if (str == NULL)
		str = "(null)";
	node = adjust_to_width2(node, ft_strlen(str));
	node = adjust_to_flag(node, ft_strlen(str));
	node.pointer += (node.empty_space > 0 ? node.empty_space : (node.width > node.precision && node.precision >= 0 && node.width != (int)ft_strlen(str) && node.flag ^ MINUS ? node.width - node.precision : 0));
	adjust_to_precision2(&node, &str);
	while (str[i])
	{
		check_overflow(&node);
		node.buffer[node.pointer] = str[i];
		i++;
		node.pointer++;
	}
	node.input++;
	if (node.flag & MINUS)
		node.pointer = node.end_of_field;
	free(str);
	return (node);
}

