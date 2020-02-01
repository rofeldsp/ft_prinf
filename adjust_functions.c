//
// Created by Rosanne Feldspar on 22/01/2020.
//

#include "ft_printf.h"

t_print		adjust_to_width(t_print node, int len)
{
	int len2;

	if (node.width == -1 || node.precision > node.width)
		node.width = len;
	len2 = node.width;
	node.end_of_field = node.pointer + node.width;
	if (node.width <= len)
		return (node);
//	if ((node.pointer + node.width) >= 100 || (node.pointer + node.width) % 100
//											  < node.pointer % 100)
//		node.buffer = increase_buffer(&node.buffer, &node);
	while (len2 > 0)
	{
		check_overflow(&node);
		node.buffer[node.pointer + len2 - 1] = ' ';
		len2--;
	}
	return(node);
}

t_print 	adjust_to_flag(t_print node, int len)
{
	int	len_width;

	node.empty_space = node.width - len;
	len_width = node.empty_space;
	if (node.flag & MINUS)
		node.empty_space = 0;
	if (node.flag & ZERO)
		while (len_width-- > 0)
		{
			check_overflow(&node);
			node.buffer[node.pointer++] = '0';
		}
	return (node);
}

t_print 	adjust_to_flag2(t_print node, int len, char c, char *str)
{
	int	len_width;
//	int buf;

//	len_width = node.width;
	node.empty_space = (node.width > len) ? node.width - len : 0;
	if (node.flag & MINUS)
		node.empty_space = 0;
	len_width = node.empty_space;
	if (str[0] == '-')
	{
		len_width++; // поменял на --
//		node.pointer++;
	}
	if (node.flag & ZERO && node.precision < 0)
	{
		if (node.flag & OCTO && node.unumber != 0)
		{
			node.buffer[node.pointer++] = '0';
			node.buffer[node.pointer++] = (c == 'f' ? 'x' : 'X');
			node.flag ^= OCTO;
		}
//		buf = node.pointer;
		while (len_width-- > 0)
		{
			check_overflow(&node);
			node.buffer[node.pointer++] = '0';
		}
//		node.pointer = buf;
		node.empty_space = 0;
	}
//	if (node.flag & PLUS)
//	{
//		if (node.number >= 0)
//		{
//			if (node.flag & ZERO)
//				node.buffer[node.field_start] = '+';
//			else
//				node.buffer[node.pointer++] = '+';
//		}
//	}
//	if ((node.flag & SPACE) && (!(node.flag & PLUS)))
//		while (len_width-- > len)
//			node.buffer[node.pointer++] = ' ';
	return (node);
}

t_print 	adjust_to_precision(t_print node, int len, char **str)
{
	int	pointer_buff;

	if (node.precision == -1 && (node.unumber == 0 || node.number == 0))
		*(str[0]) = '\0';
	if (node.precision < node.width && ((node.flag & MINUS) != MINUS) && node.precision >= 0)
	{
		pointer_buff = node.pointer;
		while ((node.precision--) - len > 0)
		{
			if ((node.pointer + 1) % BUFF_SIZE == 1)
				node.buffer = increase_buffer(&node.buffer, &node);
			node.buffer[--node.pointer] = '0';
		}
		if (node.flag & PLUS)
		{
			if (node.number >= 0)
			{
				if (node.flag & ZERO)
					node.buffer[node.field_start] = '+';
				else
					node.buffer[--node.pointer] = '+';
			}
		}
		node.pointer = pointer_buff;
	}
	else
	{
		if (node.flag & PLUS)
		{
			if (node.number >= 0)
			{
				if (node.flag & ZERO)
					node.buffer[node.field_start] = '+';
				else
					node.buffer[node.pointer++] = '+';
			}
		}
		while ((node.precision--) - len > 0)
		{
			if ((node.pointer + 1) % BUFF_SIZE == 1)
				node.buffer = increase_buffer(&node.buffer, &node);
			node.buffer[node.pointer++] = '0';
		}
	}
	return (node);
}

void	 	adjust_to_precision2(t_print *node, char **str)
{
	int 	len;
	char 	*str2;

	if (node->precision > -2)
	{
		len = ft_strlen(*str);
		str2 = ft_strdup(*str);
		if (node->precision == -1)
		{
			str2[0] = '\0';
			return ;
		}
		while (len > node->precision && len - 1 >= 0)
		{
			len--;
			str2[len] = '\0';
		}
		if (ft_strlen(*str) != ft_strlen(str2) && node->width != (int)ft_strlen(*str) && node->flag ^ MINUS)
			node->pointer += ft_strlen(*str) - ft_strlen(str2);
		if (node->width == (int)ft_strlen(*str))
			node->end_of_field -= (ft_strlen(*str) - ft_strlen(str2));
		*str = str2;
		free(str2);
	}
}
