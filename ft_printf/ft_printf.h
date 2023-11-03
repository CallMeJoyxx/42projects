/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtriscar <jtriscar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:02:40 by jtriscar          #+#    #+#             */
/*   Updated: 2023/11/02 23:05:51 by jtriscar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int	ft_printf(const char *input, ...);
int	ft_print_char(char c); // working
int	ft_print_string(const char *string); // working
int	ft_print_unsigned(unsigned int num); // working
int	ft_print_hex_up(unsigned long num);
int	ft_print_hex_down(unsigned long num);
int	ft_print_int(int n); // working
int	ft_print_ptr(unsigned long pointer); // working

#endif
