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

//	if (!(hex = (char *)malloc(sizeof(char) * 17)))
//		exit(-1);
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
//	free(hex);
	return(ft_itoa_base2(i, &str));
}

//char 		*llft_itoa_base(long long int nb, int base, char c)
//{
//	char 	*str;
//	int 	i;
//	char 	*hex;
//
////	if (!(hex = (char *)malloc(sizeof(char) * 17)))
////		exit(-1);
//	if (c == 'f')
//		hex = "0123456789abcdef";
//	else
//		hex = "0123456789ABCDEF";
//	i = 0;
//	if ((str = ft_memalloc(60)) == NULL)
//		exit (-1);
//	while (nb / base != 0)
//	{
//		str[i++] = hex[nb % base];
//		nb /= base;
//	}
//	str[i++] = hex[nb % base];
//	str[i] = '\0';
////	free(hex);
//	return(ft_itoa_base2(i, &str));
//}

t_print 	parse_hexodecimal(t_print node, char c)
{
	char	*str;
	int		i;

//	node.unumber = va_arg(node.ap, unsigned int);
//	str = ft_itoa_base(node.unumber, 16, c);
	node.field_start = node.pointer;
	str = (node.size == H) ? ft_itoa_base((unsigned short)node.unumber, 16, c) :
			(node.size == HH ? ft_itoa_base((unsigned char)node.unumber, 16, c) :
			ft_itoa_base(node.unumber, 16 , c));
	i = 0;
	node = adjust_to_width(node, (node.precision == -1 ? 0 : (node.flag & OCTO ? ft_strlen(str) + 2 : ft_strlen(str))));
	node = adjust_to_flag2(node, (node.precision == -1 ? 0 : (node.flag & OCTO ? ft_strlen(str) + 2 : ft_strlen(str))), c, str);
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
	if (node.flag & OCTO && node.unumber != 0)
	{
		node.buffer[node.pointer++] = '0';
		node.buffer[node.pointer++] = (c == 'f' ? 'x' : 'X');
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
/*
t_print 	lparse_hexodecimal(t_print node, char c)
{
	char	*str;
	int		i;

	node.lnumber = va_arg(node.ap, long int);
	str = llft_itoa_base(node.lnumber, 16, c);
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
	free(str);
	return (node);
}

t_print 	llparse_hexodecimal(t_print node, char c)
{
	char	*str;
	int		i;

	node.llnumber = va_arg(node.ap, long long int);
	str = llft_itoa_base(node.llnumber, 16, c);
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
	free(str);
	return (node);
}  */
