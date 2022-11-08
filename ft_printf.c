/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcristi <flcristi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 01:38:02 by flcristi          #+#    #+#             */
/*   Updated: 2022/11/08 02:25:10 by flcristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int ft_check(char format, va_list args);

int ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		len;

	va_start(args, str);
	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] != '%')
		{
			ft_putchar_fd(str[i]);
			len++;
		}
		else
		{
			i++;
			len = ft_check(str[i], args);
		}
		i++;
	}
	va_end(args);
	return (len);
}

static int ft_check(char s, va_list args)
{
	int	len;

	len = 0;
	if (s == 'c')
		len += ft_print_char(va_arg (args, int));
	else if (s == 's')
		len += ft_print_string(va_arg (args, char *));
	// else if (s == 'p')
	else if (s == 'd' || s == 'i')
		len += ft_print_decimal_integer(va_arg (args, int));
	else if (s == 'u')
		len += ft_print_unsigned(va_arg (args, unsigned int));
	else if (s == 'x' || s == 'X')
		len += ft_print_hexadecimal(va_arg (args, unsigned int));
	if (s == '%')
		len = ft_putchar_fd('%');
	return (len);
}

int main(void)
{
	char	str[20] = "Hello World 42";
	int	x;
	int	y;

	x = 15;
	y = 20.5;
	
	ft_printf("Hello World 42!\n");
	ft_printf("%c\n", 'd');
	ft_printf("%s\n", str);
	ft_printf("%%\n");
	printf("%%\n");
	ft_printf("%d\n", x);
	ft_printf("%i\n", x);
	printf("%u\n", y);
	ft_printf("%u\n", y);

	return (0);
}