/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_conv_specification.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:39:22 by tookuyam          #+#    #+#             */
/*   Updated: 2023/11/06 14:13:00 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversion_specification.h"
#include "conversion_specification_utils.h"
#include "libft.h"
#include <stdlib.h>
#include <errno.h>

static void	read_flag(t_conv_specification *cs, const char **format);
static void	read_min_field_width(t_conv_specification *cs, const char **format);
static void	read_precision(t_conv_specification *cs, const char **format);
static void	read_cs(t_conv_specification *cs, const char **fmt);

/**
 * get conversion specification.
 * @param format conversion format
 * @return
 */
t_conv_specification	*get_conv_specification(const char *format)
{
	t_conv_specification	*cs;

	if (*format++ != '%')
		return (NULL);
	cs = new_t_conv_specification();
	if (cs == NULL)
		return (NULL);
	read_flag (cs, &format);
	read_min_field_width(cs, &format);
	read_precision(cs, &format);
	read_cs(cs, &format);
	if (cs->conversion_specifier == CS_NONE || errno == ERANGE)
	{
		free_t_conv_specification(cs);
		return (NULL);
	}
	return (cs);
}

static void	read_flag(t_conv_specification *cs, const char **format)
{
	char	flag;

	while (is_flags(**format))
	{
		flag = **format;
		if (flag == '#')
			cs->flag_sharp = !0;
		else if (flag == '0')
			cs->flag_zero = !0;
		else if (flag == '-')
			cs->flag_minus = !0;
		else if (flag == ' ')
			cs->flag_space = !0;
		else if (flag == '+')
			cs->flag_plus = !0;
		*format += 1;
	}
	return ;
}

static void	read_min_field_width(t_conv_specification *cs, const char **format)
{
	if (! ft_isdigit(**format))
		return ;
	cs->is_specified_min_field_width = !0;
	cs->minimum_field_width = ft_atoi(*format);
	while (ft_isdigit(**format))
		*format += 1;
	return ;
}

static void	read_precision(t_conv_specification *cs, const char **format)
{
	if (**format != '.')
		return ;
	*format += 1;
	cs->is_specified_precision = !0;
	cs->precision = ft_atoi(*format);
	while (ft_isdigit(**format))
		*format += 1;
	return ;
}

static void	read_cs(t_conv_specification *cs, const char **fmt)
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
