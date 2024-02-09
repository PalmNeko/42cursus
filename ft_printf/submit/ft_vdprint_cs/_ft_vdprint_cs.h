
#ifndef _FT_VDPRINT_CS_H
# define _FT_VDPRINT_CS_H

# include <stdarg.h>
# include "conversion_specification.h"

typedef int	(*t_print_function)(int, t_conv_specification *, va_list);
typedef struct s_relational_conversion_specifier_and_print_function {
	t_conversion_specifier		specifier;
	t_print_function			p_function;
}	t_relational_conversion_specifier_and_print_function;

int	ft_vdprint_char_cs(int fd, t_conv_specification *cs, va_list args);
int	ft_vdprint_decimal_cs(int fd, t_conv_specification *cs, va_list args);
int	ft_vdprint_hex_cs(int fd, t_conv_specification *cs, va_list args);
int	ft_vdprint_hex_upper_cs(int fd, t_conv_specification *cs, va_list args);
int	ft_vdprint_int_cs(int fd, t_conv_specification *cs, va_list args);
int	ft_vdprint_percent_cs(int fd, t_conv_specification *cs, va_list args);
int	ft_vdprint_pointer_cs(int fd, t_conv_specification *cs, va_list args);
int	ft_vdprint_string_cs(int fd, t_conv_specification *cs, va_list args);
int	ft_vdprint_uint_cs(int fd, t_conv_specification *cs, va_list args);

#endif
