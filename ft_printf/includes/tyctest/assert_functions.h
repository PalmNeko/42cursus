/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assert_functions.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 18:36:46 by tookuyam          #+#    #+#             */
/*   Updated: 2023/11/01 13:21:21 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASSERT_FUNCTIONS_H
# define ASSERT_FUNCTIONS_H

# include "error_logger.h"
# include "generic_print.h"
# include "tyctest_assert_log_base.h"

/**
 * test that condition is equal to true.
 * @throw
 * @param condition condition
 */
# define ASSERT_TRUE(condition) \
	ASSERT_CHECK(condition, \
		ASSERT_LOG("==", "true", condition, \
			VALUE_LOG_STRING_RAW, \
			VALUE_LOG_BOOL))

/**
 * test that condition is equal to false.
 * @throw
 * @param condition condition
 */
# define ASSERT_FALSE(condition) \
	ASSERT_CHECK(!(condition), \
		ASSERT_LOG("==", "false", condition, \
			VALUE_LOG_STRING_RAW, \
			VALUE_LOG_BOOL))

/**
 * test that expected is equal to actual.
 * @throw
 * @param expected actual
 */
# define ASSERT_EQ(expected, actual) \
	ASSERT_CHECK((expected == actual), \
		ASSERT_LOG("==", expected, actual, \
			VALUE_LOG_NUM, \
			VALUE_LOG_NUM))

/**
 * test that expected is not equal to actual.
 * @throw
 * @param expected actual
 */
# define ASSERT_NE(expected, actual) \
	ASSERT_CHECK((expected != actual), \
		ASSERT_LOG("!=", expected, actual, \
			VALUE_LOG_NUM, \
			VALUE_LOG_NUM))

/**
 * test that expected is less than actual.
 * @throw
 * @param expected actual
 */
# define ASSERT_LT(expected, actual) \
	ASSERT_CHECK((expected < actual), \
		ASSERT_LOG("<", expected, actual, \
			VALUE_LOG_NUM, \
			VALUE_LOG_NUM))

/**
 * test that expected is less than or equal to actual.
 * @throw
 * @param expected actual
 */
# define ASSERT_LE(expected, actual) \
	ASSERT_CHECK((expected <= actual), \
		ASSERT_LOG("<=", expected, actual, \
			VALUE_LOG_NUM, \
			VALUE_LOG_NUM))

/**
 * test that expected is greater than to actual.
 * @throw
 * @param expected actual
 */
# define ASSERT_GT(expected, actual) \
	ASSERT_CHECK((expected > actual), \
		ASSERT_LOG(">", expected, actual, \
			VALUE_LOG_NUM, \
			VALUE_LOG_NUM))

/**
 * test that expected is greater than or equal to actual.
 * @throw
 * @param expected actual
 */
# define ASSERT_GE(expected, actual) \
	ASSERT_CHECK((expected >= actual), \
		ASSERT_LOG(">=", expected, actual, \
			VALUE_LOG_NUM, \
			VALUE_LOG_NUM))

/**
 * test that expected is equal to actual.
 * @throw
 * @param expected expected value
 * @param actual actual value
 */
# define ASSERT_STREQ(expected, actual) \
	ASSERT_CHECK(strcmp(expected, actual) == 0, \
		ASSERT_LOG("==", expected, actual, \
			VALUE_LOG_STRING, \
			VALUE_LOG_STRING))

/**
 * test that expected is not equal to actual.
 * @throw
 * @param expected expected value
 * @param actual actual value
 */
# define ASSERT_STRNE(expected, actual) \
	ASSERT_CHECK(strcmp(expected, actual) != 0, \
		ASSERT_LOG("!=", expected, actual, \
			VALUE_LOG_STRING, \
			VALUE_LOG_STRING))

/**
 * test that expected is equal to actual. ignore character case.
 * @throw
 * @param expected expected value
 * @param actual actual value
 */
# define ASSERT_STRCASEEQ(expected, actual) \
	ASSERT_CHECK(stricmp(expected, actual) == 0, \
		ASSERT_LOG("==", expected, actual, \
			VALUE_LOG_STRING, \
			VALUE_LOG_STRING))

/**
 * test that expected is not equal to actual. ignore character case.
 * @throw
 * @param expected expected value
 * @param actual actual value
 */
# define ASSERT_STRCASENE(expected, actual) \
	ASSERT_CHECK(stricmp(expected, actual) != 0, \
		ASSERT_LOG("!=", expected, actual, \
			VALUE_LOG_STRING, \
			VALUE_LOG_STRING))

#endif