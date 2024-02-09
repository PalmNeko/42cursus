/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percent_fd_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 23:18:58 by tookuyam          #+#    #+#             */
/*   Updated: 2023/11/09 14:53:29 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdarg.h>
#include "conversion_specification_bonus.h"
#include "aligned_print_bonus.h"
#include "libft.h"

int	ft_vdprint_percent_cs(int fd, t_conv_specification *cs, va_list args)
{
	int				print_len;

	args = 0;
	print_len = t_conv_aligned_print_char(fd, cs, '%');
	return (print_len);
}
