/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdprintf.c                                    :+:      :+:    :+:   */
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
#include <unistd.h>
#include "conversion_specification.h"
#include "ft_vdprint_cs.h"
#include "libft.h"

static int	print_cs(int fd, const char **format, va_list arg_ptr);
static int	print_until_char_fd(int fd, const char *str, char c);
static int	check_printf_format(const char *format);

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
	t_cs	*cs;
	int		print_len;
	int		specification_len;

	cs = generate_cs(*format);
	if (cs == NULL)
		return (-1);
	print_len = ft_vdprint_cs(fd, cs, arg_ptr);
	free_t_cs(cs);
	specification_len = get_cs_len(*format);
	if (specification_len < 0)
		return (-1);
	*format += specification_len;
	return (print_len);
}

static int	print_until_char_fd(int fd, const char *str, char c)
{
	size_t	len;

	len = 0;
	while (str[len] != c && str[len] != '\0' && len <= INT_MAX)
		len++;
	if (len > INT_MAX && str[len] != c && str[len] != '\0')
		return (-1);
	if (write(fd, str, len) < 0)
		return (-1);
	return ((int)len);
}

static int	check_printf_format(const char *format)
{
	char	*conv_specification;
	int		tmp_len;

	conv_specification = ft_strchr(format, '%');
	while (conv_specification != NULL)
	{
		if (check_conv_specification_format(conv_specification) == 0)
			return (0);
		tmp_len = get_cs_len(conv_specification);
		if (tmp_len < 0)
			return (-1);
		conv_specification += tmp_len;
		conv_specification = ft_strchr(conv_specification, '%');
	}
	return (true);
}
