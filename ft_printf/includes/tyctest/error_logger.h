/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_logger.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 14:55:11 by tookuyam          #+#    #+#             */
/*   Updated: 2023/10/31 18:47:48 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_LOGGER_H
# define ERROR_LOGGER_H

# include <stdio.h>
# include <stdlib.h>
# include "generic_print.h"
# include "utils_str.h"

int		is_raw_number(char *str);

/**
 * log place.
 * @param MSG (char *) message
 * @param FILE_NAME (char *) file name
 * @param LINE (char *) line number.
 * @param INDENT_NUM (number) indent space cnt.
 * @param MSG_WIDTH (number) output message width(left alignment)
 */
# define PLACE_LOG(MSG, FILE_NAME, LINE, INDENT_NUM, MSG_WIDTH) \
	fprintf(stderr, "%*s%-*s: %s:%d\n", \
		INDENT_NUM, "", MSG_WIDTH, MSG, FILE_NAME, LINE)

/**
 * log place for abort.
 * @param FILE_NAME (char *) file name
 * @param LINE (char *) line number.
 * @param INDENT_NUM (number) indent space cnt.
 * @param MSG_WIDTH (number) output message width(left alignment)
 */
# define PLACE_LOG_ABORT(FILE_NAME, LINE, INDENT_NUM, MSG_WIDTH) \
	PLACE_LOG("\033[31mAbort\033[m", FILE_NAME, LINE, INDENT_NUM, MSG_WIDTH); \

/**
 * log place for abort.
 * @param FILE_NAME (char *) file name
 * @param LINE (char *) line number.
 * @param INDENT_NUM (number) indent space cnt.
 * @param MSG_WIDTH (number) output message width(left alignment)
 */
# define PLACE_LOG_EXPECT(FILE_NAME, LINE, INDENT_NUM, MSG_WIDTH) \
	PLACE_LOG("\033[33mError\033[m", FILE_NAME, LINE, INDENT_NUM, MSG_WIDTH); \
/**
 * log string. around `"`
 * @param MSG (char *) message
 * @param RESULT (char *) value
 * @param ARG (char *) argument
 * @param INDENT_NUM (number) indent space cnt.
 * @param MSG_WIDTH (number) output message width(left alignment)
 */
# define VALUE_LOG_STRING(MSG, RESULT, ARG, INDENT_NUM, MSG_WIDTH) \
	do { \
		char	*trimmed; \
\
		trimmed = trimchr(ARG, '"'); \
		if (trimmed == NULL) \
			break ; \
		fprintf (stderr, "%*s%-*s: ", \
			INDENT_NUM, "", MSG_WIDTH, MSG); \
		fprintf(stderr, "\"%s\"", RESULT); \
		if (strcmp(RESULT, trimmed) != 0) \
			fprintf(stderr, " <- %s", ARG); \
		fprintf(stderr, "\n"); \
		free(trimmed); \
	} while (0)

/**
 * log string. not around `"`
 * @param MSG (char *) message
 * @param RESULT (char *) value
 * @param ARG (char *) argument
 * @param INDENT_NUM (number) indent space cnt.
 * @param MSG_WIDTH (number) output message width(left alignment)
 */
# define VALUE_LOG_STRING_RAW(MSG, RESULT, ARG, INDENT_NUM, MSG_WIDTH) \
	do { \
		char	*trimmed; \
\
		trimmed = trimchr(ARG, '"'); \
		if (trimmed == NULL) \
			break ; \
		fprintf (stderr, "%*s%-*s: ", \
			INDENT_NUM, "", MSG_WIDTH, MSG); \
		fprintf(stderr, "%s", RESULT); \
		if (strcmp(RESULT, trimmed) != 0) \
			fprintf(stderr, " <- %s", ARG); \
		fprintf(stderr, "\n"); \
		free(trimmed); \
	} while (0)

/**
 * Log string.
 * @param MSG (char *) message
 * @param VALUE (char *) value
 * @param INDENT_NUM (number) indent space cnt.
 * @param MSG_WIDTH (number) output message width(left alignment)
 */
# define STRING_LOG(MSG, VALUE, INDENT_NUM, MSG_WIDTH) \
		VALUE_LOG_STRING_RAW(MSG, VALUE, VALUE, INDENT_NUM, MSG_WIDTH)

/**
 * log value.
 * @param MSG (char *) message
 * @param RESULT (any number) RESULT of ARG
 * @param ARG (char *) ARG of string.
 * @param INDENT_NUM (number) indent space cnt.
 * @param MSG_WIDTH (number) output message width(left alignment)
*/
# define VALUE_LOG_NUM(MSG, RESULT, ARG, INDENT_NUM, MSG_WIDTH) \
	do { \
		fprintf (stderr, "%*s%-*s: ", \
			INDENT_NUM, "", MSG_WIDTH, MSG); \
		GENERIC_FPRINT(stderr, RESULT); \
		if (!is_raw_number(ARG)) \
			fprintf(stderr, " <- %s", ARG); \
		fprintf(stderr, "\n"); \
	} while (0)

/**
 * log value for boolean.
 * @param MSG (char *) message
 * @param RESULT (any nubmer) RESULT of ARG
 * @param ARG (char *) ARG of string.
 * @param INDENT_NUM (number) indent space cnt.
 * @param MSG_WIDTH (number) output message width(left alignment)
*/
# define VALUE_LOG_BOOL(MSG, RESULT, ARG, INDENT_NUM, MSG_WIDTH) \
	do { \
		fprintf (stderr, "%*s%-*s: ", \
			INDENT_NUM, "", MSG_WIDTH, MSG); \
		GENERIC_FPRINT_BOOL(stderr, RESULT); \
		fprintf(stderr, " <- %s\n", ARG); \
	} while (0)

#endif