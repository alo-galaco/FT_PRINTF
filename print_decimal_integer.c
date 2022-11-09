/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_decimal_integer.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcristi <flcristi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 01:02:32 by flcristi          #+#    #+#             */
/*   Updated: 2022/11/09 03:34:17 by flcristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_decimal_integer(int	size)
{
	int		i;

	i = 0;
	if (size == -2147483648)
	{
		i += write(1, "-", 1);
		i += write(1, "2", 1);
		size = 147483648;
	}
	if (size < 0)
	{
		i += write(1, "-", 1);
		size *= -1;
	}
	if (size < 10)
	{
		size += 48;
		i += write(1, &size, 1);
	}
	else
	{
		i += ft_print_decimal_integer(size / 10);
		i += ft_print_decimal_integer(size % 10);
	}
	return (i);
}