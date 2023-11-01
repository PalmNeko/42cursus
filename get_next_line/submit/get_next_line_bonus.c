/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 18:58:39 by tookuyam          #+#    #+#             */
/*   Updated: 2023/10/27 19:47:22 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdlib.h>
#include <unistd.h>

static t_pl	*get_target_pl(t_pl **pool, int fd);
static char	*_get_next_line(char **str, int fd, char **leftovers, int *is_eof);
static char	*ft_strjoin_fd(char *left, int fd, int *is_eof);
static char	*ft_substrchr(char const *str, char sep);
void		print_pool_list(t_pl *pool);

char	*get_next_line(int fd)
{
	static t_pl	*pool;
	char		*line;
	char		*leftovers;
	int			is_eof;
	t_pl		*target;

	if (read(fd, NULL, 0) < 0)
		return (NULL);
	target = get_target_pl(&pool, fd);
	if (target == NULL)
		return (pool_list_utils(&pool, NULL, 0, pl_clear));
	is_eof = 0;
	line = _get_next_line(&(target->str), fd, &leftovers, &is_eof);
	if (line == NULL && is_eof != 0)
		return (free_manager(NULL, &pool));
	else if (line == NULL)
		return (pool_list_utils(&pool, NULL, 0, pl_clear));
	if (target != NULL && target->previous == NULL)
		pool = target;
	if (line == NULL)
		return (NULL);
	free_manager(&(target->str), NULL);
	target->str = leftovers;
	return (line);
}

static t_pl	*get_target_pl(t_pl **pool, int fd)
{
	t_pl	*target;

	target = *pool;
	while (target != NULL && target->previous != NULL)
		target = target->previous;
	while (target != NULL && target->fd != fd)
		target = target->next;
	if (target == NULL)
	{
		target = pool_list_utils(NULL, NULL, fd, pl_new);
		if (target == NULL)
			return (NULL);
		if (*pool != NULL && target != NULL)
			pool_list_utils(pool, &target, 0, pl_add_front);
	}
	if (target->str == NULL)
		target->str = ft_substrchr("", '\0');
	if (target->str == NULL)
		return (free_manager(NULL, &target));
	*pool = target;
	return (target);
}

static char	*_get_next_line(char **str, int fd, char **leftovers, int *is_eof)
{
	char	*joined;
	char	*line;

	while (ft_strchr(*str, '\n') == NULL && *is_eof == 0)
	{
		joined = ft_strjoin_fd(*str, fd, is_eof);
		if (joined == NULL || ft_strlenchr(joined, '\0') == 0)
			return (free_manager(&joined, NULL));
		free_manager(str, NULL);
		*str = joined;
	}
	line = ft_substrchr(*str, '\n');
	if (line == NULL)
		return (NULL);
	*leftovers = ft_substrchr((*str) + ft_strlenchr(line, '\0'), '\0');
	if (*leftovers == NULL)
		return (free_manager(&line, NULL));
	return (line);
}

static char	*ft_strjoin_fd(char *left, int fd, int *is_eof)
{
	size_t	count;
	size_t	index;
	char	*right;
	char	*right_iter;
	char	*joined;

	right = read_str(fd, BUFFER_SIZE);
	if (right == NULL)
		return (free_manager(&right, NULL));
	count = ft_strlenchr(left, '\0') + ft_strlenchr(right, '\0') + 1;
	joined = (char *)malloc(sizeof(char) * count);
	if (joined == NULL)
		return (free_manager(&right, NULL));
	index = 0;
	while (*left != '\0')
		joined[index++] = *(left++);
	right_iter = right;
	while (*right_iter != '\0')
		joined[index++] = *(right_iter++);
	joined[index] = '\0';
	*is_eof = (ft_strlenchr(right, '\0') == 0);
	free_manager(&right, NULL);
	return (joined);
}

static char	*ft_substrchr(char const *str, char sep)
{
	char	*sub;
	char	*find;
	size_t	index;
	size_t	len;

	len = 0;
	find = ft_strchr(str, sep);
	if (find != NULL)
		len = (size_t)(find - str) + 1;
	else
		len = ft_strlenchr(str, '\0');
	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (sub == NULL)
		return (NULL);
	index = 0;
	while (str[index] != '\0' && index < len)
	{
		sub[index] = str[index];
		index++;
	}
	sub[index] = '\0';
	return (sub);
}
