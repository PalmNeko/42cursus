/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left_aligned_print.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:57:17 by tookuyam          #+#    #+#             */
/*   Updated: 2023/11/06 17:44:37 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <limits.h>
#include "libft.h"
#include "string_util.h"

int	left_aligned_print(int fd, const char *str, size_t min_len)
{
	size_t	len;

	len = ft_strlen(str);
	if (len > INT_MAX || min_len > INT_MAX)
		return (-1);
	ft_putstr_fd(str, fd);
	if (len <= min_len)
		len += repeat_print_fd(fd, " ", (int)(min_len - len));
	if (len > INT_MAX)
		return (-1);
	return (len);
}
