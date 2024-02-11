/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_flag_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:13:56 by tookuyam          #+#    #+#             */
/*   Updated: 2024/02/11 15:05:23 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

/**
 * is it equal to printf flags.
 * @param c check character.
 * @return return non-zero if `No`, return zero if `Yes`.
*/
bool	is_flags(char c)
{
	if (c == '#'
		|| c == '0'
		|| c == '-'
		|| c == ' '
		|| c == '+')
		return (true);
	return (0);
}
