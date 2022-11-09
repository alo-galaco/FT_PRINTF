/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcristi <flcristi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 01:38:23 by flcristi          #+#    #+#             */
/*   Updated: 2022/11/09 04:04:10 by flcristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# define HEX_LOWER "0123456789abcdef"
# define HEX_UPPER "0123456789ABCDEF"

int		ft_printf(const char *str, ...);
int		ft_print_char(int c);
int		ft_print_string(char *str);
int		ft_print_decimal_integer(int	size);
int		ft_print_unsigned(unsigned int size);
int		ft_print_hexadecimal(unsigned int, char c);
int		ft_print_pointer(unsigned long ptr);
int		ft_putchar(int c);
int		ft_putstr(char *s);

#endif