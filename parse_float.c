//
// Created by Rosanne Feldspar on 05/02/2020.
//

#include "ft_printf.h"

t_print		parse_float(t_print node)
{
	char *str;
	int i;
	__int64_t num;
	long double residual;

	num = (__int64_t)node.fnumber;
	if (node.precision == -2)
		node.precision = 6;
	node.fnumber -= num;
	residual = node.fnumber * ft_power(10, node.precision + 1);
	residual = residual > 0 ? residual : -residual;
	residual = (int64_t)residual% 10 >= 5 ? (int64_t)residual / 10 + 1 : (__int64_t)residual / 10;
	str = ft_itoa_float(residual, num);
	i = 0;
	while (str[i])
	{
		node.buffer[node.pointer++] = str[i++];
	}
	node.input++;
	return (node);
}

char 		*ft_itoa_float(__int64_t residual, __int64_t num)
{
	char *str_main;
	char *tmp;

	str_main = ft_itoa(num);
	tmp = ft_strjoin(str_main, ".");
	free(str_main);
	str_main = ft_strjoin(tmp, ft_itoa(residual));
	free(tmp);
	return(str_main);
}

__uint64_t	ft_power(int base, int power)
{
	__uint64_t res;
	int i;

	i = 1;
	res = base;
	while (i++ < power)
		res = res * base;
	return (res);
}
