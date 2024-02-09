/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_conversion_specifier.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:14:52 by tookuyam          #+#    #+#             */
/*   Updated: 2023/11/06 13:23:38 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** is it equal to conversion specifier character.
 * @param c check character.
 * @return return non-zero if `No`, return zero if `Yes`.
*/
int	is_conversion_specifier(char c)
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
		return (!0);
	return (0);
}
