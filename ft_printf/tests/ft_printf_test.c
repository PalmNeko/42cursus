/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:26:23 by tookuyam          #+#    #+#             */
/*   Updated: 2023/11/09 15:17:40 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tyctest.h"
#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

TEST(ft_printf, francinette)
{
	*failure_flag = 0;
	printf("%d\n", ft_printf("\001\002\007\v\010\f\r\n"));
}
