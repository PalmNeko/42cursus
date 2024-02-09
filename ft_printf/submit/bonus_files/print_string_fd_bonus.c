/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string_fd_bonus.c                            :+:      :+:    :+:   */
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
#include "conversion_specification_bonus.h"
#include "aligned_print_bonus.h"

static char	*replace_null(const char *str);
static char	*substr_with_cs(t_conv_specification *cs, const char *str);

int	ft_vdprint_string_cs(int fd, t_conv_specification *cs, va_list args)
{
	int		print_len;
	char	*output_str;
	char	*tmp;

	output_str = va_arg(args, char *);
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
