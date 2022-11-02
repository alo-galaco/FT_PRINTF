/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcristi <flcristi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 01:38:02 by flcristi          #+#    #+#             */
/*   Updated: 2022/11/02 18:09:15 by flcristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
			ft_putchar_fd(str[i], 1);
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
		count += 
	// else if (s == 'p')
	// else if (s == 'd')
	// else if (s == 'i')
	// else if (s == 'u')
	// else if (s == 'x')
	// else if (s == 'X')
	// else if (s == '%')

	return (count);
}

int main(void)
{
	char	str[20] = "Hello World 42";
	
	ft_printf("Hello World 42!\n");
	ft_printf("%c\n", 'd');
	return (0);
}