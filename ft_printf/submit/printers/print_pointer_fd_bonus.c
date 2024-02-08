/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer_fd_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 23:34:48 by tookuyam          #+#    #+#             */
/*   Updated: 2023/11/09 14:30:45 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdarg.h>
#include <stdlib.h>
#include "conversion_specification_bonus.h"
#include "aligned_print_bonus.h"
#include "string_util_bonus.h"
#include "libft.h"

static char	*set_prefix_with_cs(t_conv_specification *cs, const char *str);

int	print_pointer_fd(int fd, t_conv_specification *cs, va_list args)
{
	char	*num_str;
	char	*pad_zero_str;
	char	*tmp;
	int		print_len;

	cs->flag_sharp = !0;
	num_str = ft_ultoa_base_str(
			va_arg(args, unsigned long), "0123456789abcdef");
	if (num_str == NULL)
		return (-1);
	tmp = set_prefix_with_cs(cs, num_str);
	free(num_str);
	if (tmp == NULL)
		return (-1);
	num_str = tmp;
	pad_zero_str = zero_pad_with_cs(cs, num_str);
	free(num_str);
	if (pad_zero_str == NULL)
		return (-1);
	cs->flag_zero = 0;
	print_len = t_conv_aligned_print(fd, cs, pad_zero_str);
	free(pad_zero_str);
	return (print_len);
}

static char	*set_prefix_with_cs(t_conv_specification *cs, const char *str)
{
	if (cs->flag_sharp != 0)
		return (ft_strjoin("0x", str));
	return (ft_strdup(str));
}
