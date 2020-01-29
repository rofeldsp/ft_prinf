//
// Created by Rosanne Feldspar on 13/01/2020.
//

#include <stdint.h>
#include "ft_printf.h"

int main(void)
{
	long long int					a = 42;
	double				b;
	float				c;
	unsigned int		d;
	uint64_t 			e;
	uint32_t 			f;
	char 				letter = 42;
	char 				*string = "Hello";

	ft_printf("%d", 42);
//	ft_printf("%c%s", letter, string);
	return(0);
}
