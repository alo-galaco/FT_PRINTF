/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexadecimal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcristi <flcristi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 01:39:56 by flcristi          #+#    #+#             */
/*   Updated: 2022/11/09 02:01:50 by flcristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hexadecimal(unsigned int i, char c)
{
	char	*hex;
	int		count;

	count = 0;
	if(c == 'x')
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	if (c <= 16)
		return(ft_putchar(hex[count]));
	count += ft_print_hexadecimal(i / 16, c);
	count += ft_putchar(hex [ i % 16]);
	return (count);
}