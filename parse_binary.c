//
// Created by Rosanne Feldspar on 12/02/2020.
//

#include "ft_printf.h"

t_print 	parse_binary(t_print node, char c)
{
	char	*str;
	int		i;

//	node.unumber = va_arg(node.ap, unsigned int);
//	str = ft_itoa_base(node.unumber, 16, c);
	node.field_start = node.pointer;
	str = (node.size & H) ? ft_itoa_base((unsigned short)node.unumber, 2, c) :
		  (node.size & HH ? ft_itoa_base((unsigned char)node.unumber, 2, c) :
		   ft_itoa_base(node.unumber, 2, c));
	i = 0;
	node = adjust_to_width(node, (node.precision == -1 ? 0 : (node.flag & OCTO && node.unumber != 0 ? ft_strlen(str) + 2 : ft_strlen(str))));
	node = adjust_to_flag2(node, (node.precision == -1 ? 0 : (node.flag & OCTO && node.unumber != 0 ? ft_strlen(str) + 2 : ft_strlen(str))), c, str);
	if ((node.flag & SPACE) && (!(node.flag & PLUS)) && node.number >= 0)
	{
		check_overflow(&node);
		if (node.flag & ZERO)
		{
			node.buffer[node.pointer - node.empty_space] = ' ';
			node.empty_space = 0;
		}
		else
			node.buffer[node.pointer++] = ' ';
	}
	node.pointer += node.empty_space + (node.flag & OCTO && node.precision > 0 && node.empty_space != 0 && node.unumber != 0 && node.precision > (int)ft_strlen(str) ? 2 : 0);
	if (node.flag & OCTO && node.unumber != 0)
	{
		if (node.empty_space != 0 && node.precision > (int)ft_strlen(str))
		{
			node.buffer[node.pointer - (node.precision - ft_strlen(str)) - 2] = '0';
			node.buffer[node.pointer - (node.precision - ft_strlen(str)) - 1] = (c == 'f' ? 'x' : 'X');
		}
		else
		{
			node.buffer[node.pointer++] = '0';
			node.buffer[node.pointer++] = (c == 'f' ? 'x' : 'X');
		}
	}
	node = adjust_to_precision(node, ft_strlen(str), &str);
	while (str[i])
	{
		check_overflow(&node);
		node.buffer[node.pointer] = str[i];
		i++;
		node.pointer++;
	}
	node.input++;
	free(str);
	return (node);
}

t_print 	parse_string_binary(t_print node)
{
	char 	*str;
	int		i;

	i = 0;
	str = va_arg(node.ap, char *);
//	str = ft_strdup(str);
	if (str == NULL)
		str = "(null)";
	node = adjust_to_width2(node, ft_strlen(str));
	node = adjust_to_flag(node, ft_strlen(str));
	node.pointer += (node.empty_space > 0 ? node.empty_space : (node.width > node.precision && node.precision >= 0 && node.width != (int)ft_strlen(str) && node.flag ^ MINUS ? node.width - node.precision : 0));
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
	free(str);
	return (node);
}
