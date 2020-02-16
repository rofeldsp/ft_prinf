/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofeldsp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 19:42:50 by rofeldsp          #+#    #+#             */
/*   Updated: 2020/02/15 19:42:52 by rofeldsp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		parse_float8(t_print *node, __int64_t *num, char **str)
{
	if (node->flag & ZERO && !(node->flag & MINUS))
	{
		if (*num < 0 || node->flag & PLUS)
		{
			node->buffer[node->field_start] = *num < 0 ? '-' : '+';
			*str = ft_strcpy(*str, &((*str)[*num < 0 ? 1 : 0]));
			node->empty_space -= *num < 0 ? 0 : 1;
			node->pointer += *num < 0 ? 1 : 0;
			node->field_start++;
		}
		while (node->field_start < node->pointer)
			node->buffer[node->field_start++] = '0';
	}
}

void		parse_float7(t_print *node, __int64_t *num, char **str)
{
	if (node->flag & PLUS && *num >= 0)
	{
		if (node->flag & ZERO && node->width > (int)ft_strlen(*str))
		{
			if (node->pointer == node->field_start)
				node->buffer[node->pointer++] = '+';
			else
				node->buffer[node->field_start] = '+';
		}
		else
			node->buffer[node->pointer > node->field_start ? node->pointer - 1
												: node->pointer++] = '+';
	}
	if (node->flag & MINUS)
		node->pointer = node->field_start + node->flag & PLUS
											&& *num >= 0 ? 1 : 0;
}

void		parse_float6(t_print *node, __int64_t *num)
{
	if ((node->flag & SPACE) && (!(node->flag & PLUS)) && *num >= 0)
	{
		if (node->pointer == node->field_start)
		{
			node->buffer[node->pointer++] = ' ';
			node->field_start++;
		}
		else
		{
			if (node->flag & ZERO)
			{
				node->buffer[node->field_start] = ' ';
				node->empty_space = 0;
				node->field_start++;
			}
			else
				node->buffer[node->pointer - 1] = ' ';
		}
	}
}

void		parse_float5(t_print *node, __int64_t *num, char **str)
{
	if ((node->flag & ZERO && *num < 0 && node->precision == -2))
	{
		node->buffer[node->field_start] = '-';
		*str = ft_strcpy(*str, &((*str)[1]));
		if (node->pointer == node->field_start)
			node->pointer++;
	}
	else if (node->number < 0 && node->precision >= 0 && !(node->size & HH)
											&& !(node->size & H))
	{
		*str = ft_strcpy(*str, &((*str)[1]));
		node->pointer++;
	}
	node->pointer += node->empty_space;
}

void		parse_float4(t_print *node, char **tmp, char **str, char **str2)
{
	if (node->precision > 0 || (node->flag & OCTO))
	{
		if (!(*tmp = ft_strjoin(*str, ".")))
			exit(-1);
		free(*str);
		if (!(*str = ft_strjoin(*tmp, *str2)))
			exit(-1);
		free(*tmp);
		free(*str2);
	}
}

char		*float_cut(__int64_t *num, t_print *node)
{
	char	*tmp;
	int		a;
	int		sign;
	char	*str2;
	char	*str;

	a = 0;
	sign = node->fnumber < 0 ? -1 : 1;
	node->fnumber *= node->fnumber < 0 ? -1 : 1;
	str2 = parse_float2(node, &a);
	parse_float3(num, &str2, &a);
	if (*num == 0 && sign == -1)
	{
		tmp = ft_itoa(*num);
		if (!(str = ft_strjoin("-", tmp)))
			exit(-1);
		free(tmp);
	}
	else if (!(str = ft_itoa(*num)))
		exit(-1);
	parse_float4(node, &tmp, &str, &str2);
	*node = adjust_to_width(*node, (ft_strlen(str)));
	*node = adjust_to_flag3(*node, (ft_strlen(str)), str);
	parse_float5(node, num, &str);
	return (str);
}

void		parse_float3(__int64_t *num, char **str2, int *a)
{
	int b;

	b = *a - 1;
	if (*a == 0)
		*a = 1;
	if ((*str2)[--(*a)] >= '5')
	{
		(*a)--;
		if (*a >= 0)
			(*str2)[*a]++;
		else
			*num += *num > 0 ? 1 : -1;
		while (*a >= 0)
		{
			if ((*str2)[*a] > '9')
			{
				if (*a == 0)
					*num += *num > 0 ? 1 : -1;
				(*str2)[*a - 1] += (*str2)[*a] - '9';
				(*str2)[*a] = '0';
			}
			(*a)--;
		}
	}
	(*str2)[b] = '\0';
}

char		*parse_float2(t_print *node, int *a)
{
	int			pres;
	int			last_char;
	uint64_t	floatnbr;
	int			pres2;
	char		*str2;

	pres = node->precision != -1 ? node->precision : 0;
	str2 = ft_strnew(pres + 1);
	while (pres >= 0)
	{
		if (pres > 18)
			pres2 = 18;
		else
			pres2 = pres;
		floatnbr = node->fnumber * ft_power(10, pres2 + 1);
		node->fnumber *= ft_power(10, pres2 + 1);
		node->fnumber -= (uint64_t)node->fnumber;
		*a += pres2 + 1;
		last_char = *a - 1;
		while (pres2-- >= 0)
		{
			str2[last_char--] = floatnbr % 10 + '0';
			floatnbr /= 10;
		}
		pres = pres > 18 ? (pres - 18 - 1) : pres2;
	}
	return (str2);
}

t_print		parse_float(t_print node)
{
	char		*str;
	int			i;
	__int64_t	num;

	num = (__int64_t)node.fnumber;
	node.fnumber -= num;
	node.precision = node.precision == -2 ? 6 : node.precision;
	node.field_start = node.pointer;
	str = float_cut(&num, &node);
	parse_float6(&node, &num);
	parse_float7(&node, &num, &str);
	parse_float8(&node, &num, &str);
	i = 0;
	while (str[i])
	{
		check_overflow(&node);
		node.buffer[node.pointer++] = str[i++];
	}
	node.input++;
	free(str);
	return (node);
}

__uint64_t	ft_power(int base, int power)
{
	__uint64_t	res;
	int			i;

	i = 1;
	res = base;
	while (i++ < power)
		res = res * base;
	return (res);
}
