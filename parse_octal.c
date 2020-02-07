//
// Created by Rosanne Feldspar on 03/02/2020.
//

#include "ft_printf.h"

t_print 	parse_octal(t_print node, char c)
//{
//	char	*str;
//	int		i;
//
////	node.unumber = va_arg(node.ap, unsigned int);
////	str = ft_itoa_base(node.unumber, 16, c);
//	node.field_start = node.pointer;
//	str = (node.size & H) ? ft_itoa_base((unsigned short)node.unumber, 8, c) :
//		  (node.size & HH ? ft_itoa_base((unsigned char)node.unumber, 8, c) :
//		   ft_itoa_base(node.unumber, 8 , c));
//	i = 0;
//	node = adjust_to_width(node, (node.precision == -1 ? 0 : (node.flag & OCTO && node.unumber != 0 ? ft_strlen(str) + 1 : ft_strlen(str))));
//	node = adjust_to_flag2(node, (node.precision == -1 ? 0 : (node.flag & OCTO && node.unumber != 0 ? ft_strlen(str) + 1 : ft_strlen(str))), c, str);
//	if ((node.flag & SPACE) && (!(node.flag & PLUS)) && node.number >= 0)
//	{
//		check_overflow(&node);
//		if (node.flag & ZERO)
//		{
//			node.buffer[node.pointer - node.empty_space] = ' ';
//			node.empty_space = 0;
//		}
//		else
//			node.buffer[node.pointer++] = ' ';
//	}
//	node.pointer += node.empty_space - (node.flag & OCTO && node.precision > 0 && node.empty_space != 0 && node.unumber != 0 && node.precision > (int)ft_strlen(str) ? 1 : 0);
//	if (node.flag & OCTO)// && node.unumber != 0)
//	{
//		if (node.precision > 0 && node.empty_space != 0 && node.precision > (int)ft_strlen(str))
//		{
//			node.buffer[node.pointer - (node.precision - ft_strlen(str)) - 1] = '0';
////			node.buffer[node.pointer - (node.precision - ft_strlen(str)) - 1] = (c == 'f' ? 'x' : 'X');
//		}
//		else
//		{
//			node.buffer[node.pointer++] = '0';
////			node.buffer[node.pointer++] = (c == 'f' ? 'x' : 'X');
//		}
//	}
//	node = adjust_to_precision(node, ft_strlen(str), &str);
//	while (str[i])
//	{
//		check_overflow(&node);
//		node.buffer[node.pointer] = str[i];
//		i++;
//		node.pointer++;
//	}
//	node.input++;
//	free(str);
//	return (node);
//}
{
	char	*str;
	int		i;
//	int 	pointer_buf;

//	node.unumber = va_arg(node.ap, unsigned int);
//	str = ft_itoa_base(node.unumber, 16, c);
	node.field_start = node.pointer;
	str = (node.size & H) ? ft_itoa_base((unsigned short)node.unumber, 8, c):
		  (node.size & HH ? ft_itoa_base((unsigned char)node.unumber, 8, c):
		   ft_itoa_base(node.unumber, 8 , 'a'));
	i = 0;
	node = adjust_to_width(node, (node.precision == -1 ? 0 : (node.flag & OCTO ? ft_strlen(str) + 1 : ft_strlen(str))));
	node = adjust_to_flag2(node, (/*node.precision == -1 ? 0 : */(node.flag & OCTO ? ft_strlen(str) + 1 : ft_strlen(str))), c, str);
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
//	node.pointer += (node.flag & OCTO ? node.empty_space - 1 : node.empty_space);
	node.pointer += node.empty_space;
	if (node.unumber == 0 && node.width > (int)ft_strlen(str) + 1 && !(node.flag & MINUS) && (node.flag & ZERO) && str[i] == '0')
		node.buffer[node.pointer] = '0';
	if (node.flag & OCTO)// && node.unumber != 0)
	{
//		node.buffer[node.pointer++] = '0';
		node.buffer[node.unumber == 0 && node.width > (int)ft_strlen(str) + 1 && !(node.flag & MINUS) ? node.pointer++ + 1 : node.pointer++] = '0';
		if ((node.precision > 0 && node.pointer == node.field_start + 1) || node.unumber == 0)
//		if ((node.end_of_field - (node.pointer - 1) - ft_strlen(str)) == node.precision)
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
	if (node.buffer[node.pointer] != '\0')
		node.pointer++;
	free(str);
	return (node);
}
