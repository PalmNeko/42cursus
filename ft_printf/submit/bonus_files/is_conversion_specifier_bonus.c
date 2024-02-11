/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_conversion_specifier_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:14:52 by tookuyam          #+#    #+#             */
/*   Updated: 2024/02/11 15:05:23 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

/** is it equal to conversion specifier character.
 * @param c check character.
 * @return return non-zero if `No`, return zero if `Yes`.
*/
bool	is_conversion_specifier(char c)
{
	if (c == 's'
		|| c == 'd'
		|| c == 'i'
		|| c == 'u'
		|| c == 'c'
		|| c == 'p'
		|| c == '%'
		|| c == 'x'
		|| c == 'X')
		return (true);
	return (0);
}
