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

# define BUFF_SIZE 5

typedef struct	print
{
	va_list		ap;
	char 		*input;
	char 		*buffer;
	int 		pointer;
	int 		size;
}				t_print;

/*
**	Functions
*/

void				ft_printf(const char *str, ...);
t_print				print_arg(t_print node);
t_print				get_flag(t_print node);
char 				*increase_buffer(char **str, t_print *node);
t_print				parse_char(t_print node);
t_print				parse_string(t_print node);

#endif
