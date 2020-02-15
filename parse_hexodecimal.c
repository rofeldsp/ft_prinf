//
// Created by Rosanne Feldspar on 25/01/2020.
//

#include "ft_printf.h"

char 		*ft_itoa_base2(int i, char **str)
{
	char	*str2;
	int 	a;

	if ((str2 = ft_memalloc(i + 1)) == NULL)
		exit (-1);
	a = 0;
	i--;
	while (i >= 0)
		str2[a++] = *(*str + (i--));
	str2[a] = '\0';
	free(*str);
	return(str2);
}

char 		*ft_itoa_base(__uint64_t nb, int base, char c)
{
	char 	*str;
	int 	i;
	char 	*hex;

	if (c == 'F')
		hex = "0123456789ABCDEF";
	else
		hex = "0123456789abcdef";
	i = 0;
	if ((str = ft_memalloc(60)) == NULL)
		exit (-1);
	while (nb / base != 0)
	{
		str[i++] = hex[nb % base];
		nb /= base;
	}
	str[i++] = hex[nb % base];
	str[i] = '\0';
	return(ft_itoa_base2(i, &str));
}

t_print 	parse_hexodecimal(t_print node, char c)
{
	char	*str;
	int		i;

	node.unumber = (node.size & L) ? va_arg(node.ap, unsigned long int) :
				   ((node.size & LL) ? va_arg(node.ap, unsigned long long int) :
					va_arg(node.ap, unsigned int));
	node.field_start = node.pointer;
	str = (node.size & H) ? ft_itoa_base((unsigned short)node.unumber, 16, c) :
			(node.size & HH ? ft_itoa_base((unsigned char)node.unumber, 16, c) :
			ft_itoa_base(node.unumber, 16 , c));
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
		node.buffer[node.pointer++] = str[i];
		i++;
	}
	node.input++;
	free(str);
	return (node);
}
