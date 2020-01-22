//
// Created by Rosanne Feldspar on 26/12/2019.
//

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/*
** Standard libraries
*/

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

/*
** ----------Standard libraries-------------------
*/


# include "libft/libft.h"

/*
** Node desc and macros
*/

# define BUFF_SIZE 100

typedef struct	print
{
	va_list		ap;
	char 		*input;
	char 		*buffer;
	int 		pointer;
	char 		flag;
	int 		size;
	int 		number;
	int 		empty_space;
	int 		width;
	int 		precision;
}				t_print;

/*
**	Functions
*/

void				ft_printf(const char *str, ...);
t_print				print_arg(t_print node);
t_print				get_type(t_print node);
char 				*increase_buffer(char **str, t_print *node);
t_print				parse_char(t_print node);
t_print				parse_string(t_print node);
t_print				get_flag(t_print node);
t_print				get_width(t_print node);
t_print				get_precision(t_print node);
t_print				get_size(t_print node);
t_print				adjust_to_width(t_print node, int len);
t_print				adjust_to_flag(t_print node, int len);
t_print 			parse_decimal(t_print node);
t_print				adjust_to_flag2(t_print node, int len);

#endif
