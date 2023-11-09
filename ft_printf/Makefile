# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/08 16:07:08 by tookuyam          #+#    #+#              #
#    Updated: 2023/11/09 13:20:26 by tookuyam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = test
CC = cc
CFLAGS = -Wall -Werror -Wextra -MMD -MP
SRC_PATH = "./docs/*" "./sample_printf/*"
SRCS += $(shell find . -name "*.c" $(addprefix -not -path , $(SRC_PATH)))
OBJS = $(SRCS:.c=.o)
DEPENDS = $(SRCS:.c=.d)
EXCLUDE_INC_DIRS = "./sample_printf" "./docs" "./submit/.git" "./submit/.git/*"
INC_DIRS = $(shell find . -type d $(addprefix -not -path , $(EXCLUDE_INC_DIRS)))
CFLAGS += $(addprefix -I, $(INC_DIRS))
LIBS_TYCTEST = ./libs/libtyctest_main.a ./libs/libtyctest.a

all: $(NAME)

-include $(DEPENDS)

$(NAME): $(OBJS) $(LIBS_TYCTEST)
	$(CC) $(CFLAGS) -o $(NAME) $^

check: $(NAME)
	./$(NAME)

clean:
	$(RM) $(OBJS) $(DEPENDS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
