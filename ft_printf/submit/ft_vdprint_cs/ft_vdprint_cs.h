
#ifndef FT_VDPRINT_CS
# define FT_VDPRINT_CS

# include <stdarg.h>
# include "conversion_specification.h"

int	ft_vdprint_cs(int fd, t_conv_specification *cs, va_list args);

#endif
