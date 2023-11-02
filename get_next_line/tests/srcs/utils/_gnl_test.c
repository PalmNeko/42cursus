/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _gnl_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:16:37 by tookuyam          #+#    #+#             */
/*   Updated: 2023/11/02 17:18:30 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include "test_utils_bonus.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int	_gnl_test(int fd, char *to_be, int is_eof)
{
	static char	*pool;
	char		*line;
	char		*leftovers;
	int			comp_result;
	int			inner_is_eof;

	if (pool == NULL)
		pool = ft_substrchr("", 'a');
	if (pool == NULL)
		return (-1);
	else if (fd < 0)
	{
		free(pool);
		pool = NULL;
		return (0);
	}
	inner_is_eof = 0;
	line = _get_next_line(&pool, fd, &leftovers, &inner_is_eof);
	if (line != NULL)
	{
		free(pool);
		pool = leftovers;
	}
	else
	{
		free(pool);
		pool = NULL;
	}
	if (inner_is_eof != is_eof)
		comp_result = 1;
	else if (line == NULL && to_be == NULL)
		comp_result = 0;
	else if (line == NULL || to_be == NULL)
		comp_result = 2;
	else
		comp_result = strcmp(line, to_be);
	free(line);
	return (comp_result);
}
