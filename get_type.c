//
// Created by Rosanne Feldspar on 21/01/2020.
//

#include "ft_printf.h"

t_print		get_type(t_print node)
{
	if (*node.input == 'c')
		return(parse_char(node));
	else if (*node.input == 's')
		return(parse_string(node));
	else if (*node.input == 'd')
	{
		node.number = (node.size & L) ? va_arg(node.ap, long int) :
					  ((node.size & LL) ? va_arg(node.ap, long long int) :
					   va_arg(node.ap, int));
		return (parse_decimal(node));
	}
//	else if (*node.input == 'd')
//	{
//		if (node.size & L)
//			node.number = va_arg(node.ap, long int);
//		else if (node.size & LL)
//			node.number = va_arg(node.ap, long long int);
//		else if (node.size & H)
//			node.number = (short)va_arg(node.ap, int);
//		else
//			node.number = va_arg(node.ap, int);
//		return (parse_decimal(node));
//	}
	else if (*node.input == '%')
		return (parse_percent(node));
	else if (*node.input == 'x' || *node.input == 'X')
	{
		node.unumber = (node.size & L) ? va_arg(node.ap, unsigned long int) :
				((node.size & LL) ? va_arg(node.ap, unsigned long long int) :
					   va_arg(node.ap, unsigned int));
		return (parse_hexodecimal(node, (*node.input == 'x' ? 'f' : 'F')));
//		if (node.size & L)
//			return (lparse_hexodecimal(node, 'f'));
//		else if (node.size & LL)
//			return (llparse_hexodecimal(node, 'f'));
//		else if (node.size & H)
//			node.number = (short)va_arg(node.ap, int);
//		else
//			node.number = va_arg(node.ap, int);
		return(parse_hexodecimal(node, 'f'));
	}
//	else if (*node.input == 'X')
//	{
//		node.unumber = (node.size & L) ? va_arg(node.ap, unsigned long int) :
//					   ((node.size & LL) ? va_arg(node.ap, unsigned long long int) :
//						va_arg(node.ap, unsigned int));
//		return (parse_hexodecimal(node, 'F'));
////		if (node.size & L)
////			return (lparse_hexodecimal(node, 'F'));
////		else if (node.size & LL)
////			return (llparse_hexodecimal(node, 'F'));
////		else if (node.size & H)
////			node.number = (short)va_arg(node.ap, int);
//////		else
//////			node.number = va_arg(node.ap, int);
////		return(parse_hexodecimal(node, 'F'));
//	}
	return(parse_decimal(node));
}
