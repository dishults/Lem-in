# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dshults <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/14 18:34:55 by dshults           #+#    #+#              #
#    Updated: 2017/11/14 18:34:57 by dshults          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CFLAGS = -Wall -Wextra -Werror

CC = clang

SRCS = lib/ft_atoii.c \
	lib/ft_isasciii.c \
	lib/ft_isdigitt.c \
	lib/ft_isprintt.c \
	lib/ft_memallocc.c \
	lib/ft_nbrconvert_base.c \
	lib/ft_putnbr_base.c \
	lib/ft_putnbrr.c \
	lib/ft_putstrr.c \
	lib/ft_strchr_no_zeroo.c \
	lib/ft_strlenn.c \
	lib/ft_strndupp.c \
	plib/ft_co_get_var_size.c \
	plib/ft_convsp_char.c \
	plib/ft_convsp_num.c \
	plib/ft_num_funcs.c \
	plib/ft_num_o_u_x_p.c \
	plib/ft_p_flags.c \
	plib/ft_p_length.c \
	plib/ft_p_width_precision.c \
	ft_printf.c

OBJS = $(SRCS:.c=.o)

HDRS = ft_printf.h

all: $(NAME)
	@echo  ""

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $<
	@echo  "o\c"

$(NAME): $(OBJS) $(HDRS) Makefile
	@echo "\n\tft_printf .o files\t\tdone"
	@ar rc $(NAME) $?
	@ranlib $(NAME)
	@echo "\tStatic library libftprintf.a\tdone"

$(OBJS): $(HDRS) Makefile

clean:
	@rm -rf $(OBJS)
	@echo "\tft_printf clean\t\t\tdone"

fclean: clean
	@rm -rf $(NAME)
	@echo "\tft_printf fclean\t\tdone"

re: fclean all
