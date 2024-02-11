/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zero_pad_with_cs_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:43:19 by tookuyam          #+#    #+#             */
/*   Updated: 2024/02/11 15:10:01 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversion_specification_bonus.h"
#include "string_util_bonus.h"

char	*zero_pad_with_cs(t_cs *cs, char *num_str)
{
	int		pad_zero_min_width;

	pad_zero_min_width = 0;
	if (cs->is_specified_precision != false)
		pad_zero_min_width = cs->precision;
	else if (cs->flag_zero != false
		&& cs->is_specified_min_field_width != false
		&& cs->flag_minus == false)
		pad_zero_min_width = cs->minimum_field_width;
	return (gen_zero_pad_num_str(num_str, pad_zero_min_width));
}
