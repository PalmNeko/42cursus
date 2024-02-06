
#ifndef FT_PRINTF_TEST_TOOL_H
# define FT_PRINTF_TEST_TOOL_H

# include <stdbool.h>
# include <stdarg.h>

// main
bool check_ft_printf(const char *format, ...);
bool vcheck_ft_printf(const char *format, va_list ap);

// sub
bool is_equal_file_fd(int fd1, int fd2);
int copy_file(const char* src_path, const char* dest_path);

#endif
