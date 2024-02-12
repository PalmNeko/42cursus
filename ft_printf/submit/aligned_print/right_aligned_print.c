/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   right_aligned_print.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:45:37 by tookuyam          #+#    #+#             */
/*   Updated: 2024/02/12 16:25:31 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <limits.h>
#include <stdio.h>
#include "libft.h"
#include "string_util.h"

int	right_aligned_print(int fd, const char *str, size_t min_len, int pad_zero)
{
	size_t	len;
	char	*pad_str;
	int		now_print_len;

	len = ft_strlen(str);
	if (len > INT_MAX || min_len > INT_MAX)
		return (-1);
	if (pad_zero != 0)
		pad_str = "0";
	else
		pad_str = " ";
	if (len <= min_len)
	{
		now_print_len = repeat_print_fd(fd, pad_str, (int)(min_len - len));
		if (now_print_len < 0)
			return (-1);
		len += now_print_len;
	}
	if (len > INT_MAX)
		return (-1);
	if (write(fd, str, ft_strlen(str)) < 0)
		return (-1);
	return (len);
}
