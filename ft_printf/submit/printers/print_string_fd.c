/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 23:22:10 by tookuyam          #+#    #+#             */
/*   Updated: 2023/11/09 13:58:13 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>
#include "libft.h"
#include "conversion_specification.h"
#include "aligned_print.h"

static char	*replace_null(const char *str);
static char	*substr_with_cs(t_conv_specification *cs, const char *str);
int	print_string_fd_with_cs(int fd, t_conv_specification *cs, char *output_str);

int	print_string_fd(int fd, t_conv_specification *cs, va_list args) {
	char *output_str;

	output_str = va_arg(args, char *);
	return (print_string_fd_with_cs(fd, cs, output_str));
}

int	print_string_fd_with_cs(int fd, t_conv_specification *cs, char *output_str)
{
	int		print_len;
	char	*tmp;

	tmp = replace_null(output_str);
	if (tmp == NULL)
		return (-1);
	output_str = tmp;
	tmp = substr_with_cs(cs, output_str);
	free(output_str);
	if (tmp == NULL)
		return (-1);
	output_str = tmp;
	print_len = t_conv_aligned_print(fd, cs, (char *)output_str);
	free(output_str);
	return (print_len);
}

static char	*replace_null(const char *str)
{
	if (str == NULL)
		return (ft_strdup("(null)"));
	return (ft_strdup(str));
}

static char	*substr_with_cs(t_conv_specification *cs, const char *str)
{
	if (cs->is_specified_precision != 0)
		return (ft_substr(str, 0, cs->precision));
	return (ft_strdup(str));
}
