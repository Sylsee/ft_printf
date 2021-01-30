#include <stdio.h>
#include <unistd.h>

int main()
{
/*	unsigned int a = 42;
	unsigned int *b = &a;

	printf("p: %-020p\n", b);
	printf("X: %X\n", *b);*/
	printf("-: %-10d\n", 21);
	printf("0: %010d\n", 42);
	printf("*: %10d\n", 84);
	printf(".: %.10d\n", 168);
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

int ft_putstr(char *s)
{
	int i;

	i = -1;
	while (s[++i])
		write(1, &s[i], 1);
	return (i);	
}

int ft_atoi(char *n)
{
	int i;
	long ret;

	
}*/