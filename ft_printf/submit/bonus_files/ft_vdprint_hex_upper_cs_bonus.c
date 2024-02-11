/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdprint_hex_upper_cs_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 22:53:22 by tookuyam          #+#    #+#             */
/*   Updated: 2024/02/11 14:37:20 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>
#include "conversion_specification_bonus.h"
#include "aligned_print_bonus.h"
#include "string_util_bonus.h"
#include "libft.h"
#include "_ft_vdprint_cs_bonus.h"

int	print_hex_upper_fd_with_cs(int fd, t_cs *cs, unsigned int value);

int	ft_vdprint_hex_upper_cs(int fd, t_cs *cs, va_list args)
{
	unsigned int	value;

	value = va_arg(args, unsigned int);
	return (print_hex_upper_fd_with_cs(fd, cs, value));
}

int	print_hex_upper_fd_with_cs(int fd, t_cs *cs, unsigned int value)
{
	char	*pad_zero_str;
	int		print_len;

	if (value == 0)
		cs->flag_sharp = false;
	pad_zero_str = generate_ul_hex_with_cs(cs, value);
	if (pad_zero_str == NULL)
		return (-1);
	cs->flag_zero = 0;
	ft_toupper_str(pad_zero_str);
	print_len = t_conv_aligned_print(fd, cs, pad_zero_str);
	free(pad_zero_str);
	return (print_len);
}
