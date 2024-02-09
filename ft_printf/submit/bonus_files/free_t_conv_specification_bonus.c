/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_t_conv_specification_bonus.c            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:14:31 by tookuyam          #+#    #+#             */
/*   Updated: 2023/11/06 14:16:10 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "conversion_specification_bonus.h"

void	free_t_conv_specification(t_conv_specification *ptr)
{
	free(ptr);
	return ;
}
