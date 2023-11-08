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

static void	set_flag(t_conv_specification *cs, const char *format);
static void	set_min_field_width(t_conv_specification *cs, const char *format);
static void	set_precision(t_conv_specification *cs, const char *format);
static void	set_conversion_specifier(t_conv_specification *cs, const char *format);

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
	set_flag (cs, format);
	while (is_flags(*format))
		format++;
	set_min_field_width(cs, format);
	while (ft_isdigit(*format))
		format++;
	set_precision(cs, format);
	if (*format == '.')
		format++;
	while (ft_isdigit(*format))
		format++;
	set_conversion_specifier(cs, format);
	if (! is_conversion_specifier(*format) || errno == ERANGE)
	{
		free_t_conv_specification(cs);
		return (NULL);
	}
	return (cs);
}

static void	set_flag(t_conv_specification *cs, const char *format)
{
	size_t	index;
	char	flag;

	index = 0;
	while (is_flags(format[index]))
	{
		flag = format[index];
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
		index++;
	}
	return ;
}

static void	set_min_field_width(t_conv_specification *cs, const char *format)
{
	if (! ft_isdigit(*format))
		return ;
	cs->is_specified_min_field_width = !0;
	cs->minimum_field_width = ft_atoi(format);
	return ;
}

static void	set_precision(t_conv_specification *cs, const char *format)
{
	if (format[0] != '.')
		return ;
	cs->is_specified_precision = !0;
	cs->precision = ft_atoi(format + 1);
	return ;
}

static void	set_conversion_specifier(t_conv_specification *cs, const char *format)
{
	if (*format == 'c')
		cs->conversion_specifier = CS_LOWER_C;
	else if (*format == 'd')
		cs->conversion_specifier = CS_LOWER_D;
	else if (*format == 'i')
		cs->conversion_specifier = CS_LOWER_I;
	else if (*format == 'p')
		cs->conversion_specifier = CS_LOWER_P;
	else if (*format == 's')
		cs->conversion_specifier = CS_LOWER_S;
	else if (*format == 'u')
		cs->conversion_specifier = CS_LOWER_U;
	else if (*format == 'x')
		cs->conversion_specifier = CS_LOWER_X;
	else if (*format == 'X')
		cs->conversion_specifier = CS_UPPER_X;
	else if (*format == '%')
		cs->conversion_specifier = CS_PERCENT;
	return ;
}
