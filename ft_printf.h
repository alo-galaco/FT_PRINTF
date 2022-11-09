/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcristi <flcristi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 01:38:23 by flcristi          #+#    #+#             */
/*   Updated: 2022/11/09 01:57:04 by flcristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
int		ft_print_char(int c);
int		ft_print_string(char *str);
int		ft_print_decimal_integer(int	size);
int		ft_print_unsigned(unsigned int size);
int		ft_print_hexadecimal(unsigned int, char c);
size_t	ft_strlen(const char *str);
int		ft_putchar(int c);
int		ft_putstr(char *s);
char	*ft_itoa(int n);
char	*ft_uitoa(unsigned int n);
int		ft_digitlen(long int nb);

#endif