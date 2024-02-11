/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdprint_percent_cs_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 23:18:58 by tookuyam          #+#    #+#             */
/*   Updated: 2024/02/11 14:37:20 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdarg.h>
#include "conversion_specification_bonus.h"
#include "libft.h"
#include "_ft_vdprint_cs_bonus.h"

int	ft_vdprint_percent_cs(int fd, t_cs *cs, va_list args)
{
	int				print_len;

	args = 0;
	print_len = print_char_fd_with_cs(fd, cs, '%');
	return (print_len);
}
