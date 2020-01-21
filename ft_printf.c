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

void	ft_printf(const char *str, ...)
{
	t_print		node;

	node.pointer = 0;
//	if(!(node.buffer = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1))))
//		return ;
//	ft_bzero(node.buffer, BUFF_SIZE);
	node.flag = '\0';
	node.empty_space = 0;
	if(!(node.buffer = ft_memalloc(BUFF_SIZE)) && !(node.size = BUFF_SIZE))
		return ;
	va_start(node.ap, str);
	node.input = (char *)str;
	while (*node.input)
	{
		if ((node.pointer + 1) % BUFF_SIZE == 0)
			node.buffer = increase_buffer(&node.buffer, &node);
		if (*node.input == '%')
			node = print_arg(node);
		else
		{
			node.buffer[node.pointer] = *node.input;
			node.pointer++;
			node.input++;
		}
	}
	va_end(node.ap);
	ft_putstr(node.buffer);
	free(node.buffer);
}

t_print		print_arg(t_print node)
{
	node.input++;
	if (*node.input == '%')
	{
		node.buffer[node.pointer++] = '%';
		node.input ++;
		return (node);
	}
	node = get_flag(node);
	return(node);
}

char 		*increase_buffer(char **str, t_print *node)
{
	char	*dest;
	int 	i;

	i = 0;
	if(!(dest = ft_memalloc(ft_strlen(*str) + 1 + BUFF_SIZE)))
		exit(33);
	dest = ft_strcpy(dest, *str);
//	while (i < ft_strlen(*str))
//	{
//		dest[i] = *((*str) + i);
//		i++;
//	}
	free(*str);
	node->size += BUFF_SIZE;
	return(dest);
}
