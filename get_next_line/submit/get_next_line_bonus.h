/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 18:09:06 by tookuyam          #+#    #+#             */
/*   Updated: 2023/11/03 15:22:57 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stddef.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_pool_list {
	int					fd;
	char				*str;
	struct s_pool_list	*previous;
	struct s_pool_list	*next;
}	t_pl;

typedef enum e_list_operator {
	pl_new,
	pl_add_front,
	pl_clear
}	t_lo;

char	*get_next_line(int fd);
t_pl	*get_target_pl(t_pl **pool, int fd);
char	*_get_next_line(char **str, int fd, char **leftovers);
char	*ft_strjoin_fd(char *left, int fd, int *is_eof, size_t buf_size);
char	*ft_substrchr(char const *str, char sep);


size_t	ft_strlenchr(char const *s, char find);
void	*free_manager(char **str1, t_pl **delone);
char	*ft_strchr(const char *s, char find);
char	*read_str(int fd, size_t bufsize);
void	*pool_list_utils(t_pl **target1, t_pl **target2, int fd, t_lo ope);

void	infinite_loop_check(t_pl **pool); // TODO: delte this line

#endif