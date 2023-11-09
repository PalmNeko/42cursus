/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generic_print.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 17:42:44 by tookuyam          #+#    #+#             */
/*   Updated: 2023/11/01 11:59:28 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GENERIC_PRINT_H
# define GENERIC_PRINT_H

#include <stdio.h>

/**
 * get format for formatters. (ex. printf, fprintf, sprintf...)
 * @param X value of format target.
 */
#define FORMAT(X) _Generic((X), \
    short: "%d", \
    int: "%d", \
    long: "%ld", \
    long long: "%lld", \
    unsigned int: "%u", \
    unsigned long: "%lu", \
    unsigned long long: "%llu", \
    float: "%.5e", \
    double: "%.5le", \
    char: "%c", \
    char *: "%s", \
    const char *: "%s" \
    )

/**
 * generic fprintf. output `X` to `stream`
 * @param stream stream of target (ex. stderr, stdout...)
 * @param X value for output
 */
#define GENERIC_FPRINT(stream, X) \
	do { \
		char    format[30]; \
		\
		sprintf(format, "%s", FORMAT(X)); \
		fprintf(stream, format, X ); \
	} while(0)

/**
 * generic print. output `BOOL` as boolean string.
 * @param stream stream of target (ex. stderr, stdout...)
 * @param BOOL value for output with boolean.
 */
# define GENERIC_FPRINT_BOOL(stream, BOOL) \
    do { \
        fprintf(stream, "%s", BOOL ? "true" : "false"); \
    } while(0) \

#endif
