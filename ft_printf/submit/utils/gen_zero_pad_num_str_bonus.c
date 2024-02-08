/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_zero_pad_num_str_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:02:03 by tookuyam          #+#    #+#             */
/*   Updated: 2023/11/08 16:02:20 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <limits.h>
#include <stdlib.h>
#include "string_util_bonus.h"
#include "libft.h"

char	*gen_zero_pad_num_str(char *num_str, int min_num_len)
{
	char	*zero_pad_num;
	char	*zero_pad_num_unsigned;
	int		num_offset;

	if (num_str[0] == '-')
		num_offset = 1;
	else
		num_offset = 0;
	zero_pad_num_unsigned = pad_zero_str(
			num_str + num_offset, min_num_len);
	if (zero_pad_num_unsigned == NULL)
		return (NULL);
	if (num_str[0] != '-')
		return (zero_pad_num_unsigned);
	zero_pad_num = ft_strjoin("-", zero_pad_num_unsigned);
	free(zero_pad_num_unsigned);
	if (zero_pad_num == NULL)
		return (NULL);
	return (zero_pad_num);
}
