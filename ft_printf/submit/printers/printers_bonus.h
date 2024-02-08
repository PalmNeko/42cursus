/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:51:32 by tookuyam          #+#    #+#             */
/*   Updated: 2023/11/08 23:53:55 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTERS_BONUS_H
# define PRINTERS_BONUS_H

# include <stdarg.h>
# include "conversion_specification.h"

typedef int	(*t_print_function)(int, t_conv_specification *, va_list);
typedef struct s_relational_conversion_specifier_and_print_function {
	t_conversion_specifier		specifier;
	t_print_function			p_function;
}	t_relational_conversion_specifier_and_print_function;

int	print_char_fd(int fd, t_conv_specification *cs, va_list args);
int	print_decimal_fd(int fd, t_conv_specification *cs, va_list args);
int	print_hex_fd(int fd, t_conv_specification *cs, va_list args);
int	print_hex_upper_fd(int fd, t_conv_specification *cs, va_list args);
int	print_int_fd(int fd, t_conv_specification *cs, va_list args);
int	print_percent_fd(int fd, t_conv_specification *cs, va_list args);
int	print_pointer_fd(int fd, t_conv_specification *cs, va_list args);
int	print_string_fd(int fd, t_conv_specification *cs, va_list args);
int	print_uint_fd(int fd, t_conv_specification *cs, va_list args);
int	print_until_char_fd(int fd, const char *str, char c);
int	print_va_list_fd(int fd, t_conv_specification *cs, va_list args);

#endif
