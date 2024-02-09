
#include "conversion_specification_bonus.h"
#include <stdbool.h>

bool is_set_zero_precision(t_conv_specification *cs) {
    if (cs->is_specified_precision && cs->precision == 0)
        return (true);
    else
        return (false);
}
