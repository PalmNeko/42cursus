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
LIBFT = Libft/libft.a

# compile settings
CC = cc
CFLAGS += -Wall -Werror -Wextra
SRCS += ./check_printf_format.c \
./conversion_specification/check_conv_specification_format.c \
./conversion_specification/free_t_conv_specification.c \
./conversion_specification/get_conv_specification.c \
./conversion_specification/get_conv_specification_len.c \
./conversion_specification/new_t_conv_specification.c \
./ft_printf.c \
./ft_vprintf_fd.c \
./printers/conv_specification.c \
./printers/print_char_fd.c \
./printers/print_decimal_fd.c \
./printers/print_hex_fd.c \
./printers/print_hex_upper_fd.c \
./printers/print_int_fd.c \
./printers/print_percent_fd.c \
./printers/print_pointer_fd.c \
./printers/print_string_fd.c \
./printers/print_uint_fd.c \
./printers/print_va_list_fd.c \
./utils/add_sign_with_cs.c \
./utils/gen_repeat_str.c \
./utils/gen_zero_pad_num_str.c \
./utils/is_conversion_specifier.c \
./utils/is_flag.c \
./utils/left_aligned_print.c \
./utils/left_aligned_print_char.c \
./utils/pad_zero_str.c \
./utils/repeat_print_fd.c \
./utils/right_aligned_print.c \
./utils/right_aligned_print_char.c \
./utils/t_conv_aligned_print.c \
./utils/t_conv_aligned_print_char.c \
./utils/zero_pad_with_cs.c

OBJS = $(SRCS:.c=.o)
DEPENDS = $(SRCS:.c=.d)

NAME_BONUS = bonus
SRC_BONUS = $(SRCS:.c=_bonus.c)
OBJS_BONUS = $(SRC_BONUS:.c=.o)
DEPENDS_BONUS = $(SRC_BONUS:.c=.d)


CFLAGS += -MMD -MP
INC_DIRS = \
	conversion_specification \
	printers \
	utils \
	Libft

CFLAGS += $(addprefix -I, $(INC_DIRS))

ifeq ($(MAKECMDGOALS), debug)
	CFLAGS += -g -fsanitize=address
endif

# all
all: $(NAME)

-include $(DEPENDS)
-include $(DEPENDS_BONUS)

# make files
$(NAME): $(LIBFT) $(OBJS)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(filter %.o, $?)

$(NAME_BONUS): $(LIBFT) $(OBJS_BONUS)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(filter %.o, $?)
	date > bonus

$(LIBFT):
	$(MAKE) --directory Libft

# .PHONY rules

debug: $(NAME)

build: $(NAME) clean

clean:
	$(MAKE) --directory Libft clean
	$(RM) $(OBJS) $(DEPENDS)
	$(RM) $(OBJS_BONUS) $(DEPENDS_BONUS)

fclean: clean
	$(MAKE) --directory Libft fclean
	$(RM) $(NAME)
	$(RM) $(NAME_BONUS)

re: fclean all

.PHONY: all clean fclean re debug
