/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   right_aligned_print.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:45:37 by tookuyam          #+#    #+#             */
/*   Updated: 2023/11/08 16:06:04 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <limits.h>
#include "libft.h"
#include "string_util.h"

int	right_aligned_print(int fd, const char *str, size_t min_len, int pad_zero)
{
	size_t	len;
	char	*pad_str;

	len = ft_strlen(str);
	if (len > INT_MAX || min_len > INT_MAX)
		return (-1);
	if (pad_zero != 0)
		pad_str = "0";
	else
		pad_str = " ";
	if (len <= min_len)
		len += repeat_print_fd(fd, pad_str, (int)(min_len - len));
	if (len > INT_MAX)
		return (-1);
	ft_putstr_fd(str, fd);
	return (len);
}
