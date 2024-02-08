/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_repeat_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:31:36 by tookuyam          #+#    #+#             */
/*   Updated: 2023/11/07 14:40:26 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>
#include <stdint.h>
#include <stdlib.h>

char	*gen_repeat_str(const char *str, int repeat_cnt)
{
	size_t	len;
	size_t	size;
	char	*repeated;
	int		index;

	len = ft_strlen(str);
	if (repeat_cnt != 0 && len > SIZE_MAX / repeat_cnt)
		return (NULL);
	size = repeat_cnt * len + 1;
	repeated = (char *)malloc(sizeof(char) * size);
	if (repeated == NULL)
		return (NULL);
	index = 0;
	while (index < repeat_cnt)
	{
		ft_strlcpy(repeated + (len * index), str, size - (len * index));
		index++;
	}
	return (repeated);
}
