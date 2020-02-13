# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rofeldsp <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/11 14:10:42 by rofeldsp          #+#    #+#              #
#    Updated: 2019/09/20 12:09:12 by rofeldsp         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
#
# NAME = libftprintf.a
#
# HEAD = ft_printf.h
#
# INP = ft_printf.c get_flag.c get_precision.c get_size.c get_type.c get_width.c parse_char.c parse_string.c parse_decimal.c
#
# OBJ = ft_printf.o get_flag.o get_precision.o get_size.o get_type.o get_width.o parse_char.o parse_string.o parse_decimal.o
#
# all: $(NAME)
#
# $(NAME):
# 	@gcc -Wall -Wextra -Werror -c $(INP) -I $(HEAD)
# 	@ar rc $(NAME) $(OBJ)
#
# clean:
# 	@/bin/rm -f $(OBJ)
#
# fclean: clean
# 	@/bin/rm -f $(NAME)
#
# re: fclean all
#
C = clang

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror -O2

LIBFT = libft

DIR_S = sources

DIR_O = temporary

HEADER = include // добавить phony

SOURCES = ft_printf.c \
          get_flag.c \
          get_precision.c \
          get_size.c \
          get_type.c \
          get_width.c \
          parse_char.c \
          parse_string.c \
          parse_decimal.c \
          adjust_functions.c \
          parse_percent.c \
          parse_hexodecimal.c \
          ft_putstr_printf.c \
          parse_octal.c \
          parse_udecimal.c \
          parse_pointer.c \
          parse_float.c \
          print_color.c \
          parse_binary.c \
          parse_unicode.c

SRCS = $(addprefix $(DIR_S)/,$(SOURCES))

OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT)
	@cp libft/libft.a ./$(NAME)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

$(DIR_O)/%.o: $(DIR_S)/%.c
	@mkdir -p temporary
	@$(CC) $(FLAGS) -I $(HEADER) -o $@ -c $<

norme:
	norminette ./libft/
	@echo
	norminette ./$(HEADER)/
	@echo
	norminette ./$(DIR_S)/

clean:
	@rm -f $(OBJS)
	@rm -rf $(DIR_O)
	@make clean -C $(LIBFT)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT)

re: fclean all
