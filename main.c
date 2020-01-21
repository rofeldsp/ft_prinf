//
// Created by Rosanne Feldspar on 13/01/2020.
//

#include <stdint.h>
#include "ft_printf.h"

int main(void)
{
	int					a = 56;
	double				b;
	float				c;
	unsigned int		d;
	uint64_t 			e;
	uint32_t 			f;
	char 				letter = 'p';
	char 				*string = "Hello";

	ft_printf("sdf%%123\n%-10s123\n%01000d", string, a);
//	ft_printf("%c%s", letter, string);
	return(0);
}
