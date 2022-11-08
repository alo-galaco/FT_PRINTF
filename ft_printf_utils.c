/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcristi <flcristi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 02:16:23 by flcristi          #+#    #+#             */
/*   Updated: 2022/11/08 04:01:11 by flcristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (s[i] != '\0')
	{
		ft_putchar(s[i]);
		i++;
	}
	return (len);
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
	i += ft_strlen(ptr);
	free(ptr);
	return (i);
}

int	ft_print_unsigned(va_list args)
{
	unsigned int		size;
	int		i;
	char	*ptr;

	size = (va_arg(args, unsigned int));
	ptr = ft_uitoa(size);
	i = 0;
	ft_putstr_fd(ptr, 1);
	i += ft_strlen(ptr);
	free(ptr);
	return (i);
}

char	*ft_uitoa(unsigned int n)
{
	char				*ptr;
	unsigned long int	nb;
	int					size;

	nb = n;
	size = ft_digitlen(nb);
	ptr = (char *)malloc(size + 1);
	if (!ptr)
		return (NULL);
	ptr[size--] = '\0';
	if (nb == 0)
		ptr[0] = 48;
	while (nb > 0)
	{
		ptr[size--] = nb % 10 + '0';
		nb -= nb % 10;
		nb /= 10;
	}
	return (ptr);
}