/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_sign_with_cs_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:44:08 by tookuyam          #+#    #+#             */
/*   Updated: 2023/11/07 16:45:14 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversion_specification_bonus.h"
#include "libft.h"

char	*add_sign_with_cs(t_conv_specification *cs, char *num_str)
{
	char	*joined_str;

	joined_str = NULL;
	if (num_str[0] == '-')
		return (ft_strdup(num_str));
	else if (cs->flag_plus != 0)
		return (ft_strjoin("+", num_str));
	else if (cs->flag_space != 0)
		return (ft_strjoin(" ", num_str));
	else
		return (ft_strdup(num_str));
	return (NULL);
}
