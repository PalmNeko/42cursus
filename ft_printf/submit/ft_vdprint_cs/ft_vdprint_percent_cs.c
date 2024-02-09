/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percent_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 23:18:58 by tookuyam          #+#    #+#             */
/*   Updated: 2023/11/09 14:53:29 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdarg.h>
#include "conversion_specification.h"
#include "libft.h"
#include "_ft_vdprint_cs.h"

int	ft_vdprint_percent_cs(int fd, t_conv_specification *cs, va_list args)
{
	int				print_len;

	args = 0;
	print_len = print_char_fd_with_cs(fd, cs, '%');
	return (print_len);
}
