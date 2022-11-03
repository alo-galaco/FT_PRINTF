/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcristi <flcristi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 02:16:23 by flcristi          #+#    #+#             */
/*   Updated: 2022/11/03 16:22:54 by flcristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_fd(int c)
{
	write (1, &c, 1);
	return (1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		ft_putchar_fd (s[i]);
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

static int	ft_digitlen(long int nb)
{
	int	count;

	count = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		nb = -nb;
		count++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char		*ptr;
	long int	nb;
	int			size;

	nb = n;
	size = ft_digitlen(nb);
	ptr = (char *)malloc(size + 1);
	if (!ptr)
		return (NULL);
	ptr[size--] = '\0';
	if (nb == 0)
		ptr[0] = 48;
	if (nb < 0)
	{
		nb = -nb;
		ptr[0] = '-';
	}
	while (nb > 0)
	{
		ptr[size--] = nb % 10 + '0';
		nb -= nb % 10;
		nb /= 10;
	}
	return (ptr);
}

int	ft_print_char(va_list args)
{
	ft_putchar_fd(va_arg (args, int));
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

int	ft_print_decimal_integer(va_list args)
{
	int		size;
	int		i;
	char	*ptr;

	size = (va_arg(args, int));
	ptr = ft_itoa(size);
	i = 0;
	ft_putstr_fd(ptr, 1);
	size += ft_strlen(i);
	free(i);
	return (size);
}