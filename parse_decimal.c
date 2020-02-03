//
// Created by Rosanne Feldspar on 21/01/2020.
//

#include "ft_printf.h"

t_print 	parse_decimal(t_print node)
{
	char	*str;
	int		i;

//	node.number = va_arg(node.ap, int);
	node.field_start = node.pointer;
	str = (node.size == H) ? ft_itoa((short)node.number) : (node.size == HH ?
			ft_itoa((char)node.number) : ft_itoa(node.number));
	i = 0;
	node = adjust_to_width(node, (node.precision == -1 ? 0 : ft_strlen(str)));
	node = adjust_to_flag2(node, (node.precision == -1 ? 0 : ft_strlen(str)), '0', str);
	if ((node.flag & ZERO && node.number < 0) || (node.number < 0 && node.precision >= 0 && !(node.flag & HH) && !(node.flag & H)))
	{
		node.buffer[node.field_start] = '-';
		str = ft_strcpy(str, &(str[1]));
		if (node.pointer == node.field_start)
			node.pointer++;
	}
	node.pointer += node.empty_space;
	if ((node.flag & SPACE) && (!(node.flag & PLUS)) && node.number >= 0)
	{
		if (node.flag & ZERO)
		{
			node.buffer[node.pointer - node.empty_space] = ' ';
			node.empty_space = 0;
		}
		else
		{
			if (node.pointer == node.field_start)
				node.buffer[node.pointer++] = ' ';
			else
				node.buffer[node.pointer - 1] = ' ';
		}
	}
//	node.pointer += node.empty_space;
	node = adjust_to_precision(node, ft_strlen(str), &str);
	while (str[i])
	{
		if ((node.pointer + 1) % BUFF_SIZE == 0)
			node.buffer = increase_buffer(&node.buffer, &node);
		node.buffer[node.pointer] = str[i];
		i++;
		node.pointer++;
	}
	if (node.flag & MINUS)
	{
		if ((node.empty_space = (node.width > (int)ft_strlen(str) ? node.width - ft_strlen(str) : 0)) != 0)
			node.pointer += node.empty_space;
	}
	node.input++;
	return (node);

	/*int num;
	int len;
	int sign;

	sign = 0;
	num = va_arg(node.ap, int);
	len = num_length(num, &node);
	if (num < 0)
	{
		num = -num;
		sign = 1;
	}
	node = adjust_to_width(node, len);
	node = adjust_to_flag(node, len);
	if ((node.pointer + 1) % BUFF_SIZE == 0)
		node.buffer = increase_buffer(&node.buffer, &node);
	if (sign = 1)
		node.buffer[node.pointer++] = '-';
	while (num / 10 > 0)
	{
		if ((node.pointer + 1) % BUFF_SIZE == 0)
			node.buffer = increase_buffer(&node.buffer, &node);
		node.buffer[node.pointer++] = num % 10;

	}
	*/
}

