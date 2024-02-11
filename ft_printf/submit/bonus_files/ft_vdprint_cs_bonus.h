/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdprint_cs_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 14:33:51 by tookuyam          #+#    #+#             */
/*   Updated: 2024/02/11 14:44:47 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VDPRINT_CS_BONUS_H
# define FT_VDPRINT_CS_BONUS_H

# include <stdarg.h>
# include "conversion_specification_bonus.h"

int	ft_vdprint_cs(int fd, t_cs *cs, va_list args);

#endif
