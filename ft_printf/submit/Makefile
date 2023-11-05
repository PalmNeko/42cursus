# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/05 16:10:34 by tookuyam          #+#    #+#              #
#    Updated: 2023/11/05 19:31:57 by tookuyam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# overview
NAME = libftprintf.a

# libraries
LIBS = libft.a

# compile settings
CC = cc
CFLAGS += -Wall -Werror -Wextra
SRCS += $(shell find . -name "*.c")
OBJS = $(SRCS:.c=.o)
DEPENDS = $(SRCS:.c=.d)
CFLAGS += -MMD -MP
EXCLUDE_INC_DIRS = "./.git" "./.git/*"
INC_DIRS = $(shell find . -type d $(addprefix -not -path , $(EXCLUDE_INC_DIRS)))
CFLAGS += $(addprefix -I, $(INC_DIRS))

ifeq ($(MAKECMDGOALS), debug)
	CFLAGS += -g -fsanitize=address
endif

# all
all: $(NAME)

-include $(DEPENDS)

# make files
$(NAME): $(OBJS)
	ar rcs $(NAME) $(filter %.o, $?)

# .PHONY rules

build: $(NAME) clean

clean:
	$(RM) $(OBJS) $(DEPENDS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
