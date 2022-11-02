/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcristi <flcristi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 01:38:23 by flcristi          #+#    #+#             */
/*   Updated: 2022/11/02 03:45:47 by flcristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
int		ft_print_char(va_list args);
int		ft_print_string(va_list args);
size_t	ft_strlen(const char *str);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);

#endif