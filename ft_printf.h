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
# include "limits.h" //можно такую?
# include <string.h> // убрать потом
# include <stdio.h> //убрать потом

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
# define FLOAT_L		(1 << 4)

typedef struct	print
{
	va_list			ap;
	char 			*input;
	char 			*buffer;
	int 			pointer;
	unsigned int	flag;
	unsigned int	size;
	__int64_t		number;
	__uint64_t		unumber;
	long double 	fnumber;
	int 			empty_space;
	int 			width;
	int 			precision;
	int 			end_of_field;
	int 			field_start;
	int 			count_nulls;
	int 			buffer_size;
}				t_print;

/*
**	Functions
*/

int					ft_printf(const char *str, ...);
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
t_print				adjust_to_width2(t_print node, int len);
t_print				adjust_to_precision(t_print node, int len, char **str);
t_print				adjust_to_precision3(t_print node, int len, char **str);
t_print				adjust_to_flag(t_print node, int len);
t_print 			parse_decimal(t_print node);
t_print 			parse_udecimal(t_print node);
t_print				adjust_to_flag2(t_print node, int len, char c, char *str);
t_print				adjust_to_flag3(t_print node, int len, char *str);
void				free_flags(t_print *node);
t_print 			parse_percent(t_print node);
t_print 			parse_hexodecimal(t_print node, char c);
char 				*ft_itoa_base(__uint64_t nb, int base, char c);
char 				*ft_itoa_base2(int i, char **str);
void				check_overflow(t_print *node);
void	 			adjust_to_precision2(t_print *node, char **str);
int 				ft_putstr_printf(char *str, int a);
t_print 			parse_octal(t_print node, char c);
char 				*ft_uitoa(uint64_t n);
t_print				parse_pointer(t_print node);
t_print 			parse_float(t_print node);
__uint64_t			ft_power(int base, int power);
char 				*ft_itoa_float(__int64_t residual, __int64_t num, int len);
char				*ft_strcpy_special_edition(char *dest, const char *src);
void				adjust_float_length(char **str, int len);
int 				num_length(__int64_t residual);
t_print				adjust_float(t_print node);

#endif
