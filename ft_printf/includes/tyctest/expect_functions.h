/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expect_functions.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 18:42:35 by tookuyam          #+#    #+#             */
/*   Updated: 2023/11/01 13:17:26 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPECT_FUNCTIONS_H
# define EXPECT_FUNCTIONS_H

# include "error_logger.h"
# include "generic_print.h"
# include "tyctest_assert_log_base.h"
# include <string.h>
# include "utils_str.h"

/**
 * test that condition is equal to true.
 * @param condition condition
 */
# define EXPECT_TRUE(condition) \
	EXPECT_CHECK(condition, \
		EXPECT_LOG("==", "true", condition, \
			VALUE_LOG_STRING_RAW, \
			VALUE_LOG_BOOL))

/**
 * test that condition is equal to true.
 * @param condition condition
 */
# define EXPECT_FALSE(condition) \
	EXPECT_CHECK(!(condition), \
		EXPECT_LOG("==", "false", condition, \
			VALUE_LOG_STRING_RAW, \
			VALUE_LOG_BOOL))

/**
 * test that expected is equal to actual.
 * @param expected actual
 */
# define EXPECT_EQ(expected, actual) \
	EXPECT_CHECK((expected == actual), \
		EXPECT_LOG("==", expected, actual, \
			VALUE_LOG_NUM, \
			VALUE_LOG_NUM))

/**
 * test that expected is not equal to actual.
 * @param expected actual
 */
# define EXPECT_NE(expected, actual) \
	EXPECT_CHECK((expected != actual), \
		EXPECT_LOG("!=", expected, actual, \
			VALUE_LOG_NUM, \
			VALUE_LOG_NUM))

/**
 * test that expected is less than actual.
 * @param expected actual
 */
# define EXPECT_LT(expected, actual) \
	EXPECT_CHECK((expected < actual), \
		EXPECT_LOG("<", expected, actual, \
			VALUE_LOG_NUM, \
			VALUE_LOG_NUM))

/**
 * test that expected is less than or equal to actual.
 * @param expected actual
 */
# define EXPECT_LE(expected, actual) \
	EXPECT_CHECK((expected <= actual), \
		EXPECT_LOG("<=", expected, actual, \
			VALUE_LOG_NUM, \
			VALUE_LOG_NUM))

/**
 * test that expected is greater than to actual.
 * @param expected actual
 */
# define EXPECT_GT(expected, actual) \
	EXPECT_CHECK((expected > actual), \
		EXPECT_LOG(">", expected, actual, \
			VALUE_LOG_NUM, \
			VALUE_LOG_NUM))

/**
 * test that expected is greater than or equal to actual.
 * @param expected actual
 */
# define EXPECT_GE(expected, actual) \
	EXPECT_CHECK((expected >= actual), \
		EXPECT_LOG(">=", expected, actual, \
			VALUE_LOG_NUM, \
			VALUE_LOG_NUM))

/**
 * test that expected is equal to actual.
 * @param expected expected value
 * @param actual actual value
 */
# define EXPECT_STREQ(expected, actual) \
	EXPECT_CHECK(strcmp(expected, actual) == 0, \
		EXPECT_LOG("==", expected, actual, \
			VALUE_LOG_STRING, \
			VALUE_LOG_STRING))

/**
 * test that expected is not equal to actual.
 * @param expected expected value
 * @param actual actual value
 */
# define EXPECT_STRNE(expected, actual) \
	EXPECT_CHECK(strcmp(expected, actual) != 0, \
		EXPECT_LOG("!=", expected, actual, \
			VALUE_LOG_STRING, \
			VALUE_LOG_STRING))

/**
 * test that expected is equal to actual. ignore character case.
 * @param expected expected value
 * @param actual actual value
 */
# define EXPECT_STRCASEEQ(expected, actual) \
	EXPECT_CHECK(stricmp(expected, actual) == 0, \
		EXPECT_LOG("==", expected, actual, \
			VALUE_LOG_STRING, \
			VALUE_LOG_STRING))

/**
 * test that expected is not equal to actual. ignore character case.
 * @param expected expected value
 * @param actual actual value
 */
# define EXPECT_STRCASENE(expected, actual) \
	EXPECT_CHECK(stricmp(expected, actual) != 0, \
		EXPECT_LOG("!=", expected, actual, \
			VALUE_LOG_STRING, \
			VALUE_LOG_STRING))

#endif
