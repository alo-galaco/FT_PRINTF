/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcristi <flcristi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 01:38:02 by flcristi          #+#    #+#             */
/*   Updated: 2022/11/02 04:01:39 by flcristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
		if (str != '%')
		{
			ft_putchar_fd (str[i], 1);
			len++;
		}
		// else
		// {
		// 	i++;
		// 	len =
		// }
		i++;
	}
	va_end(args);
	return (len);
}

int main(void)
{
	ft_printf("Hello World 42");
	return (0);
}

// static int ft_check(char format, va_list args)
// {
// 	int	count;

// 	count = 0;
// 	if (c == 'c')
// 	if (c == '%')

// 	return (count);
// }