/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcristi <flcristi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 01:08:53 by flcristi          #+#    #+#             */
/*   Updated: 2022/11/09 01:10:52 by flcristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_unsigned(unsigned int size)
{
	int		i;
	char	*ptr;

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