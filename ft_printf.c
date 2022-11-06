/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcristi <flcristi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 01:38:02 by flcristi          #+#    #+#             */
/*   Updated: 2022/11/06 02:09:50 by flcristi         ###   ########.fr       */
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
	int	count;

	count = 0;
	if (s == 'c')
		count += ft_print_char(args);
	else if (s == 's')
		count += ft_print_string(args);
	// else if (s == 'p')
	else if (s == 'd' || s == 'i')
		count += ft_print_decimal_integer(args);
	else if (s == 'u')
		count += ft_print_unsigned(args);
	// else if (s == 'x')
	// else if (s == 'X')
	if (s == '%')
		count = ft_putchar_fd('%');
	return (count);
}

int main(void)
{
	char	str[20] = "Hello World 42";
	int	x;

	x = 10;
	
	ft_printf("Hello World 42!\n");
	ft_printf("%c\n", 'd');
	ft_printf("%s\n", str);
	ft_printf("%%%1\n");
	printf("%%%2\n");
	// ft_printf("%d\n", x);
	// ft_printf("%i\n", x);
	printf("%u\n", x);
	ft_printf("%u\n", x);
	printf("%i\n", x);

	return (0);
}