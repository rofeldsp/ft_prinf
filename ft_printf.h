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


# include "../libft/libft.h"

/*
** Node desc and macros
*/

# define BUFF_SIZE	100
# define MINUS		1
# define PLUS		(1 << 1)
# define SPACE		(1 << 2)
# define ZERO		(1 << 3)
# define OCTO		(1 << 4)

# define H			(1)
# define HH			(1 << 1)
# define L			(1 << 2)
# define LL			(1 << 3)

typedef struct	print
{
	va_list			ap;
	char 			*input;
	char 			*buffer;
	int 			pointer;
	unsigned int	flag;
	unsigned int	size;
	int 			number;
	int 			empty_space;
	int 			width;
	int 			precision;
}				t_print;

/*
**	Functions
*/

int				ft_printf(const char *str, ...);
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
t_print				adjust_to_precision(t_print node, int len);
t_print				adjust_to_flag(t_print node, int len);
t_print 			parse_decimal(t_print node);
t_print				adjust_to_flag2(t_print node, int len);
void				free_flags(t_print *node);
t_print 			parse_percent(t_print node);

#endif
