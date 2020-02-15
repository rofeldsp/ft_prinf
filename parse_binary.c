/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_binary.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofeldsp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 15:01:24 by rofeldsp          #+#    #+#             */
/*   Updated: 2020/02/15 15:01:26 by rofeldsp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			parse_binary2(t_print *node, char c, char *str)
{
	int len;

	if (node->precision != -1)
		len = (node->flag & OCTO && node->unumber != 0 ? ft_strlen(str) + 2
		: ft_strlen(str));
	*node = adjust_to_width(*node, (node->precision == -1 ? 0 : len));
	*node = adjust_to_flag2(*node, (node->precision == -1 ? 0 : len), c, str);
	if ((node->flag & SPACE) && (!(node->flag & PLUS)) && node->number >= 0)
	{
		check_overflow(node);
		if (node->flag & ZERO)
		{
			node->buffer[node->pointer - node->empty_space] = ' ';
			node->empty_space = 0;
		}
		else
			node->buffer[node->pointer++] = ' ';
	}
	node->pointer += node->empty_space + (node->flag & OCTO && node->precision >
			0 && node->empty_space != 0 && node->unumber != 0 &&
			node->precision > (int)ft_strlen(str) ? 2 : 0);
}

t_print			parse_binary(t_print node, char c)
{
	char	*str;
	int		i;

	node.field_start = node.pointer;
	if (node.size & H)
		str = ft_itoa_base((unsigned short)node.unumber, 2, c);
	else
		str = (node.size & HH ? ft_itoa_base((unsigned char)node.unumber, 2, c)
				: ft_itoa_base(node.unumber, 2, c));
	i = 0;
	parse_binary2(&node, c, str);
	if (node.flag & OCTO && node.unumber != 0)
	{
		if (node.empty_space != 0 && node.precision > (int)ft_strlen(str))
		{
			node.buffer[node.pointer - (node.precision - ft_strlen(str)) - 2]
																		= '0';
			node.buffer[node.pointer - (node.precision - ft_strlen(str)) - 1]
													= (c == 'f' ? 'x' : 'X');
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

void		parse_bits(void *nbr, int size, t_print *node)
{
	unsigned char	*c;
	int 			bit;

	c = (unsigned char *)nbr + size;
	while (--c >= (unsigned char *)nbr)
	{
		bit = 128;
		while (bit >= 1)
		{
			node->buffer[node->pointer] = '0';
			if (*c & bit)
				node->buffer[node->pointer] = '1';
			node->pointer++;
			if ((bit >>= 1) == 8 || (bit == 0 && c != (unsigned char *)nbr))
				node->buffer[node->pointer++] = ' ';
		}
	}
	node->input += (*(node->input + 1) == 'f' ? 2 : 1);
}

t_print			parse_string_binary(t_print node)
{
	long double a;
	double		c;
	int64_t		b;

	if ((*node.input + 1) == 'f')
		a = va_arg(node.ap, long double);
	else
		b = va_arg(node.ap, int64_t);
	if ((*node.input + 1) == 'f' && node.size & FLOAT_L)
		parse_bits(&a, 10, &node);
	else if ((*node.input + 1) == 'f')
	{
		c = (double)a;
		parse_bits(&c, sizeof(double), &node);
	}
	else if (node.size & H)
		parse_bits(&b, sizeof(short), &node);
	else if (node.size & HH)
		parse_bits(&b, sizeof(char), &node);
	else if (node.size & L || node.size & LL)
		parse_bits(&b, sizeof(int64_t), &node);
	else
		parse_bits(&b, sizeof(int), &node);
	return (node);
}
