/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdprint_hex_cs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 22:26:33 by tookuyam          #+#    #+#             */
/*   Updated: 2024/02/11 16:32:46 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include <stdbool.h>
#include "conversion_specification.h"
#include "aligned_print.h"
#include "string_util.h"
#include "libft.h"
#include "_ft_vdprint_cs.h"
#include "ft_printf.h"

int	print_hex_fd_with_cs(int fd, t_cs *cs, unsigned int value);

int	ft_vdprint_hex_cs(int fd, t_cs *cs, va_list args)
{
	unsigned int	print_value;

	print_value = va_arg(args, unsigned int);
	return (print_hex_fd_with_cs(fd, cs, print_value));
}

int	print_hex_fd_with_cs(int fd, t_cs *cs, unsigned int value)
{
	char	*pad_zero_str;
	int		print_len;

	if (value == 0)
		cs->flag_sharp = false;
	pad_zero_str = generate_ul_hex_with_cs(cs, value);
	if (pad_zero_str == NULL)
		return (-1);
	cs->flag_zero = false;
	print_len = t_conv_aligned_print(fd, cs, pad_zero_str);
	free(pad_zero_str);
	return (print_len);
}
