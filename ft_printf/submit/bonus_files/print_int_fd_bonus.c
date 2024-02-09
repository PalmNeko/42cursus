/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int_fd_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:13:37 by tookuyam          #+#    #+#             */
/*   Updated: 2023/11/07 17:14:46 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printers_bonus.h"

int	print_int_fd(int fd, t_conv_specification *cs, va_list args)
{
	return (print_decimal_fd(fd, cs, args));
}
