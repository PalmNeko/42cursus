/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:13:37 by tookuyam          #+#    #+#             */
/*   Updated: 2023/11/07 17:14:46 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_ft_vdprint_cs.h"

int	ft_vdprint_int_cs(int fd, t_conv_specification *cs, va_list args)
{
	return (ft_vdprint_decimal_cs(fd, cs, args));
}
