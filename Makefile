# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rda-silv <rda-silv@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/19 08:22:25 by rda-silv          #+#    #+#              #
#    Updated: 2022/06/19 08:45:59 by rda-silv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

# Compilation
CC = gcc
CFLAG = -Wall -Wextra -Werror
OPTCC = -I. -c
RM = rm -f
MLX = -lmlx -Imlx -lXext -lX11

# External libs
LIBFT = ./libft/libft.a
LIBFT_PATH = ./libft

# Source files
SRC = ./src/create_map.c

%.o: %.c
	$(CC) -g $(CFLAGS) -c $< -o $(<:%.c=%.o)

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
		rm -rf $(NAME)
		make -C ${LIBFT_PATH}
		$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX) -o $(NAME)

clean:
		$(RM) $(SRC.O)
		make fclean -C ${LIBFT_PATH}

re: fclean all

.PHONY: All clean fclean re