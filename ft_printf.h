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
** Node desc
*/

typedef struct	print
{
	va_list		ap;
	char 		*input;
}				t_print;

#endif
