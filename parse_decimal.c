//
// Created by Rosanne Feldspar on 21/01/2020.
//

#include "ft_printf.h"

t_print 	parse_decimal(t_print node)
{
	char	*str;
	int		i;

	str = ft_itoa(va_arg(node.ap, int));
	i = 0;
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

int 	num_length(int num, t_print *node)
{
	int len;
	int num2;

	if (num < 0)
	{
		num = -num;
		len = 1;
	}
	num2 = num;
	while (num2 / 10 > 0)
	{
		num2 /= 10;
		len++;
	}
	return (len++);
}