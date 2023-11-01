# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/17 15:45:27 by tookuyam          #+#    #+#              #
#    Updated: 2023/10/27 17:13:29 by tookuyam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = test
CC = cc
REQUIRED_FLAGS = -Wall -Wextra -Werror $(addprefix -I,$(INCS))
CFLAGS = $(REQUIRED_FLAGS) $(DEBUG_CFLAGS)
ifeq ($(MAKECMDGOALS), debug)
	CFLAGS += -g -fsanitize=address
endif
SUBMIT_SRCS = \
	$(addprefix ../submit/,\
		get_next_line.c \
		get_next_line_utils.c \
	)

BONUS_SRCS = \
	$(addprefix ../submit/,\
		get_next_line_bonus.c \
		get_next_line_utils_bonus.c \
	)

TEST_SRCS = $(shell find . -name "*.c")

SRCS = \
	$(SUBMIT_SRCS) \
	$(TEST_SRCS)

HEADERS = \
	$(addprefix ../submit/,\
		get_next_line.h \
	)

INCS = ../submit
OBJS = $(SRCS:.c=.o)
RELINK_GURAD_FLIES = $(BONUS_RULE)
CLEAN_FILES = $(OBJS) $(BONUS:.c=.o) $(RELINK_GURAD_FLIES)

all: $(NAME) $(BONUS_RULE)

$(NAME): $(OBJS) $(HEADERS)
	$(CC) $(CFLAGS) -o $(NAME) $(filter %.o,$^)

bonus: $(BONUS_SRCS:.c=.o) $(TEST_SRCS:.c=.o) $(HEADERS)
	$(CC) $(CFLAGS) -o $(NAME) $(filter %.o,$^)

debug: fclean bonus

%.o: %.c
	echo $^
	$(CC) $(CFLAGS) -o $@ -c $^

clean:
	$(RM) $(CLEAN_FILES)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
