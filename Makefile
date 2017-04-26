# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rili <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/26 17:12:37 by rili              #+#    #+#              #
#    Updated: 2017/04/26 17:42:08 by rili             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

#directories
SRC_DIR = ./src
LIB_DIR = ./lib
INC_DIR = ./includes
OBJ_DIR = ./obj

#src / obj files
SRC = tetriminos_reader.c main.c
OBJ = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

FLAGS = -Wall -Werror -Wextra
CC = gcc

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
		$(CC) $(FLAGS) $(OBJ) -o $(NAME) $(LIBFT)

$(OBJ): $(LIBFT)
		$(CC) $(FLAGS) -C $(SRC_DIR)$(SRC)

$(LIBFT):
		make -C .lib/
