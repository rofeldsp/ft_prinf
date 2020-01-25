//
// Created by Rosanne Feldspar on 25/01/2020.
//

#include "ft_printf.h"

char 		*ft_itoa_base2(int i, char *str)
{
	char	*str2;
	int 	a;

	if ((str2 = ft_memalloc(i + 1)) == NULL)
		exit (-1);
	a = 0;
	i--;
	while (i >= 0)
		str2[a++] = str[i--];
	str2[a] = '\0';
	return(str2);
}

char 		*ft_itoa_base(int nb, int base)
{
	char 	*str;
	int 	i;
	char 	*hex;
	char 	*str2;

	hex = (char *)malloc(sizeof(char) * 17);
	hex = "0123456789abcdef";
	i = 0;
	if ((str = ft_memalloc(30)) == NULL)
		exit (-1);
	while (nb / base != 0)
	{
		str[i++] = hex[nb % base];
		nb /= base;
	}
	str[i++] = hex[nb % base];
	str[i] = '\0';
	if ((str2 = ft_memalloc(ft_strlen(str))) == NULL)
		exit (-1);
	return(ft_itoa_base2(i, str));
}

t_print 	parse_hexodecimal(t_print node)
{
	char	*str;
	int		i;

	node.number = va_arg(node.ap, unsigned int);
	str = ft_itoa_base(node.number, 16);
//	str = ft_itoa(node.number);
	i = 0;
	node = adjust_to_width(node, ft_strlen(str));
	node = adjust_to_flag2(node, ft_strlen(str));
	if ((node.flag & SPACE) && (!(node.flag & PLUS)) && node.number >= 0)
	{
		if (node.flag & ZERO)
		{
			node.buffer[node.pointer - node.empty_space] = ' ';
			node.empty_space = 0;
		}
		else
			node.buffer[node.pointer++] = ' ';
	}
	node.pointer += node.empty_space;
	node = adjust_to_precision(node, ft_strlen(str));
	while (str[i])
	{
		if ((node.pointer + 1) % BUFF_SIZE == 0)
			node.buffer = increase_buffer(&node.buffer, &node);
		node.buffer[node.pointer] = str[i];
		i++;
		node.pointer++;
	}
	node.input++;
	return (node);
}