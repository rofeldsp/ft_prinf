//
// Created by Rosanne Feldspar on 03/02/2020.
//

#include "ft_printf.h"

t_print 	parse_udecimal(t_print node) {
	char *str;
	int i;

	node.field_start = node.pointer;
	str = (node.size == H) ? ft_uitoa((unsigned short) node.unumber) : (node.size == HH ?
			 ft_uitoa((unsigned char) node.unumber) : ft_uitoa(node.unumber));
	i = 0;
	node = adjust_to_width(node, (node.precision == -1 ? 0 : ft_strlen(str)));
	node = adjust_to_flag2(node, (node.precision == -1 ? 0 : ft_strlen(str)),'0', str);
	node.pointer += node.empty_space;
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
	return (dst);
}

char			*ft_uitoa(uint64_t n)
{
	__uint64_t		j;
	char				*dst;

	j = 1;
	dst = cut(j, n);
	return (dst);
}


