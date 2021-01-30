#include <stdio.h>
#include <unistd.h>

int main()
{
	printf("-*.: %*.5d\n", -10, -21);
	printf("0.: %010.5d\n", 21);
	printf("-.: %-10.5d\n", 21);
	printf("*.: %*.5d\n", 10, 21);
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
