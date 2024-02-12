/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zero_pad_with_cs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:43:19 by tookuyam          #+#    #+#             */
/*   Updated: 2024/02/12 12:31:00 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversion_specification.h"
#include "string_util.h"
#include "libft.h"
#include <stdlib.h>
#include <stddef.h>

static char	*gen_zero_pad_num_str(char *num_str, int min_num_len);

char	*zero_pad_with_cs(t_cs *cs, char *num_str)
{
	int		pad_zero_min_width;

	pad_zero_min_width = 0;
	if (cs->is_specified_precision == true)
		pad_zero_min_width = cs->precision;
	else if (cs->flag_zero == true
		&& cs->is_specified_min_field_width == true
		&& cs->flag_minus == false)
		pad_zero_min_width = cs->minimum_field_width;
	if (num_str[0] == '-' && cs->is_specified_precision != true)
		pad_zero_min_width -= 1;
	return (gen_zero_pad_num_str(num_str, pad_zero_min_width));
}

static char	*gen_zero_pad_num_str(char *num_str, int min_num_len)
{
	char	*zero_pad_num;
	char	*zero_pad_num_unsigned;
	int		num_offset;

	if (num_str[0] == '-')
		num_offset = 1;
	else
		num_offset = 0;
	if (min_num_len < 0)
		min_num_len = 0;
	zero_pad_num_unsigned = pad_zero_str(
			num_str + num_offset, min_num_len);
	if (zero_pad_num_unsigned == NULL)
		return (NULL);
	if (num_str[0] != '-')
		return (zero_pad_num_unsigned);
	zero_pad_num = ft_strjoin("-", zero_pad_num_unsigned);
	free(zero_pad_num_unsigned);
	if (zero_pad_num == NULL)
		return (NULL);
	return (zero_pad_num);
}
