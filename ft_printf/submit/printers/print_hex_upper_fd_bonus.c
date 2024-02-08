/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_upper_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 22:53:22 by tookuyam          #+#    #+#             */
/*   Updated: 2023/11/08 23:41:59 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>
#include "conversion_specification.h"
#include "aligned_print.h"
#include "string_util.h"
#include "libft.h"

int	print_hex_upper_fd(int fd, t_conv_specification *cs, va_list args)
{
	char	*num_str;
	char	*pad_zero_str;
	char	*tmp;
	int		print_len;

	num_str = ft_utoa_base_str(va_arg(args, unsigned int), "0123456789ABCDEF");
	if (num_str == NULL)
		return (-1);
	if (cs->flag_sharp != 0)
	{
		tmp = ft_strjoin("0X", num_str);
		free(num_str);
		if (tmp == NULL)
			return (-1);
		num_str = tmp;
	}
	pad_zero_str = zero_pad_with_cs(cs, num_str);
	free(num_str);
	if (pad_zero_str == NULL)
		return (-1);
	cs->flag_zero = 0;
	print_len = t_conv_aligned_print(fd, cs, pad_zero_str);
	free(pad_zero_str);
	return (print_len);
}
