//
// Created by Rosanne Feldspar on 13/01/2020.
//

#include <stdint.h>
#include "ft_printf.h"

int main(void)
{
	int					a;
	double				b;
	float				c;
	unsigned int		d;
	uint64_t 			e;
	uint32_t 			f;
	char 				letter = 'p';
	char 				*string = "Hello";

	ft_printf("sdfsd\nfjks%%hdf\n%c\n%s", letter, string);
//	ft_printf("%c%s", letter, string);
	return(0);
}
