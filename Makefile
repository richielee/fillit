# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rili <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/26 17:12:37 by rili              #+#    #+#              #
#    Updated: 2017/04/26 18:02:52 by rili             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

#directories
SRC_DIR = ./src/
LIB_DIR = ./lib/
INC_DIR = ./includes/
OBJ_DIR = ./obj/

#src / obj files
SRC = tetriminos_reader.c main.c
OBJ = $(SRC:.c=.o)
SRC_POS = $(addprefix $(SRC_DIR),$(SRC))

FLAGS = -Wall -Werror -Wextra
CC = gcc
LIBFT = ./lib/libft.a

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
		$(CC) $(FLAGS) $(OBJ) -o $(NAME) $(LIBFT)

$(OBJ): $(LIBFT)
		$(CC) $(FLAGS) -c $(SRC_POS)

$(LIBFT):
		make -C ./lib/
clean :
		rm -f $(OBJ)
		make clean -C ./lib/
fclean: clean
		rm -f $(NAME)
		make clean -C ./lib/

re: fclean all

.PHONY : all, re, clean, fclean
