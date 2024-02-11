
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdarg.h>
#include <sys/stat.h>
#include "ft_printf_test_tool.h"
#include "ft_printf.h"
#include "ft_vdprintf.h"

# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define CL "\033[m"

bool check_ft_printf(const char *format, ...) {
	va_list ap;
	bool result;

	va_start(ap, format);
	result = vcheck_ft_printf(format, ap);
	va_end(ap);
	return (result);
}

bool vcheck_ft_printf(const char *format, va_list ap) {
	va_list ft_ap;
	int ft_printf_fd;
	int printf_fd;
	int ft_print_len;
	int print_len;
	char ft_printf_log_filename[] = "logs/ft_printf_output_tmp.txt";
	char printf_log_filename[] = "logs/printf_output_tmp.txt";

	va_copy(ft_ap, ap);
	struct stat st;

    if (stat("logs", &st) != 0)
		if (mkdir("logs", 0777) == -1)
			return perror(NULL), false;
	ft_printf_fd = open(ft_printf_log_filename, O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	if (ft_printf_fd == -1)
		return perror(NULL), false;
	printf_fd = open(printf_log_filename, O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	if (printf_fd == -1)
		return perror(NULL), false;
	ft_print_len = ft_vdprintf(ft_printf_fd, format, ft_ap);
	print_len = vdprintf(printf_fd, format, ap);
	if (ft_print_len != print_len) {
		fprintf(stdout, YELLOW "error" CL ": return value isn't equal - original : %d ft: %d\n", print_len, ft_print_len);
	}
	lseek(ft_printf_fd, SEEK_SET, 0);
	lseek(printf_fd, SEEK_SET, 0);
	bool cmp_result;
	cmp_result = is_equal_file_fd(ft_printf_fd, printf_fd);
	close(ft_printf_fd);
	close(printf_fd);
	if (cmp_result == false) {
		char ft_printf_filename[] = "logs/ft_printf.log.temp.XXXXXX";
		char printf_filename[] = "logs/printf.log.temp.XXXXXX";
		char *error_check[2];

		error_check[0] = mktemp(ft_printf_filename);
		error_check[1] = mktemp(printf_filename);
		fprintf(stdout, YELLOW "error" CL ": isn't equal output log: %s , %s\n", printf_filename, ft_printf_filename);
		if (error_check[0] == NULL || error_check[1] == NULL)
			printf(RED "fail" CL ": couldn't create template file\n");
		else {
			copy_file(ft_printf_log_filename, ft_printf_filename);
			copy_file(printf_log_filename, printf_filename);
		}
		return false;
	}
	return true;
}
