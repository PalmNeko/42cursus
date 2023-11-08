/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   over_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:50:50 by tookuyam          #+#    #+#             */
/*   Updated: 2023/11/07 13:55:44 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

int	main(void)
{
	char	*big_str;
	size_t	size;
	int		result;

	size = sizeof(char) * (INT_MAX / 8);
	big_str = (char *)malloc(size);
	if (big_str == NULL)
		return (1);
	memset(big_str, 'a', size);
	big_str[size - 1] = '\0'; // if size < 0, occurs error.
	result = printf("%s%s%s%s%s%s%s%s%s%s%s%s%s\n",
		big_str,
		big_str,
		big_str,
		big_str,
		big_str,
		big_str,
		big_str,
		big_str,
		big_str,
		big_str,
		big_str,
		big_str,
		big_str);
	printf("%d\n", result);
	return (0);
}
