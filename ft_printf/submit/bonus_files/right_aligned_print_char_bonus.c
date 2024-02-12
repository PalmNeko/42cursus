/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   right_aligned_print_char_bonus.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:51:24 by tookuyam          #+#    #+#             */
/*   Updated: 2024/02/12 15:37:03 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <limits.h>
#include "libft.h"
#include "string_util_bonus.h"

int	right_aligned_print_char(int fd, char c, size_t min_len, int pad_zero)
{
	size_t	len;
	char	*pad_str;
	int		now_print_len;

	len = 1;
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
	if (ft_putchar_fd(c, fd) < 0)
		return (-1);
	return (len);
}
