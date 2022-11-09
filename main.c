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

int main(void)
{
	char	str[20] = "Hello World 42";
	int	x;
	int	y;

	x = 15;
	y = 20;
	
	ft_printf("%d\n", ft_printf(0));
	printf("%d\n", printf(0));	
	ft_printf("%c\n", 'd');
	printf("%%\n");
	ft_printf("%d\n", x);
	ft_printf("%i\n", x);
	ft_printf("%u\n", y);
	ft_printf("%x\n", y);
	ft_printf("%X\n", y);
	ft_printf("%p\n", str);
	return (0);
}