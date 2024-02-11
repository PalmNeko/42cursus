/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aligned_print.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:56:23 by tookuyam          #+#    #+#             */
/*   Updated: 2024/02/11 14:37:20 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALIGNED_PRINT_H
# define ALIGNED_PRINT_H

# include <stddef.h>
# include "conversion_specification.h"

int	left_aligned_print(int fd, const char *str, size_t min_len);
int	right_aligned_print(int fd, const char *str, size_t min_len, int pad_zero);
int	t_conv_aligned_print(int fd, t_cs *cs, const char *str);
int	left_aligned_print_char(int fd, char c, size_t min_len);
int	right_aligned_print_char(int fd, char c, size_t min_len, int pad_zero);
int	t_conv_aligned_print_char(int fd, t_cs *cs, char c);

#endif
