/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_ul_hex_with_cs_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 14:46:38 by tookuyam          #+#    #+#             */
/*   Updated: 2024/02/11 16:40:21 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "conversion_specification_bonus.h"
#include "string_util_bonus.h"

static char	*set_prefix_with_cs(t_cs *cs, const char *str);

char	*generate_ul_hex_with_cs(t_cs *cs, unsigned long value)
{
	char	*num_str;
	char	*tmp;

	if (cs->is_specified_precision == true && cs->precision == 0 && value == 0)
		num_str = ft_strdup("");
	else
		num_str = ft_ultoa_base_str(value, "0123456789abcdef");
	if (num_str == NULL)
		return (NULL);
	tmp = set_prefix_with_cs(cs, num_str);
	free(num_str);
	if (tmp == NULL)
		return (NULL);
	num_str = tmp;
	tmp = zero_pad_with_cs(cs, num_str);
	free(num_str);
	if (tmp == NULL)
		return (NULL);
	num_str = tmp;
	return (num_str);
}

static char	*set_prefix_with_cs(t_cs *cs, const char *str)
{
	if (cs->flag_sharp != false)
		return (ft_strjoin("0x", str));
	return (ft_strdup(str));
}
