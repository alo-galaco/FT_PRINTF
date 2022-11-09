/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_decimal_integer.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcristi <flcristi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 01:02:32 by flcristi          #+#    #+#             */
/*   Updated: 2022/11/09 01:30:32 by flcristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_digitlen(long int nb)
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

int	ft_print_decimal_integer(int	size)
{
	int		i;
	char	*ptr;

	ptr = ft_itoa(size);
	i = 0;
	ft_putstr(ptr);
	i += ft_strlen(ptr);
	free(ptr);
	return (i);
}