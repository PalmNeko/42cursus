/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdprint_pointer_cs.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 23:34:48 by tookuyam          #+#    #+#             */
/*   Updated: 2024/02/11 15:11:44 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdarg.h>
#include <stdlib.h>
#include "conversion_specification.h"
#include "aligned_print.h"
#include "string_util.h"
#include "libft.h"
#include "_ft_vdprint_cs.h"

int	print_pointer_fd_with_cs(int fd, t_cs *cs, unsigned long value);

int	ft_vdprint_pointer_cs(int fd, t_cs *cs, va_list args)
{
	unsigned long	value;

	value = va_arg(args, unsigned long);
	return (print_pointer_fd_with_cs(fd, cs, value));
}

int	print_pointer_fd_with_cs(int fd, t_cs *cs, unsigned long value)
{
	char	*pad_zero_str;
	int		print_len;

	cs->flag_sharp = true;
	pad_zero_str = generate_ul_hex_with_cs(cs, value);
	if (pad_zero_str == NULL)
		return (-1);
	cs->flag_zero = false;
	print_len = t_conv_aligned_print(fd, cs, pad_zero_str);
	free(pad_zero_str);
	return (print_len);
}
