/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdprint_char_cs.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:59:21 by tookuyam          #+#    #+#             */
/*   Updated: 2024/02/11 14:37:20 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "aligned_print.h"

int	print_char_fd_with_cs(int fd, t_cs *cs, char c);

int	ft_vdprint_char_cs(int fd, t_cs *cs, va_list args)
{
	int		print_len;
	char	value;

	value = va_arg(args, int);
	print_len = print_char_fd_with_cs(fd, cs, value);
	return (print_len);
}

int	print_char_fd_with_cs(int fd, t_cs *cs, char c)
{
	int		print_len;

	print_len = t_conv_aligned_print_char(fd, cs, c);
	return (print_len);
}
