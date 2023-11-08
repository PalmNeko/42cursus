/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_va_list_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:36:59 by tookuyam          #+#    #+#             */
/*   Updated: 2023/11/08 16:43:13 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversion_specification.h"
#include "printers.h"

int	print_va_list_fd(int fd, t_conv_specification *cs, va_list args)
{
	const t_relational_conversion_specifier_and_print_function	relation[] = {
	{.specifier = CS_LOWER_U, .p_function = print_uint_fd},
	{.specifier = CS_LOWER_D, .p_function = print_decimal_fd},
	{.specifier = CS_LOWER_I, .p_function = print_int_fd},
	{.specifier = CS_LOWER_C, .p_function = print_char_fd}};
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
