/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 18:58:39 by tookuyam          #+#    #+#             */
/*   Updated: 2023/10/22 16:44:30 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

static char		*_get_next_line(char **str, int fd, char **leftovers);
static char		*ft_strjoin_fd(char *left, int fd, int *is_eof);
static char		*ft_substrchr(char const *str, char sep);

char	*get_next_line(int fd)
{
	static char	*pool;
	char		*line;
	char		*leftovers;

	if (pool == NULL)
		pool = ft_substrchr("", '\0');
	if (pool == NULL)
		return (NULL);
	line = _get_next_line(&pool, fd, &leftovers);
	if (line == NULL)
	{
		pool = free_manager(&pool);
		return (NULL);
	}
	free_manager(&pool);
	pool = leftovers;
	return (line);
}

static char	*_get_next_line(char **str, int fd, char **leftovers)
{
	char	*joined;
	int		is_eof;
	char	*line;

	is_eof = 0;
	while (ft_strchr(*str, '\n') == NULL && is_eof == 0)
	{
		is_eof = 0;
		joined = ft_strjoin_fd(*str, fd, &is_eof);
		if (joined == NULL || ft_strlenchr(joined, '\0') == 0)
			return (free_manager(&joined));
		free_manager(str);
		*str = joined;
	}
	line = ft_substrchr(*str, '\n');
	if (line == NULL)
		return (NULL);
	*leftovers = ft_substrchr((*str) + ft_strlenchr(line, '\0'), '\0');
	if (*leftovers == NULL)
		return (free_manager(&line));
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
		return (free_manager(&right));
	*is_eof = (ft_strlenchr(right, '\0') == 0);
	count = ft_strlenchr(left, '\0') + ft_strlenchr(right, '\0') + 1;
	joined = (char *)malloc(sizeof(char) * count);
	if (joined == NULL)
		return (free_manager(&right));
	index = 0;
	while (*left != '\0')
		joined[index++] = *(left++);
	right_iter = right;
	while (*right_iter != '\0')
		joined[index++] = *(right_iter++);
	joined[index] = '\0';
	free_manager(&right);
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
