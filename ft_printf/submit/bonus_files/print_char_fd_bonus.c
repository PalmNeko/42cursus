/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char_fd_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:59:21 by tookuyam          #+#    #+#             */
/*   Updated: 2023/11/09 13:57:03 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "aligned_print_bonus.h"

int	ft_vdprint_char_cs(int fd, t_conv_specification *cs, va_list args)
{
	int				print_len;
	unsigned char	print_buf;

	print_buf = va_arg(args, int);
	print_len = t_conv_aligned_print_char(fd, cs, print_buf);
	return (print_len);
}
