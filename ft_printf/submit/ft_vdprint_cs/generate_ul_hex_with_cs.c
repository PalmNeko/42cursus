
#include <stdlib.h>
#include "libft.h"
#include "conversion_specification.h"
#include "string_util.h"

static char	*set_prefix_with_cs(t_conv_specification *cs, const char *str);

char *generate_ul_hex_with_cs(t_conv_specification *cs, unsigned long value) {
    char	*num_str;
	char	*tmp;

    num_str = ft_ultoa_base_str(value, "0123456789abcdef");
	if (num_str == NULL)
		return (NULL);
	tmp = set_prefix_with_cs(cs, num_str);
	free(num_str);
	if (tmp == NULL)
		return (NULL);
    num_str = tmp;
	tmp = zero_pad_with_cs(cs, num_str);
	free(num_str);
	if (tmp == NULL)
		return (NULL);
    num_str = tmp;
	return (num_str);
}

static char	*set_prefix_with_cs(t_conv_specification *cs, const char *str)
{
	if (cs->flag_sharp != 0)
		return (ft_strjoin("0x", str));
	return (ft_strdup(str));
}
