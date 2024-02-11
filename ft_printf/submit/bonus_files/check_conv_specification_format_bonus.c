/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_conv_specification_format_bonus.c            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 19:26:35 by tookuyam          #+#    #+#             */
/*   Updated: 2024/02/11 15:05:23 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include "libft.h"
#include "conversion_specification_utils_bonus.h"

int	check_conv_specification_format(const char *cs_format)
{
	int	tmp;

	if (*cs_format != '%')
		return (0);
	while (is_flags(*cs_format))
		cs_format++;
	tmp = ft_atoi(cs_format);
	if (errno == ERANGE)
		return (0);
	while (ft_isdigit(*cs_format))
		cs_format++;
	if (*cs_format == '.')
		cs_format++;
	tmp = ft_atoi(cs_format);
	if (errno == ERANGE)
		return (0);
	while (ft_isdigit(*cs_format))
		cs_format++;
	if (! is_conversion_specifier(*cs_format))
		return (0);
	return (true);
}
