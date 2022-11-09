/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcristi <flcristi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 02:16:23 by flcristi          #+#    #+#             */
/*   Updated: 2022/11/09 03:45:24 by flcristi         ###   ########.fr       */
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
	if (!s)
		return (write(1, "(null)", 6));
	while (s[i] != '\0')
	{
		ft_putchar(s[i]);
		i++;
	}
	return (len);
}