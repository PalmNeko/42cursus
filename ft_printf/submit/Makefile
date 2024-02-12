# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/05 16:10:34 by tookuyam          #+#    #+#              #
#    Updated: 2024/02/12 16:29:35 by tookuyam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# overview
NAME = libftprintf.a

# libraries
LIBFT = Libft/libft.a

# compile settings
CC = cc
CFLAGS += -Wall -Werror -Wextra
SRCS += \
	./aligned_print/left_aligned_print.c \
	./aligned_print/left_aligned_print_char.c \
	./aligned_print/right_aligned_print.c \
	./aligned_print/right_aligned_print_char.c \
	./aligned_print/t_conv_aligned_print.c \
	./aligned_print/t_conv_aligned_print_char.c \
	./conversion_specification/check_conv_specification_format.c \
	./conversion_specification/free_t_cs.c \
	./conversion_specification/generate_cs.c \
	./conversion_specification/get_cs_len.c \
	./conversion_specification/is_conversion_specifier.c \
	./conversion_specification/is_flag.c \
	./conversion_specification/is_set_zero_precision.c \
	./conversion_specification/new_t_cs.c \
	./ft_printf/ft_printf.c \
	./ft_vdprint_cs/ft_vdprint_char_cs.c \
	./ft_vdprint_cs/ft_vdprint_cs.c \
	./ft_vdprint_cs/ft_vdprint_decimal_cs.c \
	./ft_vdprint_cs/ft_vdprint_hex_cs.c \
	./ft_vdprint_cs/ft_vdprint_hex_upper_cs.c \
	./ft_vdprint_cs/ft_vdprint_int_cs.c \
	./ft_vdprint_cs/ft_vdprint_percent_cs.c \
	./ft_vdprint_cs/ft_vdprint_pointer_cs.c \
	./ft_vdprint_cs/ft_vdprint_string_cs.c \
	./ft_vdprint_cs/ft_vdprint_uint_cs.c \
	./ft_vdprint_cs/generate_ul_hex_with_cs.c \
	./ft_vdprintf/ft_vdprintf.c \
	./utils/pad_zero_str.c \
	./utils/repeat_print_fd.c \
	./utils/zero_pad_with_cs.c

INCLUDES = \
	./aligned_print/aligned_print.h \
	./conversion_specification/conversion_specification.h \
	./conversion_specification/conversion_specification_utils.h \
	./ft_printf.h \
	./ft_vdprint_cs/_ft_vdprint_cs.h \
	./ft_vdprint_cs/ft_vdprint_cs.h \
	./ft_vdprintf/ft_vdprintf.h \
	./Libft/libft.h \
	./utils/string_util.h

OBJS = $(SRCS:.c=.o)
DEPENDS = $(SRCS:.c=.d)

NAME_BONUS = bonus
SRC_BONUS = $(addprefix bonus_files/, $(notdir $(SRCS:.c=_bonus.c)))
OBJS_BONUS = $(SRC_BONUS:.c=.o)
DEPENDS_BONUS = $(SRC_BONUS:.c=.d)


CFLAGS += -MMD -MP
INC_DIRS = \
	. \
	aligned_print \
	conversion_specification \
	ft_printf \
	ft_vdprint_cs \
	ft_vdprintf \
	Libft \
	utils \
	bonus_files

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
	$(RM) $(NAME)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(filter %.o, $^)

$(NAME_BONUS): $(LIBFT) $(OBJS_BONUS)
	$(RM) $(NAME)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(filter %.o, $^)
	date > bonus

$(LIBFT):
	$(MAKE) --directory Libft

# .PHONY rules

debug: $(NAME)

build: $(NAME) clean

update_bonus:
	mkdir -p bonus_files
	@for i in $(SRCS); \
	do \
		bonus_file_name=$$(echo $$i | sed -E 's/\.c$$/_bonus\.c/g'); \
		bonus_file_name="bonus_files/$$(basename $$bonus_file_name)"; \
		cp $$i $$bonus_file_name; \
		sed -i".bak" -E 's/\.h"$$/_bonus\.h"/g' $$bonus_file_name; \
		bonus_file_base_name="$$(basename $$bonus_file_name | sed 's/\./\\./g')"; \
		file_base_name="$$(basename $$i | sed 's/\./\\./g')      "; \
		sed -i".bak" "s/$$file_base_name/$$bonus_file_base_name/g" $$bonus_file_name; \
		sed -i".bak" 's/libft_bonus.h/libft.h/g' $$bonus_file_name; \
	done
	@for i in $(INCLUDES); \
	do \
		if [[ ! $$i =~ "libft" ]]; then \
			bonus_file_name=$$(echo $$i | sed -E 's/\.h$$/_bonus\.h/g'); \
			bonus_file_name="bonus_files/$$(basename $$bonus_file_name)"; \
			cp $$i $$bonus_file_name; \
			sed -i".bak" -E 's/\.h"$$/_bonus\.h"/g' $$bonus_file_name; \
			sed -i".bak" 's/libft_bonus.h/libft.h/g' $$bonus_file_name; \
			bonus_file_base_name="$$(basename $$bonus_file_name | sed 's/\./\\./g')"; \
			file_base_name="$$(basename $$i | sed 's/\./\\./g')      "; \
			sed -i".bak" "s/$$file_base_name/$$bonus_file_base_name/g" $$bonus_file_name; \
			file_base_name_header=$$(echo $$file_base_name | tr "[a-z]" "[A-Z]" | tr '.' '_'); \
			bonus_file_base_name_header=$$(echo $$bonus_file_base_name | tr "[a-z]" "[A-Z]" | tr '.' '_'); \
			sed -i".bak" "s/$$file_base_name_header/$$bonus_file_base_name_header/g" $$bonus_file_name; \
		fi; \
	done

clean:
	$(MAKE) --directory Libft clean
	$(RM) $(OBJS) $(DEPENDS)
	$(RM) $(OBJS_BONUS) $(DEPENDS_BONUS)
	$(RM) *.bak
	$(RM) **/*.bak

fclean: clean
	$(MAKE) --directory Libft fclean
	$(RM) $(NAME)
	$(RM) $(NAME_BONUS)

re: fclean all

.PHONY: all clean fclean re debug
