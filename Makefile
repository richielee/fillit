# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rili <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/26 17:12:37 by rili              #+#    #+#              #
#    Updated: 2017/04/26 17:29:48 by rili             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

#directories
SRC_DIR = ./src
LIB_DIR = ./lib

#src / obj files
SRC = tetriminos_reader.c main.c
OBJ = $(SRC:.c=.o)

FLAG = -Wall -Werror -Wextra
all: $(NAME)

$(NAME) :
	gcc -c $(NAME) $(SRC) $(FLAG) -I .
