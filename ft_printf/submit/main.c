
#include <stdio.h>

int	ft_printf(const char *format, ...);

int main(void)
{
	const char *format = " %02.0x \n";

	ft_printf(format, 0);
	printf(format, 0);
	return (0);
}
