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

NAME = libft.a

CFLAGS = -Wall -Wextra -Werror

CC = clang

SRCS = ft_atoi.c \
	ft_bzero.c \
	ft_count_char.c \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isprint.c \
	ft_itoa.c \
	ft_malloc_xy.c \
	ft_memalloc.c \
	ft_memccpy.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memdel.c \
	ft_memmove.c \
	ft_memset.c \
	ft_putchar_fd.c \
	ft_putchar.c \
	ft_putendl_fd.c \
	ft_putendl.c \
	ft_putnbr_fd.c \
	ft_putnbr.c \
	ft_putstr_fd.c \
	ft_putstr.c \
	ft_strcat.c \
	ft_strchr.c \
	ft_strchr_no_zero.c \
	ft_strclr.c \
	ft_strcmp.c \
	ft_strcpy.c \
	ft_strdel.c \
	ft_strdup.c \
	ft_strdup_c.c \
	ft_strequ.c \
	ft_striter.c \
	ft_striteri.c \
	ft_strjoin.c \
	ft_strlcat.c \
	ft_strlen.c \
	ft_strmap.c \
	ft_strmapi.c \
	ft_strncat.c \
	ft_strncmp.c \
	ft_strncpy.c \
	ft_strndup.c \
	ft_strnequ.c \
	ft_strnew.c \
	ft_strnstr.c \
	ft_strrchr.c \
	ft_strsplit.c \
	ft_strstr.c \
	ft_strsub.c \
	ft_strtrim.c \
	ft_tolower.c \
	ft_toupper.c \
	get_next_line/get_next_line.c

OBJS = $(SRCS:.c=.o)

HDRS = libft.h get_next_line/get_next_line.h

all: $(NAME)
	@echo  ""

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $<
	@echo  "o\c"

$(NAME): $(OBJS) $(HDRS) Makefile
	@echo "\n\tlibft .o files\t\t\tdone"
	@ar rc $(NAME) $?
	@ranlib $(NAME)
	@echo "\tStatic library libft.a\t\tdone"

$(OBJS): $(HDRS) Makefile

clean:
	@rm -rf $(OBJS)
	@echo "\tlibft clean\t\t\tdone"

fclean: clean
	@rm -rf $(NAME)
	@echo "\tlibft fclean\t\t\tdone"

re: fclean all
