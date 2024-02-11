/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdprint_cs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:36:59 by tookuyam          #+#    #+#             */
/*   Updated: 2024/02/11 14:37:20 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversion_specification.h"
#include "_ft_vdprint_cs.h"

int	ft_vdprint_cs(int fd, t_cs *cs, va_list args)
{
	const t_relational_conversion_specifier_and_print_function	relation[] = {
	{.specifier = CS_LOWER_S, .p_function = ft_vdprint_string_cs},
	{.specifier = CS_LOWER_P, .p_function = ft_vdprint_pointer_cs},
	{.specifier = CS_LOWER_C, .p_function = ft_vdprint_char_cs},
	{.specifier = CS_LOWER_D, .p_function = ft_vdprint_decimal_cs},
	{.specifier = CS_LOWER_U, .p_function = ft_vdprint_uint_cs},
	{.specifier = CS_LOWER_I, .p_function = ft_vdprint_int_cs},
	{.specifier = CS_LOWER_X, .p_function = ft_vdprint_hex_cs},
	{.specifier = CS_UPPER_X, .p_function = ft_vdprint_hex_upper_cs},
	{.specifier = CS_PERCENT, .p_function = ft_vdprint_percent_cs}};
	int															relation_size;
	int															index;

	relation_size = sizeof(relation) / sizeof(relation[0]);
	index = 0;
	while (index < relation_size)
	{
		if (relation[index].specifier == cs->conversion_specifier)
			return (relation[index].p_function(fd, cs, args));
		index++;
	}
	return (-1);
}
