/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cs.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:39:22 by tookuyam          #+#    #+#             */
/*   Updated: 2023/11/06 14:13:00 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversion_specification_bonus.h"
#include "conversion_specification_utils_bonus.h"
#include "libft.h"
#include <stdlib.h>
#include <errno.h>

static void	read_flag(t_cs *cs, const char **format);
static void	read_min_field_width(t_cs *cs, const char **format);
static void	read_precision(t_cs *cs, const char **format);
static void	read_cs(t_cs *cs, const char **fmt);

/**
 * get conversion specification.
 * @param format conversion format
 * @return
 */
t_cs	*generate_cs(const char *format)
{
	t_cs	*cs;

	if (*format++ != '%')
		return (NULL);
	cs = new_t_cs();
	if (cs == NULL)
		return (NULL);
	read_flag (cs, &format);
	read_min_field_width(cs, &format);
	read_precision(cs, &format);
	read_cs(cs, &format);
	if (cs->conversion_specifier == CS_NONE || errno == ERANGE)
	{
		free_t_cs(cs);
		return (NULL);
	}
	return (cs);
}

static void	read_flag(t_cs *cs, const char **format)
{
	char	flag;

	while (is_flags(**format))
	{
		flag = **format;
		if (flag == '#')
			cs->flag_sharp = true;
		else if (flag == '0')
			cs->flag_zero = true;
		else if (flag == '-')
			cs->flag_minus = true;
		else if (flag == ' ')
			cs->flag_space = true;
		else if (flag == '+')
			cs->flag_plus = true;
		*format += 1;
	}
	return ;
}

static void	read_min_field_width(t_cs *cs, const char **format)
{
	if (! ft_isdigit(**format))
		return ;
	cs->is_specified_min_field_width = true;
	cs->minimum_field_width = ft_atoi(*format);
	while (ft_isdigit(**format))
		*format += 1;
	return ;
}

static void	read_precision(t_cs *cs, const char **format)
{
	if (**format != '.')
		return ;
	*format += 1;
	cs->is_specified_precision = true;
	cs->precision = ft_atoi(*format);
	while (ft_isdigit(**format))
		*format += 1;
	return ;
}

static void	read_cs(t_cs *cs, const char **fmt)
{
	if (**fmt == 'c')
		cs->conversion_specifier = CS_LOWER_C;
	else if (**fmt == 'd')
		cs->conversion_specifier = CS_LOWER_D;
	else if (**fmt == 'i')
		cs->conversion_specifier = CS_LOWER_I;
	else if (**fmt == 'p')
		cs->conversion_specifier = CS_LOWER_P;
	else if (**fmt == 's')
		cs->conversion_specifier = CS_LOWER_S;
	else if (**fmt == 'u')
		cs->conversion_specifier = CS_LOWER_U;
	else if (**fmt == 'x')
		cs->conversion_specifier = CS_LOWER_X;
	else if (**fmt == 'X')
		cs->conversion_specifier = CS_UPPER_X;
	else if (**fmt == '%')
		cs->conversion_specifier = CS_PERCENT;
	else
		cs->conversion_specifier = CS_NONE;
	return ;
}
