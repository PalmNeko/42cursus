/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:26:23 by tookuyam          #+#    #+#             */
/*   Updated: 2024/02/06 12:25:32 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tyctest.h"
#include "ft_printf.h"
#include "ft_printf_test_tool.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <limits.h>

TEST(ft_printf, francinette)
{
	*failure_flag = 0;
	ASSERT_TRUE(check_ft_printf("\001\002\007\v\010\f\r\n"));
}
