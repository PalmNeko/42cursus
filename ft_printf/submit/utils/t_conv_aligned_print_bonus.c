/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_conv_aligned_print.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:08:00 by tookuyam          #+#    #+#             */
/*   Updated: 2023/11/08 16:06:17 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversion_specification.h"
#include "conversion_specification_utils.h"
#include "aligned_print.h"

int	t_conv_aligned_print(int fd, t_conv_specification *cs, const char *str)
{
	int	min_len;
	int	print_len;

	min_len = 0;
	if (cs->is_specified_min_field_width != 0)
		min_len = cs->minimum_field_width;
	print_len = -1;
	if (cs->flag_minus == !0)
		print_len = left_aligned_print(fd, str, min_len);
	else
		print_len = right_aligned_print(fd, str, min_len, cs->flag_zero);
	return (print_len);
}
