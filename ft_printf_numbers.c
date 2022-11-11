/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_numbers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcristi <flcristi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 02:16:23 by flcristi          #+#    #+#             */
/*   Updated: 2022/11/12 00:14:37 by flcristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_decimal_integer(int size)
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

int	ft_print_unsigned(unsigned int size)
{
	int		i;

	i = 0;
	if (size >= 10)
		i += ft_print_unsigned(size / 10);
	i += ft_print_char(size % 10 + '0');
	return (i);
}

int	ft_print_hexadecimal(unsigned int i, char c)
{
	int	count;

	count = 0;
	if (i < 16)
	{
		if (c == 'x')
			return (ft_print_char(HEX_LOWER[i]));
		else
			return (ft_print_char(HEX_UPPER[i]));
	}
	count += ft_print_hexadecimal(i / 16, c);
	if (c == 'x')
		count += (ft_print_char(HEX_LOWER[i % 16]));
	else
		count += (ft_print_char(HEX_UPPER[i % 16]));
	return (count);
}

int	ft_print_pointer(unsigned long ptr)
{
	int	count;

	count = 0;
	if (!ptr)
	{
		count += write(1, "(nil)", 5);
		return (count);
	}
	if (ptr < 16)
	{
		count += write(1, "0x", 2) + (ft_print_char(HEX_LOWER[ptr]));
		return (count);
	}
	count += ft_print_pointer(ptr / 16);
	count += (ft_print_char(HEX_LOWER[ptr % 16]));
	return (count);
}
