/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 18:55:51 by tookuyam          #+#    #+#             */
/*   Updated: 2023/10/20 15:23:32 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

static int	ft_isspace(char c);
static long	mul_l(long value, long mul_value);
static long	add_l(long value, long add_value);

int	ft_atoi(const char *str)
{
	int		sign_direction;
	int		add_value;
	long	ret;

	sign_direction = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
		sign_direction *= -1;
	if (*str == '+' || *str == '-')
		str++;
	ret = 0;
	while ('0' <= *str && *str <= '9')
	{
		add_value = sign_direction * (*str - '0');
		ret = mul_l(ret, 10);
		ret = add_l(ret, add_value);
		if (ret == LONG_MAX || ret == LONG_MIN)
			return (ret);
		str++;
	}
	return (ret);
}

static long	mul_l(long value, long mul_value)
{
	if (mul_value != 0 && value > LONG_MAX / mul_value)
		return (LONG_MAX);
	else if (mul_value != 0 && value < LONG_MIN / mul_value)
		return (LONG_MIN);
	return (value * mul_value);
}

static long	add_l(long value, long add_value)
{
	if (add_value > 0 && value > LONG_MAX - add_value)
		return (LONG_MAX);
	else if (add_value < 0 && value < LONG_MIN - add_value)
		return (LONG_MIN);
	return (value + add_value);
}

/**
 * If c is '\t', '\n', '\v', '\f', '\r' or ' ', return non-zero.
 * else, return zero.
 */
static int	ft_isspace(char c)
{
	if (('\t' <= c && c <= '\r') || c == ' ')
		return (1);
	else
		return (0);
}
