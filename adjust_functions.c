/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adjust_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofeldsp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 11:55:32 by rofeldsp          #+#    #+#             */
/*   Updated: 2020/02/17 11:55:33 by rofeldsp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	while (len2 > 0)
	{
		check_overflow(&node);
		node.buffer[node.pointer + node.width - len2] = ' ';
		len2--;
	}
	return (node);
}

t_print		adjust_to_width2(t_print node, int len)
{
	int len2;
	int width_buf;

	width_buf = node.width;
	if (node.width == -1)
		node.width = len;
	len2 = node.width;
	node.end_of_field = node.pointer + node.width;
	if (width_buf <= 0)
		return (node);
	while (len2 > 0)
	{
		check_overflow(&node);
		node.buffer[node.pointer + node.width - len2] = ' ';
		len2--;
	}
	return (node);
}

t_print		adjust_to_flag(t_print node, int len)
{
	int	len_width;

	node.empty_space = (node.width > len) ? node.width - len : 0;
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

t_print		adjust_to_flag2(t_print node, int len, char c, char *str)
{
	int	len_width;

	node.empty_space = (node.width > len) ? node.width - len : 0;
	if (node.flag & MINUS)
		node.empty_space = 0;
	len_width = node.empty_space;
	if (str[0] == '-')
		len_width++;
	if (node.flag & ZERO && node.precision < 0)
	{
		if (node.flag & OCTO && node.unumber != 0 && (c == 'F' || c == 'f'))
		{
			node.buffer[node.pointer++] = '0';
			node.buffer[node.pointer++] = (c == 'F' ? 'X' : 'x');
			node.flag ^= OCTO;
		}
		while (len_width-- > 0)
		{
			check_overflow(&node);
			node.buffer[node.pointer++] = '0';
		}
		node.empty_space = 0;
	}
	return (node);
}

t_print		adjust_to_flag3(t_print node, int len, char *str)
{
	int	len_width;

	node.empty_space = (node.width > len) ? node.width - len : 0;
	if (node.flag & MINUS)
		node.empty_space = 0;
	len_width = node.empty_space;
	if (str[0] == '-')
	{
		len_width++;
	}
	return (node);
}

void		adjust_to_precision_3(t_print *node, int len)
{
	if (node->flag & PLUS)
	{
		if (node->number >= 0)
		{
			if (node->flag & ZERO && node->width > len)
			{
				if (node->pointer == node->field_start)
					node->buffer[node->pointer++] = '+';
				else
					node->buffer[node->field_start] = '+';
			}
			else
				node->buffer[node->pointer++] = '+';
		}
	}
	if (node->pointer != node->field_start &&
										node->buffer[node->pointer - 1] == '\0')
		node->buffer[node->pointer - 1] = ' ';
	while ((node->precision--) - len > 0)
	{
		check_overflow(node);
		node->buffer[node->pointer++] = '0';
	}
}

void		adjust_to_precision_2(t_print *node, int len)
{
	int		pointer_buff;

	pointer_buff = node->pointer;
	while ((node->precision--) - len > 0)
	{
		check_overflow(node);
		node->buffer[--node->pointer] = '0';
	}
	if (node->flag & PLUS)
	{
		if (node->number >= 0)
		{
			if (node->pointer == node->field_start)
				node->buffer[pointer_buff++] = '+';
			else
				node->buffer[--node->pointer] = '+';
		}
	}
	node->pointer = pointer_buff;
}

t_print		adjust_to_precision(t_print node, int len, char **str)
{
	if (node.precision == -1 && (node.unumber == 0 || node.number == 0))
		*(str[0]) = '\0';
	if (node.precision < node.width && ((node.flag & MINUS) != MINUS) &&
													node.precision >= 0)
		adjust_to_precision_2(&node, len);
	else
		adjust_to_precision_3(&node, len);
	return (node);
}

void		adjust_to_precision_v2_2(t_print *node, char **str, char **str2)
{
	if (ft_strlen(*str) != ft_strlen(*str2) && node->width >
								(int)ft_strlen(*str) && node->flag ^ MINUS)
		node->pointer += ft_strlen(*str) - ft_strlen(*str2);
	if (node->width == (int)ft_strlen(*str))
		node->end_of_field -= (ft_strlen(*str) - ft_strlen(*str2));
	if (!(*str = ft_strdup(*str2)))
		exit(-1);
}

void		adjust_to_precision_v2(t_print *node, char **str)
{
	int		len;
	char	*str2;

	if (node->precision > -2)
	{
		len = ft_strlen(*str);
		if (!(str2 = ft_strdup(*str)))
			exit(-1);
		if (node->precision == -1)
		{
			str2[0] = '\0';
			if (!(*str = ft_strdup(str2)))
				exit(-1);
			free(str2);
			return ;
		}
		while (len > node->precision && len - 1 >= 0)
			str2[--len] = '\0';
		adjust_to_precision_v2_2(node, str, &str2);
		free(str2);
	}
	else if (!(*str = ft_strdup(*str)))
		exit(-1);
}

void		adjust_to_precision_v3_2(t_print *node, int len)
{
	int pointer_buff;

	pointer_buff = node->pointer;
	while ((node->precision--) - len > 0)
	{
		if ((node->pointer + 1) % BUFF_SIZE == 1)
			node->buffer = increase_buffer(&node->buffer, node);
		node->buffer[--node->pointer] = '0';
	}
	node->pointer = pointer_buff;
}

t_print		adjust_to_precision_v3(t_print node, int len, char **str)
{
	if (node.precision == -1 && ((node.unumber == 0 || node.number == 0) ||
									(node.number == 1 && node.unumber == 1)))
		(*str)[0] = '\0';
	if (node.precision < node.width && ((node.flag & MINUS) != MINUS) &&
														node.precision >= 0)
		adjust_to_precision_v3_2(&node, len);
	else
	{
		while ((node.precision--) - len > 0)
		{
			check_overflow(&node);
			node.buffer[node.pointer++] = '0';
		}
	}
	return (node);
}
