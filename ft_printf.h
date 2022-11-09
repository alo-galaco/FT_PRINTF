/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcristi <flcristi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 01:38:23 by flcristi          #+#    #+#             */
/*   Updated: 2022/11/09 01:06:39 by flcristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
int		ft_print_char(int char);
int		ft_print_string(char *str);
int		ft_print_decimal_integer(int	size);
int		ft_print_unsigned(va_list args);
size_t	ft_strlen(const char *str);
int		ft_putchar_fd(int c);
void	ft_putstr_fd(char *s, int fd);
char	*ft_itoa(int n);

#endif