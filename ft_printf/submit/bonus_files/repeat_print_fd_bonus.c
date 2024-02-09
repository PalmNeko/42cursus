/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_print_fd_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:03:12 by tookuyam          #+#    #+#             */
/*   Updated: 2023/11/09 15:26:57 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	repeat_print_fd(int fd, const char *str, int repeat_cnt)
{
	int	cnt;
	int	print_len;

	print_len = ft_strlen(str);
	cnt = 0;
	while (cnt < repeat_cnt)
	{
		if (ft_putstr_fd(str, fd) < 0)
			return (-1);
		cnt++;
	}
	return (print_len * repeat_cnt);
}
