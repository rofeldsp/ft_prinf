//
// Created by Rosanne Feldspar on 03/02/2020.
//

#include "ft_printf.h"

t_print 	parse_udecimal(t_print node) {
	char *str;
	int i;

//	node.number = va_arg(node.ap, int);
	node.field_start = node.pointer;
	str = (node.size == H) ? ft_uitoa((unsigned short) node.unumber) : (node.size == HH ?
			 ft_uitoa((unsigned char) node.unumber) : ft_uitoa(node.unumber));
	i = 0;
	node = adjust_to_width(node, (node.precision == -1 ? 0 : ft_strlen(str)));
	node = adjust_to_flag2(node, (node.precision == -1 ? 0 : ft_strlen(str)),'0', str);
//	if ((node.flag & ZERO) || (node.precision >= 0 && !(node.flag & HH) && !(node.flag & H)))
//	{
//		node.buffer[node.field_start] = '-';
//		str = ft_strcpy(str, &(str[1]));
//		if (node.pointer == node.field_start)
//			node.pointer++;
//	}
	node.pointer += node.empty_space;
//	if ((node.flag & SPACE) && (!(node.flag & PLUS))) {
//		if (node.flag & ZERO) {
//			node.buffer[node.pointer - node.empty_space] = ' ';
//			node.empty_space = 0;
//		} else {
//			if (node.pointer == node.field_start)
//				node.buffer[node.pointer++] = ' ';
//			else
//				node.buffer[node.pointer - 1] = ' ';
//		}
//	}
//	node.pointer += node.empty_space;
	node = adjust_to_precision3(node, ft_strlen(str), &str);
	while (str[i]) {
		if ((node.pointer + 1) % BUFF_SIZE == 0)
			node.buffer = increase_buffer(&node.buffer, &node);
		node.buffer[node.pointer] = str[i];
		i++;
		node.pointer++;
	}
	node.input++;
	node.pointer = node.end_of_field > node.pointer ? node.end_of_field : node.pointer;
	free(str);
	return (node);
}


static char		*cut(uint64_t j, uint64_t n)
{
	char				*dst;
	uint64_t				b;

	b = n;
	while (b / 10 > 0)
	{
		j++;
		b = b / 10;
	}
	if (!(dst = (char*)malloc(sizeof(char) * (j + 1))))
		exit (-1);
	dst[j] = '\0';
	j--;
	while (n / 10 > 0)
	{
		dst[j] = '0' + n % 10;
		n = n / 10;
		j--;
	}
	dst[j] = '0' + n % 10;
//	if (c < 0)
//		dst[j - 1] = '-';
	return (dst);
}

char			*ft_uitoa(uint64_t n)
{
	__uint64_t		j;
	char				*dst;

	j = 1;
//	c = n;
//	if (n < 0)
//	{
//		if (n - 1 > n)
//			return (ft_strdup("-9223372036854775808"));
//		n = -n;
//		j++;
//	}
	dst = cut(j, n);
	return (dst);
}


