/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_print_fd_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:03:12 by tookuyam          #+#    #+#             */
/*   Updated: 2024/02/12 16:23:12 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>
#include <stdio.h>

int	repeat_print_fd(int fd, const char *str, int repeat_cnt)
{
	int		cnt;
	size_t	print_len;

	print_len = ft_strlen(str);
	if (print_len == 0)
		return (0);
	if (repeat_cnt < 0)
		return (-1);
	if (repeat_cnt > (int)(INT_MAX / print_len))
		return (-1);
	cnt = 0;
	while (cnt < repeat_cnt)
	{
		if (write(fd, str, print_len) < 0)
			return (-1);
		cnt++;
	}
	return (print_len * repeat_cnt);
}
