//
// Created by Rosanne Feldspar on 31/01/2020.
//

#include "ft_printf.h"

int		ft_putstr_printf(char *str, int a)
{
	int i;

	i = 0;
	while (str[i] || a > 0)
	{
		if (str[i] == '\0')
			a--;
		ft_putchar(str[i++]);
	}
	return (i);
}