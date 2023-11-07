/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pad_zero_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:50:40 by tookuyam          #+#    #+#             */
/*   Updated: 2023/11/07 15:59:11 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*pad_zero_str(char *str, int min_len)
{
	size_t	len;
	size_t	size;
	int		pad_cnt;
	char	*pad_zero;

	len = ft_strlen(str);
	if (len >= min_len)
		return (ft_strdup(str));
	size = min_len + 1;
	pad_zero = (char *)malloc(sizeof(char) * size);
	if (pad_zero == NULL)
		return (NULL);
	pad_cnt = min_len - len;
	ft_memset(pad_zero, '0', pad_cnt);
	strlcpy(&pad_zero[pad_cnt], str, size - pad_cnt);
	return (pad_zero);
}
