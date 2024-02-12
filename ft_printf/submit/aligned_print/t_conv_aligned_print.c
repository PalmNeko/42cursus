/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_conv_aligned_print.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:08:00 by tookuyam          #+#    #+#             */
/*   Updated: 2024/02/12 15:16:29 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversion_specification.h"
#include "conversion_specification_utils.h"
#include "aligned_print.h"

int	t_conv_aligned_print(int fd, t_cs *cs, const char *str)
{
	int	min_len;
	int	print_len;

	min_len = 0;
	if (cs->is_specified_min_field_width != false)
		min_len = cs->minimum_field_width;
	print_len = -1;
	if (cs->flag_minus == true)
		print_len = left_aligned_print(fd, str, min_len);
	else
		print_len = right_aligned_print(fd, str, min_len, cs->flag_zero);
	return (print_len);
}
