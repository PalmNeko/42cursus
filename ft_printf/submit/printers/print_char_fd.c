/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:59:21 by tookuyam          #+#    #+#             */
/*   Updated: 2023/11/09 13:57:03 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "aligned_print.h"

int print_char_fd_with_cs(int fd, t_conv_specification *cs, char c);
int print_char_fd_with_cs_str(int fd, t_conv_specification *cs, char *str);

int	print_char_fd(int fd, t_conv_specification *cs, va_list args)
{
	int				print_len;
	char	value;

	value = va_arg(args, int);
	return print_len = print_char_fd_with_cs(fd, cs, value);
	return (print_len);
}

int print_char_fd_with_cs(int fd, t_conv_specification *cs, char c)
{
	int		print_len;
	char	*str;

	str = (char []){c, '\0'};
	print_len = print_char_fd_with_cs_str(fd, cs, str);
	return (print_len);
}

int print_char_fd_with_cs_str(int fd, t_conv_specification *cs, char *str)
{
	int print_len;

	print_len = t_conv_aligned_print(fd, cs, str);
	return (print_len);
}
