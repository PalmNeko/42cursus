/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left_aligned_print_char_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:57:17 by tookuyam          #+#    #+#             */
/*   Updated: 2023/11/09 15:25:42 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <limits.h>
#include "libft.h"
#include "string_util_bonus.h"

int	left_aligned_print_char(int fd, char c, size_t min_len)
{
	size_t	len;

	len = 1;
	if (ft_putchar_fd(c, fd) < 0)
		return (-1);
	if (len <= min_len)
		len += repeat_print_fd(fd, " ", (int)(min_len - len));
	if (len > INT_MAX)
		return (-1);
	return (len);
}
