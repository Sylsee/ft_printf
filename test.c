#include <stdio.h>
#include <unistd.h>

int main()
{
	int i = 0;

	if (i)
		printf("wesh\n");
	printf("%-*d", 10, 42);
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
