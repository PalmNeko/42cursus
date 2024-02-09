/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_util_bonus.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:53:02 by tookuyam          #+#    #+#             */
/*   Updated: 2023/11/08 23:49:06 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_UTIL_BONUS_H
# define STRING_UTIL_BONUS_H

# include "conversion_specification_bonus.h"

int		repeat_print_fd(int fd, const char *str, int repeat_cnt);
char	*gen_repeat_str(const char *str, int repeat_cnt);
char	*pad_zero_str(char *str, int min_len);
char	*gen_zero_pad_num_str(char *num_str, int min_num_len);
char	*zero_pad_with_cs(t_conv_specification *cs, char *num_str);
char	*add_sign_with_cs(t_conv_specification *cs, char *num_str);

#endif
