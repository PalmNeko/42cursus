/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_specification_utils_bonus.h             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:14:11 by tookuyam          #+#    #+#             */
/*   Updated: 2023/11/08 23:48:41 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERSION_SPECIFICATION_UTILS_BONUS_H
# define CONVERSION_SPECIFICATION_UTILS_BONUS_H

# include "conversion_specification_bonus.h"
# include <stdbool.h>

int	is_flags(char c);
int	is_conversion_specifier(char c);
bool is_set_zero_precision(t_conv_specification *cs);

#endif
