/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   right_aligned_print_char.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:51:24 by tookuyam          #+#    #+#             */
/*   Updated: 2023/11/09 15:26:03 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <limits.h>
#include "libft.h"
#include "string_util.h"

int	right_aligned_print_char(int fd, char c, size_t min_len, int pad_zero)
{
	size_t	len;
	char	*pad_str;

	len = 1;
	if (pad_zero != 0)
		pad_str = "0";
	else
		pad_str = " ";
	if (len <= min_len)
		len += repeat_print_fd(fd, pad_str, (int)(min_len - len));
	if (len > INT_MAX)
		return (-1);
	if (ft_putchar_fd(c, fd) < 0)
		return (-1);
	return (len);
}
