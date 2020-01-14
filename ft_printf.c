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

	va_start(node.ap, str);
	node.input = (char *)str;
	while (*node.input)
	{
		if (*node.input == '%')
		{
			get_flag();
		}
		else
		{
//			buffer_chars(&node);

		}
		(*node.input)++;
	}
	va_end(ap);
}


