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

int	print_va_list_fd(int fd, t_conv_specification *cs, va_list args)
{
	const t_relational_conversion_specifier_and_print_function	relation[] = {
	{.specifier = CS_LOWER_S, .p_function = print_string_fd},
	{.specifier = CS_LOWER_P, .p_function = print_pointer_fd},
	{.specifier = CS_LOWER_C, .p_function = print_char_fd},
	{.specifier = CS_LOWER_D, .p_function = print_decimal_fd},
	{.specifier = CS_LOWER_U, .p_function = print_uint_fd},
	{.specifier = CS_LOWER_I, .p_function = print_int_fd},
	{.specifier = CS_LOWER_X, .p_function = print_hex_fd},
	{.specifier = CS_UPPER_X, .p_function = print_hex_upper_fd},
	{.specifier = CS_PERCENT, .p_function = print_percent_fd}};
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
