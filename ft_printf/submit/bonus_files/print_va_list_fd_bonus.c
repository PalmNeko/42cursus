/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_va_list_fd_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:36:59 by tookuyam          #+#    #+#             */
/*   Updated: 2023/11/08 23:38:52 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversion_specification_bonus.h"
#include "printers_bonus.h"

int	ft_vdprint_cs(int fd, t_conv_specification *cs, va_list args)
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
