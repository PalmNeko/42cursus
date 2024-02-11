/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_printf_format_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:38:11 by tookuyam          #+#    #+#             */
/*   Updated: 2024/02/11 15:05:23 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "conversion_specification_bonus.h"

int	check_printf_format(const char *format)
{
	char	*conv_specification;
	int		tmp_len;

	conv_specification = ft_strchr(format, '%');
	while (conv_specification != NULL)
	{
		if (check_conv_specification_format(conv_specification) == 0)
			return (0);
		tmp_len = get_cs_len(conv_specification);
		if (tmp_len < 0)
			return (-1);
		conv_specification += tmp_len;
		conv_specification = ft_strchr(conv_specification, '%');
	}
	return (true);
}
