//
// Created by Rosanne Feldspar on 20/01/2020.
//

#include "ft_printf.h"

t_print		get_flag(t_print node)
{
	char *str;

	str = (char*)malloc(sizeof(char) * 5);
	str[1] = '\0';
	if (str = ft_strchr(" -+0#", *node.input))
	{
		node.flag = str[0];
//	if ((node.flag = ft_strchr(" -+#0", *node.input)[0]))
		node.input++;
	}
	return (get_width(node));
}