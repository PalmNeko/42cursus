/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_conv_specification_len_test.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:28:32 by tookuyam          #+#    #+#             */
/*   Updated: 2023/11/09 13:29:56 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tyctest.h"
#include "conversion_specification.h"

TEST(get_conv_specification_len, basic)
{
	EXPECT_EQ(get_conv_specification_len("%c %c %c"), 2);
}
