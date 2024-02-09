/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 22:26:33 by tookuyam          #+#    #+#             */
/*   Updated: 2023/11/08 23:40:52 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include "conversion_specification.h"
#include "aligned_print.h"
#include "string_util.h"
#include "libft.h"

int print_hex_fd_with_cs(int fd, t_conv_specification *cs, unsigned int value);

int	print_hex_fd(int fd, t_conv_specification *cs, va_list args)
{
	unsigned int print_value;

	print_value = va_arg(args, unsigned int);
	return print_hex_fd_with_cs(fd, cs, print_value);
}

int print_hex_fd_with_cs(int fd, t_conv_specification *cs, unsigned int value)
{
	char	*num_str;
	char	*pad_zero_str;
	char	*tmp;
	int		print_len;

	num_str = ft_utoa_base_str(value, "0123456789abcdef");
	if (num_str == NULL)
		return (-1);
	if (cs->flag_sharp != 0)
	{
		tmp = ft_strjoin("0x", num_str);
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