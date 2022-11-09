/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcristi <flcristi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 03:43:36 by flcristi          #+#    #+#             */
/*   Updated: 2022/11/09 04:19:55 by flcristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_pointer(unsigned long ptr)
{
	int	count;

	count = 0;
	if (!ptr)
	{
		count += write(1, "(nil)", 5);
		return (count);
	}
	if (ptr <= 16)
	{
		count += write (1, "0x", 2);
		return(ft_putchar(HEX_LOWER[ptr]));
	}
	count += ft_print_pointer(ptr / 16);
	count += (ft_putchar(HEX_LOWER[ptr % 16]));
	return (count);
}
