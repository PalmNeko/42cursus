
#include <unistd.h>
#include <fcntl.h>
#include <stdbool.h>
#include <string.h>

static int file_compare_fd(int fd1, int fd2, ssize_t *read_result);

bool is_equal_file_fd(int fd1, int fd2) {
	ssize_t read_result;
	int cmp_result;

	do {
		cmp_result = file_compare_fd(fd1, fd2, &read_result);
		if (cmp_result != 0)
			return (false);
	} while (read_result > 0);
	return (true);
}

static int file_compare_fd(int fd1, int fd2, ssize_t *read_result) {
	char buf[2][1024];
	ssize_t readed_len[2];
	const int fds[2] = {fd1, fd2};

	for (int i = 0; i < 2; i++) {
		readed_len[i] = read(fds[i], buf[i], sizeof(buf[i]) - 1);
		if (readed_len[i] == -1)
			return (-1);
		buf[i][readed_len[i]] = '\0';
	}
	if (readed_len[0] > readed_len[1])
		*read_result = readed_len[0];
	else
		*read_result = readed_len[0];
	return (strcmp(buf[0], buf[1]));
}
