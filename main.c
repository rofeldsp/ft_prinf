//
// Created by Rosanne Feldspar on 13/01/2020.
//

#include <stdint.h>
#include "ft_printf.h"

int main(void)
{
	int					a = 555555;
	double				b;
	float				c;
	unsigned int		d;
	uint64_t 			e;
	uint32_t 			f;
	char 				letter = '0';
	char 				*string = "Hello";

	ft_printf("%hd", a);
//	ft_printf("%c%s", letter, string);
	return(0);
}
