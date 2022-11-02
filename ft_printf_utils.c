/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcristi <flcristi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 02:16:23 by flcristi          #+#    #+#             */
/*   Updated: 2022/11/02 03:37:32 by flcristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		ft_putchar_fd (s[i], fd);
		i++;
	}
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_print_char(va_list args)
{
	ft_putchar_fd(va_arg (args, int), 1);
	return (1);
}

int	ft_print_string(va_list args)
{
	int		count;
	char	*r;

	count = 0;
	r = (va_arg(args, char *));
	if (!r)
	{
		ft_putstr_fd("(null)", 1);
		return (count);
	}
	else
	{
		ft_putstr_fd(r, 1);
		count = ft_strlen(r);
	}
	return (count);
}