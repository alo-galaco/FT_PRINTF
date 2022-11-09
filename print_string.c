/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcristi <flcristi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 04:03:19 by flcristi          #+#    #+#             */
/*   Updated: 2022/11/09 01:01:07 by flcristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_string(char	*str)
{
	int		count;

	count = 0;
	if (!str)
	{
		count += write(1, "(null)", 6);
		return (count);
	}
	else
		count += write(1, &(str++), 1);
	return (count);
}