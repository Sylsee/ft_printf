#include <stdio.h>
#include <unistd.h>

int main()
{
	printf("0: %0*d\n", -10, 42);
	printf("0: %0*d\n", -10, 42);
	printf("0: %.*d\n\n", -10, 42);
	printf("-: %-*c\n", 10, 's');
	printf("0: %0*c\n", -10, 's');
	printf("*: %*c\n", 10, 's');
	/*
	printf("-: %-*s\n", 10, "wesh");
	printf("0: %0*s\n", 10, "wesh");
	printf("*: %*s\n", 10, "wesh");
	printf(".: %.*s\n", 0, "wesh");
	printf("-.: %-*.2s\n", 10, "wesh");
	printf("0.: %0*.2s\n", 10, "wesh");
	printf("*.: %*.2s\n", 10, "wesh");
	return (0);
	*/
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
