/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:26:23 by tookuyam          #+#    #+#             */
/*   Updated: 2024/02/11 16:07:39 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tyctest.h"
#include "ft_printf_test_tool.h"
#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

TEST(ft_printf, francinette)
{
	ASSERT_TRUE(check_ft_printf("%c ", '0' + 256));
	ASSERT_TRUE(check_ft_printf(" %c", '0' - 256));
	ASSERT_TRUE(check_ft_printf(" %c %c %c ", '0', 0, '1'));
	ASSERT_TRUE(check_ft_printf(" %c %c %c ", '2', '1', 0));
	ASSERT_TRUE(check_ft_printf(" %c %c %c ", 0, '1', '2'));
	ASSERT_TRUE(check_ft_printf("%p", ""));
	ASSERT_TRUE(check_ft_printf("%p", (void *)-14523));
}

TEST(ft_printf, d)
{
	int check_values[] = {
		0,
		1,
		-1,
		INT_MIN,
		INT_MAX
	};
	const int max_index = sizeof(check_values) / sizeof(check_values[0]);

	for (int i = 0; i < max_index; i++) {
		ASSERT_TRUE(check_ft_printf("%d\n", check_values[i]));
		ASSERT_TRUE(check_ft_printf("%#d\n", check_values[i]));
		ASSERT_TRUE(check_ft_printf("%-d\n", check_values[i]));
		ASSERT_TRUE(check_ft_printf("%+d\n", check_values[i]));
		ASSERT_TRUE(check_ft_printf("% d\n", check_values[i]));
		ASSERT_TRUE(check_ft_printf("%0d\n", check_values[i]));
		ASSERT_TRUE(check_ft_printf("%.0d\n", check_values[i]));
		ASSERT_TRUE(check_ft_printf("%.1d\n", check_values[i]));
	}
}

TEST(ft_printf, i)
{
	int check_values[] = {
		0,
		1,
		-1,
		INT_MIN,
		INT_MAX
	};
	const int max_index = sizeof(check_values) / sizeof(check_values[0]);

	for (int i = 0; i < max_index; i++) {
		ASSERT_TRUE(check_ft_printf("%i\n", check_values[i]));
		ASSERT_TRUE(check_ft_printf("%#i\n", check_values[i]));
		ASSERT_TRUE(check_ft_printf("%-i\n", check_values[i]));
		ASSERT_TRUE(check_ft_printf("%+i\n", check_values[i]));
		ASSERT_TRUE(check_ft_printf("% i\n", check_values[i]));
		ASSERT_TRUE(check_ft_printf("%0i\n", check_values[i]));
		ASSERT_TRUE(check_ft_printf("%.0i\n", check_values[i]));
		ASSERT_TRUE(check_ft_printf("%.1i\n", check_values[i]));
	}
}

TEST(ft_printf, c)
{
	char check_values[] = {
		'c',
		'a'
	};
	const int max_index = sizeof(check_values) / sizeof(check_values[0]);

	for (int i = 0; i < max_index; i++) {
		ASSERT_TRUE(check_ft_printf("%c\n", check_values[i]));
		ASSERT_TRUE(check_ft_printf("%#c\n", check_values[i]));
		ASSERT_TRUE(check_ft_printf("%-c\n", check_values[i]));
		ASSERT_TRUE(check_ft_printf("%+c\n", check_values[i]));
		ASSERT_TRUE(check_ft_printf("% c\n", check_values[i]));
		ASSERT_TRUE(check_ft_printf("%0c\n", check_values[i]));
		ASSERT_TRUE(check_ft_printf("%.0c\n", check_values[i]));
		ASSERT_TRUE(check_ft_printf("%.1c\n", check_values[i]));
	}
}

TEST(ft_printf, s)
{
	char *check_values[] = {
		"abc",
		"",
		NULL
	};
	const int max_index = sizeof(check_values) / sizeof(check_values[0]);

	for (int i = 0; i < max_index; i++) {
		ASSERT_TRUE(check_ft_printf("%s\n", check_values[i]));
		ASSERT_TRUE(check_ft_printf("%#s\n", check_values[i]));
		ASSERT_TRUE(check_ft_printf("%-s\n", check_values[i]));
		ASSERT_TRUE(check_ft_printf("%+s\n", check_values[i]));
		ASSERT_TRUE(check_ft_printf("% s\n", check_values[i]));
		ASSERT_TRUE(check_ft_printf("%0s\n", check_values[i]));
		ASSERT_TRUE(check_ft_printf("%.0s\n", check_values[i]));
		ASSERT_TRUE(check_ft_printf("%.1s\n", check_values[i]));
	}
}

TEST(ft_printf, p)
{
	void *check_values[] = {
		(void *)0,
		(void *)1,
		(void *)2,
		(void *)10,
		(void *)UINT_MAX,
	};
	const int max_index = sizeof(check_values) / sizeof(check_values[0]);

	for (int i = 0; i < max_index; i++) {
		ASSERT_TRUE(check_ft_printf("%p\n", check_values[i]));
		ASSERT_TRUE(check_ft_printf("%#p\n", check_values[i]));
		ASSERT_TRUE(check_ft_printf("%-p\n", check_values[i]));
		ASSERT_TRUE(check_ft_printf("%+p\n", check_values[i]));
		ASSERT_TRUE(check_ft_printf("% p\n", check_values[i]));
		ASSERT_TRUE(check_ft_printf("%0p\n", check_values[i]));
		ASSERT_TRUE(check_ft_printf("%.0p\n", check_values[i]));
		ASSERT_TRUE(check_ft_printf("%.1p\n", check_values[i]));
	}
}

TEST(ft_printf, u)
{
	unsigned int check_values[] = {
		0,
		1,
		2,
		10,
		UINT_MAX,
	};
	const int max_index = sizeof(check_values) / sizeof(check_values[0]);

	for (int i = 0; i < max_index; i++) {
		ASSERT_TRUE(check_ft_printf("%u\n", check_values[i]));
		ASSERT_TRUE(check_ft_printf("%#u\n", check_values[i]));
		ASSERT_TRUE(check_ft_printf("%-u\n", check_values[i]));
		ASSERT_TRUE(check_ft_printf("%+u\n", check_values[i]));
		ASSERT_TRUE(check_ft_printf("% u\n", check_values[i]));
		ASSERT_TRUE(check_ft_printf("%0u\n", check_values[i]));
		ASSERT_TRUE(check_ft_printf("%.0u\n", check_values[i]));
		ASSERT_TRUE(check_ft_printf("%.1u\n", check_values[i]));
	}
}

TEST(ft_printf, x)
{
	unsigned int check_values[] = {
		0,
		1,
		2,
		10,
		UINT_MAX,
	};
	const int max_index = sizeof(check_values) / sizeof(check_values[0]);

	for (int i = 0; i < max_index; i++) {
		ASSERT_TRUE(check_ft_printf("%x\n", check_values[i]));
		ASSERT_TRUE(check_ft_printf("%#x\n", check_values[i]));
		ASSERT_TRUE(check_ft_printf("%-x\n", check_values[i]));
		ASSERT_TRUE(check_ft_printf("%+x\n", check_values[i]));
		ASSERT_TRUE(check_ft_printf("% x\n", check_values[i]));
		ASSERT_TRUE(check_ft_printf("%0x\n", check_values[i]));
		ASSERT_TRUE(check_ft_printf("%.0x\n", check_values[i]));
		ASSERT_TRUE(check_ft_printf("%.1x\n", check_values[i]));
	}
}

TEST(ft_printf, X)
{
	unsigned int check_values[] = {
		0,
		1,
		2,
		10,
		UINT_MAX,
	};
	const int max_index = sizeof(check_values) / sizeof(check_values[0]);

	for (int i = 0; i < max_index; i++) {
		ASSERT_TRUE(check_ft_printf("%X\n", check_values[i]));
		ASSERT_TRUE(check_ft_printf("%#X\n", check_values[i]));
		ASSERT_TRUE(check_ft_printf("%-X\n", check_values[i]));
		ASSERT_TRUE(check_ft_printf("%+X\n", check_values[i]));
		ASSERT_TRUE(check_ft_printf("% X\n", check_values[i]));
		ASSERT_TRUE(check_ft_printf("%0X\n", check_values[i]));
		ASSERT_TRUE(check_ft_printf("%.0X\n", check_values[i]));
		ASSERT_TRUE(check_ft_printf("%.1X\n", check_values[i]));
	}
}

TEST(ft_printf, percent)
{
	ASSERT_TRUE(check_ft_printf("%%\n"));
	ASSERT_TRUE(check_ft_printf("%#%\n"));
	ASSERT_TRUE(check_ft_printf("%-%\n"));
	ASSERT_TRUE(check_ft_printf("%+%\n"));
	ASSERT_TRUE(check_ft_printf("% %\n"));
	ASSERT_TRUE(check_ft_printf("%0%\n"));
	ASSERT_TRUE(check_ft_printf("%.0%\n"));
	ASSERT_TRUE(check_ft_printf("%.1%\n"));
}
