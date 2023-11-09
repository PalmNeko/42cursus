/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_conv_specification_format_test.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:16:23 by tookuyam          #+#    #+#             */
/*   Updated: 2023/11/09 13:25:46 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tyctest.h"
#include "conversion_specification.h"

TEST(check_conv_specification_format, basic)
{
	EXPECT_NE(check_conv_specification_format("%s"), 0);
	EXPECT_NE(check_conv_specification_format("%p"), 0);
	EXPECT_NE(check_conv_specification_format("%c"), 0);
	EXPECT_NE(check_conv_specification_format("%d"), 0);
	EXPECT_NE(check_conv_specification_format("%u"), 0);
	EXPECT_NE(check_conv_specification_format("%i"), 0);
	EXPECT_NE(check_conv_specification_format("%x"), 0);
	EXPECT_NE(check_conv_specification_format("%X"), 0);
	EXPECT_NE(check_conv_specification_format("%%"), 0);
}

TEST(check_conv_specification_format, advance)
{
	EXPECT_NE(check_conv_specification_format("%# - + 0123.221s"), 0);
}
