/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_specification_utils_bonus.h             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:14:11 by tookuyam          #+#    #+#             */
/*   Updated: 2024/02/11 15:05:30 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERSION_SPECIFICATION_UTILS_BONUS_H
# define CONVERSION_SPECIFICATION_UTILS_BONUS_H

# include "conversion_specification_bonus.h"
# include <stdbool.h>

bool	is_flags(char c);
bool	is_conversion_specifier(char c);
bool	is_set_zero_precision(t_cs *cs);

#endif
