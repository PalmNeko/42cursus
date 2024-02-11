/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdprint_decimal_cs.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:17:14 by tookuyam          #+#    #+#             */
/*   Updated: 2024/02/11 15:15:10 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include "conversion_specification.h"
#include "libft.h"
#include "string_util.h"
#include "aligned_print.h"
#include "conversion_specification_utils.h"

int			print_decimal_fd_with_cs(int fd, t_cs *cs, int value);
static char	*add_sign_with_cs(t_cs *cs, char *num_str);

int	ft_vdprint_decimal_cs(int fd, t_cs *cs, va_list args)
{
	int		print_value;

	print_value = va_arg(args, int);
	return (print_decimal_fd_with_cs(fd, cs, print_value));
}

int	print_decimal_fd_with_cs(int fd, t_cs *cs, int value)
{
	char	*num_str;
	char	*pad_zero_str;
	char	*joined_sign_str;
	int		print_len;

	if (is_set_zero_precision(cs) && value == 0)
		return (0);
	num_str = ft_itoa(value);
	if (num_str == NULL)
		return (-1);
	pad_zero_str = zero_pad_with_cs(cs, num_str);
	free(num_str);
	if (pad_zero_str == NULL)
		return (-1);
	joined_sign_str = add_sign_with_cs(cs, pad_zero_str);
	free(pad_zero_str);
	if (joined_sign_str == NULL)
		return (-1);
	cs->flag_zero = false;
	print_len = t_conv_aligned_print(fd, cs, joined_sign_str);
	free(joined_sign_str);
	return (print_len);
}

static char	*add_sign_with_cs(t_cs *cs, char *num_str)
{
	char	*joined_str;

	joined_str = NULL;
	if (num_str[0] == '-')
		return (ft_strdup(num_str));
	else if (cs->flag_plus != false)
		return (ft_strjoin("+", num_str));
	else if (cs->flag_space != false)
		return (ft_strjoin(" ", num_str));
	else
		return (ft_strdup(num_str));
	return (NULL);
}
