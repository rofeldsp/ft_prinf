//
// Created by Rosanne Feldspar on 05/02/2020.
//

#include "ft_printf.h"

t_print		parse_float(t_print node)
{
	char *str;
	int i;
	__int64_t num;
//	long double residual;
	char 	*str2;
	char 	*tmp;
	int pres;
	int a;
	int b;
	int last_char;
	int sign;
	uint64_t floatnbr;
	int pres2;


	num = (__int64_t)node.fnumber;
	node.fnumber -= num;

//	long double h = 0.87650894255l;
//	h = h * ft_power(10, 11);
	if (node.precision == -2)
		node.precision = 6;

	node.field_start = node.pointer;
	a = 0;
	sign = node.fnumber < 0 ? -1 : 1;
	node.fnumber *= node.fnumber < 0 ? -1 : 1;
	pres = node.precision != -1 ? node.precision : 0;
	str2 = ft_strnew(pres + 1);
	while (pres >= 0)
	{
		if (pres > 18)
		{
			pres2 = 18;
//			pres -= (pres2 + 1);
		}
		else
			pres2 = pres;
		floatnbr = node.fnumber * ft_power(10, pres2 + 1);
		node.fnumber *= ft_power(10, pres2 + 1);
		node.fnumber -= (uint64_t )node.fnumber;
		a += pres2 + 1;
		last_char = a - 1;
		while (pres2-- >= 0)
		{
			str2[last_char--] = floatnbr % 10 + '0';
			floatnbr /= 10;
		}
		pres = pres > 18 ? (pres - 18 - 1) : pres2;
	}
//	str2 = ft_strnew(node.precision + 1);
//	pres = node.precision != -1 ? node.precision : 0;
//	while (pres-- >= 0)
//	{
//		str2[a++] = (int)(node.fnumber * 10) + '0';
//		node.fnumber *= 10;
//		node.fnumber -= (int64_t )node.fnumber;
//	}
	b = a - 1;
	if (a == 0)
		a = 1;
	if (str2[--a] >= '5')
	{
		a--;
		if (a >= 0)
			str2[a]++;
		else
			num += num > 0 ? 1 : -1;
		while (a >= 0)
		{
			if (str2[a] > '9')
			{
				if (a == 0)
					num += num > 0 ? 1 : -1;
				str2[a - 1] += str2[a] - '9';
				str2[a] = '0';
			}
			a--;
		}
	}
	str2[b] = '\0';

//	residual = node.fnumber * ft_power(10, node.precision + 1);
//	residual = residual > 0 ? residual : -residual;
//	residual = (int64_t)residual % 10 >= 5 ? (int64_t)residual / 10 + 1 : (__int64_t)residual / 10;
//	while (num_length(residual) < node.precision && residual != 0)
//		residual *= 10;
//	str = ft_itoa_float(residual, num);
	if (num == 0 && sign == -1)
	{
		str = ft_strjoin("-", tmp = ft_itoa(num));
		free(tmp);
	}
	else
		str = ft_itoa(num);
	if (node.precision > 0 || (node.flag & OCTO))
	{
		tmp = ft_strjoin(str, ".");
		free(str);
		str = ft_strjoin(tmp, str2);
		free(tmp);
		free(str2);
	}

	i = 0;
	node = adjust_to_width(node, (ft_strlen(str)));
	node = adjust_to_flag3(node, (ft_strlen(str)), str);

	if ((node.flag & ZERO && num < 0 && node.precision == -2))// || /)
	{
		node.buffer[node.field_start] = '-';
		str = ft_strcpy(str, &(str[1]));
		if (node.pointer == node.field_start)
			node.pointer++;
	}
	else if (node.number < 0 && node.precision >= 0 && !(node.size & HH) && !(node.size & H))
	{
		str = ft_strcpy(str, &(str[1]));
		node.pointer++;
//		pointer_buf = node.pointer - 1;
	}
	node.pointer += node.empty_space;
//	node.pointer -= (node.empty_space != 0 && (node.flag & PLUS) != 0 && node.precision < 0) ? 1 : 0;
	if ((node.flag & SPACE) && (!(node.flag & PLUS)) && num >= 0)
	{
		if (node.pointer == node.field_start)
		{
			node.buffer[node.pointer++] = ' ';
			node.field_start++;
		}
		else
		{
			if (node.flag & ZERO)
			{
				node.buffer[node.field_start] = ' ';
				node.empty_space = 0;
				node.field_start++;
			}
			else
				node.buffer[node.pointer - 1] = ' ';
		}
	}
	if (node.flag & PLUS && num >= 0)
	{
//		if (node.number >= 0)
//		{
			if (node.flag & ZERO && node.width > (int)ft_strlen(str))
			{
				if (node.pointer == node.field_start)
					node.buffer[node.pointer++] = '+';
				else
					node.buffer[node.field_start] = '+';
			}
			else
				node.buffer[node.pointer > node.field_start ? node.pointer - 1 : node.pointer++] = '+';
//		}
	}
	if (node.flag & MINUS)
		node.pointer = node.field_start + node.flag & PLUS && num >= 0 ? 1 : 0;
	if (node.flag & ZERO && !(node.flag & MINUS))
	{
		if (num < 0 || node.flag & PLUS)
		{
			node.buffer[node.field_start] = num < 0 ? '-' : '+';
			str = ft_strcpy(str, &(str[num < 0 ? 1 : 0]));
			node.empty_space -= num < 0 ? 0 : 1;
			node.pointer += num < 0 ? 1 : 0;
			node.field_start++;
		}
		while (node.field_start < node.pointer)
			node.buffer[node.field_start++] = '0';
	}
//	if (node.flag & ZERO)
//	{
//		int a = node.pointer;
//		if (num < 0)
//		{
//			str = ft_strcpy(str, &(str[1]));
//			node.buffer[node.field_start] = '-';
//			a++;
//			node.field_start++;
//		}
//		while (a >= node.field_start)
//		{
//			node.buffer[--a] = '0';
//		}
//	}


//	node.pointer += node.empty_space;
	while (str[i])
	{
		node.buffer[node.pointer++] = str[i++];
	}
	node.input++;
	free(str);
	return (node);
}

t_print adjust_float(t_print node)
{
	return(node);
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
