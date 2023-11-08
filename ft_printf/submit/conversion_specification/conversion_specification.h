/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_specification.h                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:49:40 by tookuyam          #+#    #+#             */
/*   Updated: 2023/11/08 13:40:35 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERSION_SPECIFICATION_H
# define CONVERSION_SPECIFICATION_H

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
} t_conversion_specifier;

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
	t_conversion_specifier conversion_specifier;
	int flag_sharp;
	int	flag_minus;
	int	flag_plus;
	int	flag_zero;
	int	flag_space;
	int is_specified_min_field_width;
	int minimum_field_width;
	int is_specified_precision;
	int precision;
} t_conv_specification;

t_conv_specification	*new_t_conv_specification(void);
t_conv_specification	*get_conv_specification(const char *format);
int						get_conv_specification_len(const char *format);
void					free_t_conv_specification(t_conv_specification *ptr);
int						check_conv_specification_format(const char *cs_format);

#endif
