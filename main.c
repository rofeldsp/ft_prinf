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
	char 				a01;
	char 				a02;
	char 				a03;
	char 				a04;
	char 				a05;
	char 				a06;
	char 				a07;
	char 				a08;
	char 				a09;
	char 				a10;
	char 				a11;
	char 				a12;
	char 				letter = 42;
	char 				*string = "Hello";

	ft_printf("%.10Lf", 0.87650894255l);
	printf("\n%.10Lf", 0.87650894255l);
//	ft_printf("%c%s", letter, string);
	return(0);
}
