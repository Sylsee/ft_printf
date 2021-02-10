#include "libprintf.h"

int main()
{
	int xstr = -10;
	ft_printf("-: %-*X\n", 20, xstr);
	ft_printf("0: %0*x\n", 20, xstr);
	ft_printf("*: %*x\n", 20, xstr);
	ft_printf(".: %.*x\n", 1, xstr);
	ft_printf("-.: %-*.20x\n", 20, xstr);
	ft_printf("0.: %0*.20x\n", 20, xstr);
	ft_printf("*.: %*.20x\n", 20, xstr);

	long str = 0;
	ft_printf("-: %-*p\n", 20, &str);
	ft_printf("0: %0*p\n", 20, &str);
	ft_printf("*: %*p\n", 20, &str);
	ft_printf(".: %.*p\n", 1, &str);
	ft_printf("-.: %-*.20p\n", 20, &str);
	ft_printf("0.: %0*.20p\n", 20, &str);
	ft_printf("*.: %*.20p\n", 20, &str);

	ft_printf("0: %0*d\n", -10, 42);
	ft_printf("0: %0*d\n", -10, 42);
	ft_printf("0: %.*d\n\n", -10, 42);

	ft_printf("-: %-*c\n", 10, 's');
	ft_printf("0: %0*c\n", 10, 's');
	ft_printf("*: %*c\n", 10, 's');
	ft_printf("-: %-*s\n", 20, str);
	ft_printf("0: %0*s\n", 20, str);
	ft_printf("*: %*s\n", 20, str);
	ft_printf(".: %.*s\n", 0, "wesh");
	ft_printf("-.: %-*.2s\n", 20, str);
	ft_printf("0.: %0*.2s\n", 20, str);
	ft_printf("*.: %*.2s\n", 20, str);
	return (0);
}


/*
**	. with d = 0 before (don't cut into the nb)
**  . with s = cut if < len of s
**	
**	
**	
**	
**	
**	
*/



/*
**  cspdiuxX%
**	fl : 0 -> between % and fl
**	fl : 1 -> digit before (width / padding)
**	fl : 2 -> number -
**	fl : 3 -> number 0
**	fl : 4 -> number .
**	fl : 5 -> number *
**	fl : 6 -> digit after (precision)
*/
