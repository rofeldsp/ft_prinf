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
	residual = (int64_t)residual % 10 >= 5 ? (int64_t)residual / 10 + 1 : (__int64_t)residual / 10;
//	while (num_length(residual) < node.precision && residual != 0)
//		residual *= 10;
	str = ft_itoa_float(residual, num, node.precision);
	i = 0;
	while (str[i])
	{
		node.buffer[node.pointer++] = str[i++];
	}
	node.input++;
	return (node);
}

int 		num_length(int64_t residual)
{
	int len;

	len = 0;
	while (residual / 10 > 0)
	{
		len++;
		residual /= 10;
	}
	return(++len);
}

char 		*ft_itoa_float(__int64_t residual, __int64_t num, int len)
{
	char *str_main;
	char *tmp;
	char *tmp2;

	str_main = ft_itoa(num);
	tmp = ft_strjoin(str_main, ".");
	free(str_main);
	while (residual % 10 == 0 && residual)
		residual /= 10;
	tmp2 = ft_itoa(residual);
	if (num_length(residual) != len)
		adjust_float_length(&tmp2, len);
	str_main = ft_strjoin(tmp, tmp2);
	free(tmp);
	free(tmp2);
	return(str_main);
}

void		adjust_float_length(char **str, int len)
{
	char *ret;
	int i;
	int dif;
	char *tmp;

	ret = ft_strnew(len);
	i = 0;
	if ((*(*str)) == '0')
	{
		while (len-- > 0)
			ret[i++] = '0';
		free(*str);
		*str = ft_strdup(ret);
		return ;
	}
	dif = len - ft_strlen(*str);
	while (dif-- > 0)
		ret[i++] = '0';
	tmp = ft_strjoin(ret, *str);
	free(ret);
	free(*str);
	*str = ft_strdup(tmp);
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
