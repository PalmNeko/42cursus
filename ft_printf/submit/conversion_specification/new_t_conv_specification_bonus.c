/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_t_conv_specification_bonus.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:50:15 by tookuyam          #+#    #+#             */
/*   Updated: 2023/11/06 13:55:05 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversion_specification_bonus.h"
#include <stdlib.h>

t_conv_specification	*new_t_conv_specification(void)
{
	t_conv_specification	*cs;

	cs = (t_conv_specification *)malloc(
			sizeof(t_conv_specification));
	if (cs == NULL)
		return (NULL);
	*cs = (t_conv_specification){
		.conversion_specifier = CS_NONE,
		.flag_minus = 0,
		.flag_plus = 0,
		.flag_sharp = 0,
		.flag_space = 0,
		.flag_zero = 0,
		.is_specified_min_field_width = 0,
		.is_specified_precision = 0,
		.minimum_field_width = 0,
		.precision = 0,
	};
	return (cs);
}
