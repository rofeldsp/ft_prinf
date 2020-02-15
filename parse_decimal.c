//
// Created by Rosanne Feldspar on 21/01/2020.
//

#include "ft_printf.h"

t_print 	parse_decimal(t_print node)
{
	char	*str;
	int		i;
	int 	pointer_buf;

	node.number = (node.size & L) ? va_arg(node.ap, long int) :
				  ((node.size & LL) ? va_arg(node.ap, long long int) :
				   va_arg(node.ap, int));
	node.field_start = node.pointer;
	if (!(str = (node.size == H) ? ft_itoa((short)node.number) : (node.size == HH ?
			ft_itoa((char)node.number) : ft_itoa(node.number))))
		exit (-1);
	i = 0;
	node = adjust_to_width(node, (node.precision == -1 ? 0 : ft_strlen(str)));
	node = adjust_to_flag2(node, (node.precision == -1 ? 0 : ft_strlen(str)), '0', str);
	if ((node.flag & ZERO && node.number < 0 && node.precision == -2))// || /)
	{
		node.buffer[node.field_start] = '-';
		str = ft_strcpy(str, &(str[1]));
		if (node.pointer == node.field_start)
			node.pointer++;
	}
	else if (node.number < 0 && node.precision >= 0 && !(node.size & HH) && !(node.size & H))
	{
		str = ft_strcpy(str, &(str[1]));
		node.pointer++;
	}
	node.pointer += node.empty_space;
	node.pointer -= (node.empty_space != 0 && (node.flag & PLUS) != 0 && node.precision < 0) ? 1 : 0;
	if ((node.flag & SPACE) && (!(node.flag & PLUS)) && node.number >= 0)
	{
		if (node.pointer == node.field_start)
			node.buffer[node.pointer++] = ' ';
		else
		{
			if (node.flag & ZERO)
			{
					node.buffer[node.field_start] = ' ';
					node.empty_space = 0;
			}
			else
					node.buffer[node.pointer - 1] = ' ';
		}
	}
	node = adjust_to_precision(node, ft_strlen(str), &str);
	if (node.number < 0 && node.precision >= 0 && !(node.size & HH) && !(node.size & H) && !(node.size & ZERO))
	{
		pointer_buf = node.pointer - 1;
		while (node.buffer[pointer_buf] != ' ' && node.buffer[pointer_buf] != '\0')
			pointer_buf--;
		node.buffer[pointer_buf] = '-';
	}
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
	free(str);
	return (node);
}

