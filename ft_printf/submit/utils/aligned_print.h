/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aligned_print.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:56:23 by tookuyam          #+#    #+#             */
/*   Updated: 2023/11/07 14:07:35 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALIGNED_PRINT_H
# define ALIGNED_PRINT_H

#include <stddef.h>
#include "conversion_specification.h"

int	left_aligned_print(int fd, const char *str, size_t min_len);
int	right_aligned_print(int fd, const char *str, size_t min_len, int pad_zero);
int	t_conv_aligned_print(int fd, t_conv_specification *cs, const char *str);

#endif
