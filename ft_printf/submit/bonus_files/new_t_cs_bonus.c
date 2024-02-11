/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_t_cs_bonus.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:50:15 by tookuyam          #+#    #+#             */
/*   Updated: 2023/11/06 13:55:05 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversion_specification_bonus.h"
#include <stdlib.h>

t_cs	*new_t_cs(void)
{
	t_cs	*cs;

	cs = (t_cs *)malloc(
			sizeof(t_cs));
	if (cs == NULL)
		return (NULL);
	*cs = (t_cs){
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
