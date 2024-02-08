/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_uint_fd_bonus.c                              :+:      :+:    :+:   */
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
#include "conversion_specification_bonus.h"
#include "string_util_bonus.h"
#include "aligned_print_bonus.h"

int	print_uint_fd(int fd, t_conv_specification *cs, va_list args)
{
	char	*num_str;
	char	*pad_zero_str;
	int		print_len;

	num_str = ft_utoa(va_arg(args, unsigned int));
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
