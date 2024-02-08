/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:13:56 by tookuyam          #+#    #+#             */
/*   Updated: 2023/11/06 13:43:10 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * is it equal to printf flags.
 * @param c check character.
 * @return return non-zero if `No`, return zero if `Yes`.
*/
int	is_flags(char c)
{
	if (c == '#'
		|| c == '0'
		|| c == '-'
		|| c == ' '
		|| c == '+')
		return (!0);
	return (0);
}
