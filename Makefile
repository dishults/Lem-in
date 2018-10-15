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

NAME = lem-in

CFLAGS = -Wall -Wextra -Werror

CC = clang

SRCS =	main.c						\
		r_rooms.c					\
		r_check_room.c				\
		r_start_end_rooms_comment.c \
		l_links.c					\
		l_start_end_room_links.c 	\
		l_check_link.c				\
		p_paths.c					\
		p_make_or_add_path.c 		\
		s_sort.c					\
		s_sort_startroom_links.c 	\
		s_path_combos.c				\
		move.c						\
		free_all.c					\
		free_r_l_srl_p.c

OBJS = $(SRCS:.c=.o)

HDRS = lem_in.h

LIBS = libft/libft.a libft/ft_printf/libftprintf.a

COMPILE = $(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS)

all: ft ftprintf echolemin $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $<
	@echo  "o\c"

$(NAME): $(OBJS) $(HDRS) Makefile
	@echo "\n\tlem-in .o files\t\t\tdone"
	@$(COMPILE)
	@echo "\tExecutable lem-in\t\tdone"

$(OBJS): $(HDRS) $(LIBS) Makefile

ft:
	@echo "\n\t\tLIBFT"
	@$(MAKE) -C libft all

ftprintf:
	@echo "\t\tFT_PRINTF"
	@$(MAKE) -C libft/ft_printf all

echolemin:
	@echo "\t\tLEM-IN"

clean:
	@rm -rf $(OBJS)
	@echo "\tlem-in clean\t\t\tdone"
	@$(MAKE) -C libft clean
	@$(MAKE) -C libft/ft_printf/ clean

fclean: clean
	@rm -rf $(NAME)
	@echo "\tlem-in fclean\t\t\tdone"
	@$(MAKE) -C libft fclean
	@$(MAKE) -C libft/ft_printf fclean

re: fclean all
