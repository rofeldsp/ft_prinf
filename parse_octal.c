//
// Created by Rosanne Feldspar on 03/02/2020.
//

#include "ft_printf.h"

t_print 	parse_octal(t_print node, char c)
{
	char	*str;
	int		i;

//	node.unumber = va_arg(node.ap, unsigned int);
//	str = ft_itoa_base(node.unumber, 16, c);
	str = (node.size == H) ? ft_itoa_base((unsigned short)node.unumber, 8, c):
		  (node.size == HH ? ft_itoa_base((unsigned char)node.unumber, 8, c):
		   ft_itoa_base(node.unumber, 8 , 'a'));
	i = 0;
	node = adjust_to_width(node, (node.precision == -1 ? 0 : (node.flag & OCTO ? ft_strlen(str) + 1 : ft_strlen(str))));
	node = adjust_to_flag2(node, (node.precision == -1 ? 0 : (node.flag & OCTO ? ft_strlen(str) + 1 : ft_strlen(str))), c, str);
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
	node.pointer += node.empty_space;
	if (node.flag & OCTO)// && node.unumber != 0)
	{
//		node.buffer[node.pointer++] = '0';
		node.buffer[node.unumber == 0 ? node.pointer++ + 1 : node.pointer++] = '0';
		if (node.precision > 0)
			node.precision--;
		if (str[i] == '0')
			str[i] = '\0';
//		node.buffer[node.pointer++] = (c == 'F' ? 'X' : 'x');
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
