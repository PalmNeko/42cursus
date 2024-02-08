/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_specification_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:52:30 by tookuyam          #+#    #+#             */
/*   Updated: 2023/11/09 15:19:25 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stddef.h>
#include <unistd.h>

int	print_until_char_fd(int fd, const char *str, char c)
{
	size_t	len;

	len = 0;
	while (str[len] != c && str[len] != '\0' && len <= INT_MAX)
		len++;
	if (len > INT_MAX && str[len] != c && str[len] != '\0')
		return (-1);
	if (write(fd, str, len) < 0)
		return (-1);
	return ((int)len);
}
