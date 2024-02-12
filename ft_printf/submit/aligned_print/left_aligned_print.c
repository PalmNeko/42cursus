/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left_aligned_print.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:57:17 by tookuyam          #+#    #+#             */
/*   Updated: 2024/02/12 16:40:11 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <limits.h>
#include "libft.h"
#include "string_util.h"

int	left_aligned_print(int fd, const char *str, size_t min_len)
{
	size_t	len;
	int		now_print_len;

	len = ft_strlen(str);
	if (len > INT_MAX || min_len > INT_MAX)
		return (-1);
	if (write(fd, str, len) < 0)
		return (-1);
	if (len <= min_len)
	{
		now_print_len = repeat_print_fd(fd, " ", (int)(min_len - len));
		if (now_print_len < 0)
			return (-1);
		len += now_print_len;
	}
	if (len > INT_MAX)
		return (-1);
	return (len);
}
