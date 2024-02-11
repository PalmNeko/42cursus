/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cs_len_bonus.c           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:31:43 by tookuyam          #+#    #+#             */
/*   Updated: 2023/11/06 13:26:20 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "conversion_specification_bonus.h"
#include "libft.h"
#include "conversion_specification_utils_bonus.h"

/**
 * get length of one conversion specification.
 * @param format conversion specification format. this format needs at start '%'.
 * @return return conversion specification length if of success.
 * negative value if of error.
*/
int	get_cs_len(const char *format)
{
	size_t	index;

	index = 0;
	if (format[index++] != '%')
		return (-1);
	while (is_flags(format[index]))
		index++;
	while ('1' <= format[index] && format[index] <= '9')
		index++;
	if (format[index] == '.')
		index++;
	while (ft_isdigit(format[index]))
		index++;
	if (! is_conversion_specifier(format[index++]))
		return (-1);
	return (index);
}
