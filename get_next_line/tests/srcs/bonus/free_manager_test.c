/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:56:15 by tookuyam          #+#    #+#             */
/*   Updated: 2023/11/02 13:18:21 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include "tyctest.h"
#include <stdlib.h>
#include <errno.h>

static t_pl	*new_t_pl(void)
{
	t_pl	*tmp;

	tmp = (t_pl *)malloc(sizeof(t_pl) * 1);
	if (tmp == NULL)
		return (NULL);
	tmp->fd = 0;
	tmp->next = NULL;
	tmp->previous = NULL;
	tmp->str = strdup("123");
	return (tmp);
}

static t_pl	*create_test_pl(void)
{
	t_pl	*left;
	t_pl	*right;
	t_pl	*center;

	left = new_t_pl();
	if (left == NULL)
		exit(1);
	right = new_t_pl();
	if (right == NULL)
		exit(1);
	center = new_t_pl();
	if (center == NULL)
		exit(1);
	left->next = center;
	center->previous = left;
	center->next = right;
	right->previous = center;
	return (left);
}

TEST(free_manager, free_string)
{
	char	*s1;

	s1 = (char *)malloc(sizeof(char) * 1);
	if (s1 == NULL)
		exit(errno);
	free_manager(&s1, NULL);
	EXPECT_TRUE(s1 == NULL);
}

TEST(free_manager, free_t_pl_basic)
{
	t_pl	*test;

	test = new_t_pl();
	if (test == NULL)
		exit(1);
	free_manager(NULL, &test);
	EXPECT_TRUE(test == NULL);
	ASSERT_TRUE(system("leaks -q bonus >> leaks.log") == 0);
}

TEST(free_manager, free_t_pl_more_left)
{
	t_pl	*test;

	test = create_test_pl();
	if (test == NULL)
		exit(1);
	free_manager(NULL, &test);
	ASSERT_TRUE(test != NULL);
	free_manager(NULL, &test);
	ASSERT_TRUE(test != NULL);
	free_manager(NULL, &test);
	ASSERT_TRUE(test == NULL);
	ASSERT_TRUE(system("leaks -q bonus >> leaks.log") == 0);
}

TEST(free_manager, free_t_pl_more_center)
{
	t_pl	*test;

	test = create_test_pl();
	if (test == NULL)
		exit(1);
	test = test->next;
	free_manager(NULL, &test);
	ASSERT_TRUE(test != NULL);
	free_manager(NULL, &test);
	ASSERT_TRUE(test != NULL);
	free_manager(NULL, &test);
	ASSERT_TRUE(test == NULL);
	ASSERT_TRUE(system("leaks -q bonus >> leaks.log") == 0);
}

TEST(free_manager, free_t_pl_more_right)
{
	t_pl	*test;

	test = create_test_pl();
	if (test == NULL)
		exit(1);
	test = test->next;
	test = test->next;
	free_manager(NULL, &test);
	ASSERT_TRUE(test != NULL);
	free_manager(NULL, &test);
	ASSERT_TRUE(test != NULL);
	free_manager(NULL, &test);
	ASSERT_TRUE(test == NULL);
	ASSERT_TRUE(system("leaks -q bonus >> leaks.log") == 0);
}
