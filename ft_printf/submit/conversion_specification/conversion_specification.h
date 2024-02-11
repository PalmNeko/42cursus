/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_specification.h                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:49:40 by tookuyam          #+#    #+#             */
/*   Updated: 2024/02/11 15:03:53 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERSION_SPECIFICATION_H
# define CONVERSION_SPECIFICATION_H

# include <stdbool.h>

// conversion specifier
typedef enum e_conversion_specifier
{
	CS_NONE,
	CS_LOWER_S,
	CS_LOWER_P,
	CS_LOWER_C,
	CS_LOWER_D,
	CS_LOWER_U,
	CS_LOWER_I,
	CS_LOWER_X,
	CS_UPPER_X,
	CS_PERCENT
}	t_conversion_specifier;

/** conversion specifier
 * @param conversion_specifier conversion specifier
 * @param flag_shape # flag
 * @param flag_minus - flag
 * @param flag_plus + flag
 * @param flag_zero 0 flag
 * @param flag_space ` ` flag
 * @param is_specified_min_field_width is set specified minimum field width
 * @param minimum_field_width specified minimum field width value.
 * @param is_specified_precision is set precision
 * @param precision precision
 */
typedef struct s_conv_specification
{
	t_conversion_specifier	conversion_specifier;
	bool					flag_sharp;
	bool					flag_minus;
	bool					flag_plus;
	bool					flag_zero;
	bool					flag_space;
	bool					is_specified_min_field_width;
	int						minimum_field_width;
	bool					is_specified_precision;
	int						precision;
}	t_cs;

t_cs	*new_t_cs(void);
t_cs	*generate_cs(const char *format);
int		get_cs_len(const char *format);
void	free_t_cs(t_cs *ptr);
int		check_conv_specification_format(const char *cs_format);

#endif
