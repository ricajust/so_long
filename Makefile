# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rda-silv <rda-silv@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/21 22:01:18 by rda-silv          #+#    #+#              #
#    Updated: 2022/06/22 22:03:05 by rda-silv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# VARIABLES
# project name
PROJ_NAME=so_long

# .c files
SRC_C=$(wildcard ./src/*.c)

# .h files
SRC_H=$(wildcard ./src/*.h)

# object file
#OBJ=$(patsubst %.c, obj/%.o, $(notdir $(SRC_C)))
OBJ=$(SRC_C:.c=.o)

# compiler
CC=gcc

# compiler flags
CC_FLAGS=-g      \
		 -Wall   \
		 -Wextra \
		 -Werror \
		 -lmlx   \
		 -lXext  \
		 -lX11

# others projects dependencies
MLX=minilibx/Makefile

# clean target
RM = rm -rf

# compilation and linking
all: $(PROJ_NAME)

$(PROJ_NAME): $(OBJ)
	@ echo 'Building binary using GCC linker: $@'
	$(CC) $^ -g -o $@
	@ echo 'Finished building binary: $@'
	@ echo ' '

$(MLX):
	@echo " [ .. ] | Compiling minilibx.."
	@make -s -C mlx
	@echo " [ OK ] | Minilibx ready!"

./obj/%.o: ./src/%.c ./src/%.h
	@ echo 'Building target using GCC compiler: $<'
	$(CC) $< $(CC_FLAGS) -o $@ $(X_FLAGS)
	@ echo ' '

./obj/main.o: ./src/main.c $(SRC_H)
	@ echo 'Building target using GCC compiler: $<'
	$(CC) $< $(CC_FLAGS) -o $@ $(X_FLAGS)
	@ echo ' '

clean:
	@ $(RM) ./src/*.o $(PROJ_NAME) *~

.PHONY: all clean