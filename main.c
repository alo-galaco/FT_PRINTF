#include <stdarg.h>
#include <stdio.h>
#include <string.h>

int	max(int num_args, ...);

int main(void)
{
	max(8, 10, 25, 26, 28);
	return (0);
}

int	max(int num_args, ...)
{
	va_list	args;
	int	x;

	va_start(args, num_args);
	if (num_args)
	{
		int x = va_arg(args, int);
		printf("x: %d\n", x);
		x = va_arg(args, int);
		printf("x: %d\n", x);
	}
	va_end (args);
	return (0);
}