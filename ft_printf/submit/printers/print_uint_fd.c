/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_uint_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:31:31 by tookuyam          #+#    #+#             */
/*   Updated: 2023/11/08 16:01:51 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include "libft.h"
#include "conversion_specification.h"
#include "conversion_specification_utils.h"
#include "string_util.h"
#include "aligned_print.h"

int	print_uint_fd_with_cs(int fd, t_conv_specification *cs, unsigned int value);

int print_uint_fd(int fd, t_conv_specification *cs, va_list args)
{
	int	value;

	value = va_arg(args, unsigned int);
	return (print_uint_fd_with_cs(fd, cs, value));
}

int	print_uint_fd_with_cs(int fd, t_conv_specification *cs, unsigned int value)
{
	char			*num_str;
	char			*pad_zero_str;
	int				print_len;

	if (is_set_zero_precision(cs) && value == 0)
		return (0);
	num_str = ft_utoa(value);
	if (num_str == NULL)
		return (-1);
	pad_zero_str = zero_pad_with_cs(cs, num_str);
	free(num_str);
	if (pad_zero_str == NULL)
		return (-1);
	cs->flag_zero = 0;
	print_len = t_conv_aligned_print(fd, cs, pad_zero_str);
	free(pad_zero_str);
	return (print_len);
}
