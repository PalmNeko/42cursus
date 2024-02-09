/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_decimal_fd_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:17:14 by tookuyam          #+#    #+#             */
/*   Updated: 2023/11/08 16:01:21 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include "conversion_specification_bonus.h"
#include "libft.h"
#include "string_util_bonus.h"
#include "aligned_print_bonus.h"
#include "conversion_specification_utils_bonus.h"

int	print_decimal_fd(int fd, t_conv_specification *cs, va_list args)
{
	char	*num_str;
	char	*pad_zero_str;
	char	*joined_sign_str;
	int		print_len;
	int		print_value;

	print_value = va_arg(args, int);
	if (is_set_zero_precision(cs) && print_value == 0)
		return (0);
	num_str = ft_itoa(print_value);
	if (num_str == NULL)
		return (-1);
	pad_zero_str = zero_pad_with_cs(cs, num_str);
	free(num_str);
	if (pad_zero_str == NULL)
		return (-1);
	joined_sign_str = add_sign_with_cs(cs, pad_zero_str);
	free(pad_zero_str);
	if (joined_sign_str == NULL)
		return (-1);
	cs->flag_zero = 0;
	print_len = t_conv_aligned_print(fd, cs, joined_sign_str);
	free(joined_sign_str);
	return (print_len);
}
