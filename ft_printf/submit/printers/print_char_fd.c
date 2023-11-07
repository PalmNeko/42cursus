/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:59:21 by tookuyam          #+#    #+#             */
/*   Updated: 2023/11/07 14:19:50 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "aligned_print.h"

int	print_char_fd(int fd, t_conv_specification *cs, va_list args)
{
	int				print_len;
	unsigned char	print_buf[2];

	print_buf[0] = va_arg(args, unsigned char);
	print_buf[1] = '\0';
	print_len = t_conv_aligned_print(fd, cs, print_buf);
	return (print_len);
}
