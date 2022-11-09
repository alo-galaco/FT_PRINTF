/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexadecimal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcristi <flcristi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 01:39:56 by flcristi          #+#    #+#             */
/*   Updated: 2022/11/09 04:11:58 by flcristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hexadecimal(unsigned int i, char c)
{
	int	count;

	count = 0;
	if (i <= 16)
	{
		if(c == 'x')
			return(ft_putchar(HEX_LOWER[i]));
		else
			return(ft_putchar(HEX_UPPER[i]));
	}
	count += ft_print_hexadecimal(i / 16, c);
	if(c == 'x')
		count += (ft_putchar(HEX_LOWER[i % 16]));
	else
		count += (ft_putchar(HEX_UPPER[i % 16]));
	return (count);
}