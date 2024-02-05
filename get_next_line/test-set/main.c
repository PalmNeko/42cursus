/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 14:42:55 by tookuyam          #+#    #+#             */
/*   Updated: 2024/02/05 17:56:37 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <assert.h>
#include <time.h>
#include "get_next_line.h"

char empty_file[] = "./files/empty.txt";
char fazzing_file[] = "./files/fazzing.txt";
char multiline_file[] = "./files/multiline.txt";
char multiline_endline_file[] = "./files/multiline_endline.txt";
char one_file[] = "./files/one.txt";
char only_line_file[] = "./files/only_line.txt";
char only_multiline_file[] = "./files/only_multiline.txt";
char singleline_file[] = "./files/singleline.txt";
char singleline_endline_file[] = "./files/singleline_endline.txt";

int multi_fd_random_reading();
int test_with_pc(int fd, const char *expects[], int size, int *pc);
int test_all_expects(int fd, const char *expects[], int size, int *pc);
int test_all_with_pc(int fd, int *pc, int (*f)(int fd, int *pc));
int test_all_and_more_one(int fd, int (*f)(int fd, int *pc));
int test_empty_with_pc(int fd, int *pc);
int test_empty(int fd);
int test_fazzing_with_pc(int fd, int *pc);
int test_fazzing(int fd);
int test_multiline_with_pc(int fd, int *pc);
int test_multiline(int fd);
int test_multiline_endline_with_pc(int fd, int *pc);
int test_multiline_endline(int fd);
int test_one_with_pc(int fd, int *pc);
int test_one(int fd);
int test_only_line_with_pc(int fd, int *pc);
int test_only_line(int fd);
int test_only_multiline_with_pc(int fd, int *pc);
int test_only_multiline(int fd);
int test_singleline_with_pc(int fd, int *pc);
int test_singleline(int fd);
int test_singleline_endline_with_pc(int fd, int *pc);
int test_singleline_endline(int fd);
int gnl_assert(int fd, const char *tobe);
int single_fd_test_template(const char *filename, int (*f)(int fd));
void test_print_and_free(const char *file_name, char *input_data);
void print_file_header(const char *file_name, int fd);
void print_footer(int fd);

int main() {
    single_fd_test_template(empty_file, test_empty);
    single_fd_test_template(fazzing_file, test_fazzing);
    single_fd_test_template(multiline_file, test_multiline);
    single_fd_test_template(multiline_endline_file, test_multiline_endline);
    single_fd_test_template(one_file, test_one);
    single_fd_test_template(only_line_file, test_only_line);
    single_fd_test_template(only_multiline_file, test_only_multiline);
    single_fd_test_template(singleline_file, test_singleline);
    single_fd_test_template(singleline_endline_file, test_singleline_endline);
    multi_fd_random_reading();
    return (0);
}

int multi_fd_random_reading() {
    int target_cnt;
    int fd[1000];
    int pc[1000];
    char *template_files[] = {
        empty_file,
        fazzing_file,
        multiline_file,
        multiline_endline_file,
        one_file,
        only_line_file,
        only_multiline_file,
        singleline_file,
        singleline_endline_file,
    };
    int (*template_test_functions[])(int fd, int *pc) = {
        test_empty_with_pc,
        test_fazzing_with_pc,
        test_multiline_with_pc,
        test_multiline_endline_with_pc,
        test_one_with_pc,
        test_only_line_with_pc,
        test_only_multiline_with_pc,
        test_singleline_with_pc,
        test_singleline_endline_with_pc,
    };
    int target_numbers[] = {
        0,
        1,
        2,
    };
    srand(time(NULL));
    target_cnt = sizeof(target_numbers) / sizeof(target_numbers[0]);
    for (int i = 0; i < target_cnt; i++)
        pc[i] = 0;
    // ファイルのオープン
    for (int i = 0; i < target_cnt; i++) {
        int no = target_numbers[i];
        fd[i] = open(template_files[no], O_RDONLY);
        print_file_header(template_files[no], fd[i]);
    }
    // ランダム処理
    for (int i = 0; i < 20; i++) {
        int target_index = arc4random() % target_cnt;
        int no = target_numbers[target_index];
        template_test_functions[no](fd[target_index], &pc[target_index]);
    }
    // クローズ
    for (int i = 0; i < target_cnt; i++) {
        close(fd[i]);
        print_footer(fd[i]);
    }
    return (0);
}

int test_with_pc(int fd, const char *expects[], int size, int *pc) {
    int simple_pos; // -1 : infile, 0 : final, 1 : over

    assert(*pc >= 0);
    simple_pos = 0;
    if (*pc > size - 1) {
        gnl_assert(fd, NULL);
        simple_pos = 1;
    }
    else if (*pc == size - 1) {
        gnl_assert(fd, expects[size - 1]);
        simple_pos = 0;
    }
    else {
        gnl_assert(fd, expects[*pc]);
        simple_pos = -1;
    }
    *pc += 1;
    return (simple_pos);
}

int test_all_expects(int fd, const char *expects[], int size, int *pc) {
    for (int i = 0; i < size; i++)
        test_with_pc(fd, expects, size, pc);
    return (0);
}

int test_all_with_pc(int fd, int *pc, int (*f)(int fd, int *pc)) {
    while (f(fd, pc) <= 0)
        ;
    return (0);
}

int test_all_and_more_one(int fd, int (*f)(int fd, int *pc)) {
    int pc;

    pc = 0;
    test_all_with_pc(fd, &pc, f);
    f(fd, &pc);
    return (0);
}

int test_empty_with_pc(int fd, int *pc) {
    const char *expects[] = {
        NULL,
        NULL,
        NULL,
    };
    const int size = sizeof(expects) / sizeof(expects[0]);
    return test_with_pc(fd, expects, size, pc);
}

int test_empty(int fd) {
    test_all_and_more_one(fd, test_empty_with_pc);
    return (0);
}

int test_fazzing_with_pc(int fd, int *pc) {
    const char *expects[] = {
        "\n",
        "0\n",
        "3210\n",
        "\n",
        "0\n",
        "0123\n",
        "\n",
        "\n",
    };
    const int size = sizeof(expects) / sizeof(expects[0]);
    return test_with_pc(fd, expects, size, pc);
}

int test_fazzing(int fd) {
    test_all_and_more_one(fd, test_fazzing_with_pc);
    return (0);
}

int test_multiline_with_pc(int fd, int *pc) {
    const char *expects[] = {
        "0123456789\n",
        "0123456789\n",
        "0123456789\n",
        "0123456789\n",
        "0123456789\n",
        "0123456789\n",
        "0123456789\n",
        "0123456789\n",
        "0123456789\n",
        "0123456789",
    };
    const int size = sizeof(expects) / sizeof(expects[0]);
    return test_with_pc(fd, expects, size, pc);
}

int test_multiline(int fd) {
    test_all_and_more_one(fd, test_multiline_with_pc);
    return (0);
}

int test_multiline_endline_with_pc(int fd, int *pc) {
    const char *expects[] = {
        "0123456789\n",
        "0123456789\n",
        "0123456789\n",
        "0123456789\n",
        "0123456789\n",
        "0123456789\n",
        "0123456789\n",
        "0123456789\n",
        "0123456789\n",
        "0123456789\n",
    };
    const int size = sizeof(expects) / sizeof(expects[0]);
    return test_with_pc(fd, expects, size, pc);
}

int test_multiline_endline(int fd) {
    test_all_and_more_one(fd, test_multiline_endline_with_pc);
    return (0);
}

int test_one_with_pc(int fd, int *pc) {
    const char *expects[] = {
        "a",
    };
    const int size = sizeof(expects) / sizeof(expects[0]);
    return test_with_pc(fd, expects, size, pc);
}

int test_one(int fd) {
    test_all_and_more_one(fd, test_one_with_pc);
    return (0);
}

int test_only_line_with_pc(int fd, int *pc) {
    const char *expects[] = {
        "\n",
    };
    const int size = sizeof(expects) / sizeof(expects[0]);
    return test_with_pc(fd, expects, size, pc);
}

int test_only_line(int fd) {
    test_all_and_more_one(fd, test_only_line_with_pc);
    return (0);
}

int test_only_multiline_with_pc(int fd, int *pc) {
    const char *expects[] = {
        "\n",
        "\n",
        "\n",
        "\n",
        "\n",
    };
    const int size = sizeof(expects) / sizeof(expects[0]);
    return test_with_pc(fd, expects, size, pc);
}

int test_only_multiline(int fd) {
    test_all_and_more_one(fd, test_only_multiline_with_pc);
    return (0);
}

int test_singleline_with_pc(int fd, int *pc) {
    const char *expects[] = {
        "123403923"
    };
    const int size = sizeof(expects) / sizeof(expects[0]);
    return test_with_pc(fd, expects, size, pc);
}

int test_singleline(int fd) {
    test_all_and_more_one(fd, test_singleline_with_pc);
    return (0);
}

int test_singleline_endline_with_pc(int fd, int *pc) {
    const char *expects[] = {
        "123403923\n"
    };
    const int size = sizeof(expects) / sizeof(expects[0]);
    return test_with_pc(fd, expects, size, pc);
}

int test_singleline_endline(int fd) {
    test_all_and_more_one(fd, test_singleline_endline_with_pc);
    return (0);
}

void test_print_and_free(const char *file_name, char *input_data) {
    printf("%s :\'%s\'\n", file_name, input_data);
    free(input_data);
}

void print_file_header(const char *file_name, int fd) {
    printf("\n");
    printf("fd: %d ---- %s ----\n", fd, file_name);
}

void print_footer(int fd) {
    printf("close: -------- %d\n", fd);
}

void print_escape_line(const char *str) {
    if (str == NULL) {
        printf("%s", NULL);
        return ;
    }
    while (*str != '\0')
    {
        if (*str == '\n')
            printf("\\n");
        else
            printf("%c", *str);
        str++;
    }
    return ;
}

int gnl_assert(int fd, const char *tobe) {
    char *result;

    result = get_next_line(fd);
    printf("%d expect: ", fd);
    print_escape_line(tobe);
    printf(" , return ");
    print_escape_line(result);
    printf(" - ");
    if (result == tobe || (result != NULL && tobe != NULL && strcmp(result, tobe) == 0))
        printf("\033[32m" "equal\n" "\033[m");
    else
        printf("\033[31m" "not equal\n" "\033[m");
    free(result);
    return 0;
}

int single_fd_test_template(const char *filename, int (*f)(int fd)) {
    int fd;

    fd = open(filename, O_RDONLY);
    print_file_header(filename, fd);
    f(fd);
    close(fd);
    print_footer(fd);
    return (0);
}
