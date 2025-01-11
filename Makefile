# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alex <alex@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/04 21:21:20 by alex              #+#    #+#              #
#    Updated: 2025/01/10 11:38:18 by alex             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address

SRC_FILE = /home/$(USER)/pipex_repo/Src_normal
SRC_BONUS = /home/$(USER)/pipex_repo/Src_bonus
INCLUDE = /home/$(USER)/Proyects/pipex/Include

SRCS = $(SRC_FILE)/pipex.c $(SRC_FILE)/utils.c
BONUS_SRCS = $(SRC_BONUS)/pipex_bonus.c $(SRC_BONUS)/utils_bonus.c \
			$(SRC_BONUS)/parse_bonus.c \
			$(SRC_BONUS)/exes_and_redirs_bonus.c
			
LIBFT_DIR = $(INCLUDE)/libft
PRINTF_DIR = $(INCLUDE)/ft_printf

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:%.c=%.o)

HEADERS = pipex.h
LIBFT = libft.a
PRINTF = libftprintf.a


all: $(LIBFT) $(PRINTF) $(NAME)

bonus: $(LIBFT) $(PRINTF)
	$(MAKE) OBJS="$(BONUS_OBJS)" $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -I$(SRC_FILE) -L$(LIBFT_DIR) -lft -L$(PRINFT_DIR) -lftprintf -o $(NAME)


%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT): 
	make all -C $(INCLUDE)/libft

$(PRINTF):
	make all -C $(INCLUDE)/ft_printf
	
libft:
	make all -C $(INCLUDE)/libft

printf:
	make all -C $(INCLUDE)/ft_printf
	
clean:
	make clean -C $(INCLUDE)/libft
	make clean -C $(INCLUDE)/ft_printf
	rm -f $(OBJS) $(BONUS_OBJS)
	
fclean: clean
	make fclean -C $(INCLUDE)/libft
	make fclean -C $(INCLUDE)/ft_printf
	rm -f $(NAME)

re: fclean all

PHONY: make clean fclean re bonus