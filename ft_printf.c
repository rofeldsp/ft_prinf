/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofeldsp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 17:20:00 by rofeldsp          #+#    #+#             */
/*   Updated: 2019/12/26 17:20:02 by rofeldsp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf(const char *str, ...)
{
	t_print		node;
	int			i;

	node.pointer = 0;
	node.count_nulls = 0;
	node.empty_space = 0;
	node.buffer_size = BUFF_SIZE;
	if (!(node.buffer = ft_strnew(node.buffer_size)))
		exit(-1);
	va_start(node.ap, str);
	node.input = (char *)str;
	while (*node.input)
	{
		check_overflow(&node);
		if (*node.input == '%')
			node = print_arg(node);
		else if (*node.input != '{')
			node.buffer[node.pointer++] = *(node.input++);
		if (*node.input == '{')
			node = print_color(node);
	}
	va_end(node.ap);
	i = ft_putstr_printf(node.buffer, node.count_nulls);
	free(node.buffer);
	return (i);
}

int			ft_dprintf(int fd, const char *str, ...)
{
	t_print		node;
	int			i;

	node.pointer = 0;
	node.count_nulls = 0;
	node.empty_space = 0;
	node.buffer_size = BUFF_SIZE;
	if (!(node.buffer = ft_strnew(node.buffer_size)))
		exit(-1);
	va_start(node.ap, str);
	node.input = (char *)str;
	while (*node.input)
	{
		check_overflow(&node);
		if (*node.input == '%')
			node = print_arg(node);
		else if (*node.input != '{')
			node.buffer[node.pointer++] = *(node.input++);
		if (*node.input == '{')
			node = print_color(node);
	}
	va_end(node.ap);
	i = ft_putstr_dprintf(fd, node.buffer, node.count_nulls);
	free(node.buffer);
	return (i);
}

t_print		print_arg(t_print node)
{
	node.input++;
	if (*node.input == '%')
	{
		node.buffer[node.pointer++] = '%';
		node.input++;
		return (node);
	}
	free_flags(&node);
	node = get_flag(node);
	return (node);
}

void		check_overflow(t_print *node)
{
	int		i;

	i = 0;
	if (node->buffer_size - node->pointer < 100)
		node->buffer = increase_buffer(&node->buffer, node);
}

char		*increase_buffer(char **str, t_print *node)
{
	char	*dest;
	int		i;

	i = 0;
	if (!(dest = ft_strnew(node->buffer_size + BUFF_SIZE)))
		exit(-1);
	dest = ft_strcpy_special_edition(dest, *str);
	free(*str);
	node->buffer_size += BUFF_SIZE;
	return (dest);
}

void		free_flags(t_print *node)
{
	node->flag = '\0';
	node->size = 0;
	node->empty_space = 0;
	node->width = 0;
	node->precision = -2;
	node->number = 1;
	node->unumber = 1;
	node->end_of_field = 0;
	node->return_status = 0;
}

char		*ft_strcpy_special_edition(char *dest, const char *src)
{
	int		i;
	int		a;
	char	*s;

	a = 0;
	s = (char*)src;
	i = ft_strlen(s);
	while (a < i)
	{
		*(dest + a) = *(s + a);
		a++;
	}
	dest[a] = '\0';
	return (dest);
}
