//
// Created by Rosanne Feldspar on 13/01/2020.
//

#include <stdint.h>
#include "ft_printf.h"


int main(int argc, char **argv)
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
	char 				*string = NULL;
	static char 		ch_pos_1 = 100, ch_neg_1 = -87;
	static short		sh_pos_1 = 3047, sh_neg_1 = -8875;
	static int			i_pos_1 = 878023;
	static long		l_pos_1 = 22337203685477, l_neg_1 = -22337203685477;
	static long long	ll_pos_1 = 22337203685477, ll_neg_1 = -22337203685477;
	static long		lmax	= 9223372036854775807;
	static long		lmin	= -9223372036854775807;
	static long long llmax = 9223372036854775807;
	static long long	llmin = -9223372036854775807ll;
	static unsigned char 		uch_pos_1 = 100;
	static unsigned short		ush_pos_1 = 3047;
	static unsigned int		ui_pos_1 = 878023;
	static unsigned long		ul_pos_1 = 22337203685477;
	static unsigned long long	ull_pos_1 = 22337203685477;
	static unsigned long long  ullmax = 9223372036854775807;
	static unsigned long  		ulmax = 9223372036854775807;
	int fd;


//	fd = open("check.txt", O_RDWR);
//	ft_dprintf(fd, "check %Ud", 68394);
//	close(fd);
//	ft_printf("%bf", 36.45645);
//	write(1, "^C", 2);
//	ft_printf("%B", "Hello World!");
	ft_printf("{green}%s%hihello%-17.14llu%lli%08hu%s%17ssom{red}estuff%s%hi%i%.24lu%llu%u%.2s{{eoc}%li    %25.16f","abc",sh_neg_1,
			  ull_pos_1,ll_neg_1,ush_pos_1,"wassup","nope","",(short)32767,0,ul_pos_1,0ull,ui_pos_1,"notall",l_pos_1, "Hello World", -356.123456789101112897675);
	printf("\n%s%hihello%-17.14llu%lli%08hu%s%17ssomestuff%s%hi%i%.24lu%llu%u%.2s%li","abc",sh_neg_1,
		   ull_pos_1,ll_neg_1,ush_pos_1,"wassup","nope","",(short)32767,0,ul_pos_1,0ull,ui_pos_1,"notall",l_pos_1);
//	printf("%p", NULL);
//	ft_printf("%c%s", letter, string);
	return(0);
}
