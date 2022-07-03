# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rda-silv <rda-silv@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/03 15:34:52 by rda-silv          #+#    #+#              #
#    Updated: 2022/07/03 15:36:07 by rda-silv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# LIBFT_PATH		=	./library/libft
# LIBFT			=	$(LIBFT_PATH)/libft.a

MINILIBX_PATH	=	./library/minilibx
MINILIBX		=	$(MINILIBX_PATH)/libmlx.a

SOURCE_FILES	=	main.c 

SOURCE_DIR		=	source
HEADER			=	$(SOURCE_DIR)/so_long.h

SOURCES			=	$(addprefix $(SOURCE_DIR)/, $(SOURCE_FILES))

OBJECTS			= 	$(SOURCES:.c=.o)

NAME			=	so_long

CC				=	gcc
RM				=	rm -f

CFLAGS			=	-Wall -Wextra -Werror
MLXFLAGS		=	-L. -lXext -L. -lX11

.c.o:
				$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:			$(NAME)

# $(NAME):		$(LIBFT) $(MINILIBX) $(OBJECTS) $(HEADER)
$(NAME):		$(MINILIBX) $(OBJECTS) $(HEADER)
				$(CC) $(CFLAGS) $(OBJECTS) $(MINILIBX) $(MLXFLAGS) -o $(NAME)


# $(LIBFT):
# 				$(MAKE) -C $(LIBFT_PATH)

$(MINILIBX):
				$(MAKE) -C $(MINILIBX_PATH)

clean:
#				$(MAKE) -C $(LIBFT_PATH) clean
				$(MAKE) -C $(MINILIBX_PATH) clean
				$(RM) $(OBJECTS)

fclean:			clean
#				$(MAKE) -C $(LIBFT_PATH) fclean
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re libft minilibx bonus
