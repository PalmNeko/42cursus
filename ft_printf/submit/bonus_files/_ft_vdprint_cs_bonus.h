/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _ft_vdprint_cs_bonus.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 14:33:20 by tookuyam          #+#    #+#             */
/*   Updated: 2024/02/11 14:37:20 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_VDPRINT_CS_BONUS_H
# define _FT_VDPRINT_CS_BONUS_H

# include <stdarg.h>
# include "conversion_specification_bonus.h"

typedef int	(*t_print_function)(int, t_cs *, va_list);
typedef struct s_relational_conversion_specifier_and_print_function {
	t_conversion_specifier		specifier;
	t_print_function			p_function;
}	t_relational_conversion_specifier_and_print_function;

int		ft_vdprint_char_cs(int fd, t_cs *cs, va_list args);
int		ft_vdprint_decimal_cs(int fd, t_cs *cs, va_list args);
int		ft_vdprint_hex_cs(int fd, t_cs *cs, va_list args);
int		ft_vdprint_hex_upper_cs(int fd, t_cs *cs, va_list args);
int		ft_vdprint_int_cs(int fd, t_cs *cs, va_list args);
int		ft_vdprint_percent_cs(int fd, t_cs *cs, va_list args);
int		ft_vdprint_pointer_cs(int fd, t_cs *cs, va_list args);
int		ft_vdprint_string_cs(int fd, t_cs *cs, va_list args);
int		ft_vdprint_uint_cs(int fd, t_cs *cs, va_list args);

int		print_char_fd_with_cs(int fd, t_cs *cs, char c);

char	*generate_ul_hex_with_cs(t_cs *cs, unsigned long value);

#endif
