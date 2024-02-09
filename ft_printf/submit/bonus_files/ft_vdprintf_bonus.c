/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdprintf_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:52:40 by tookuyam          #+#    #+#             */
/*   Updated: 2023/11/09 15:13:26 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stddef.h>
#include <limits.h>
#include "conversion_specification_bonus.h"
#include "printers_bonus.h"
#include "ft_printf_bonus.h"

static int	print_cs(int fd, const char **format, va_list arg_ptr);

int	ft_vdprintf(int fd, const char *format, va_list arg_ptr)
{
	size_t	len;
	int		tmp_len;

	len = 0;
	if (check_printf_format(format) == 0)
		return (-1);
	while (*format != '\0')
	{
		tmp_len = print_until_char_fd(fd, format, '%');
		if (tmp_len < 0)
			return (-1);
		len += tmp_len;
		format += tmp_len;
		if (len > INT_MAX)
			return (-1);
		else if (*format == '\0')
			return ((int)len);
		tmp_len = print_cs(fd, &format, arg_ptr);
		if (tmp_len < 0)
			return (-1);
		len += tmp_len;
		if (len > INT_MAX)
			return (-1);
	}
	return ((int)len);
}

static int	print_cs(int fd, const char **format, va_list arg_ptr)
{
	t_conv_specification	*cs;
	int						print_len;
	int						specification_len;

	cs = get_conv_specification(*format);
	if (cs == NULL)
		return (-1);
	print_len = ft_vdprint_cs(fd, cs, arg_ptr);
	free_t_conv_specification(cs);
	specification_len = get_conv_specification_len(*format);
	if (specification_len < 0)
		return (-1);
	*format += specification_len;
	return (print_len);
}
