# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/15 17:13:45 by sbrochar          #+#    #+#              #
#    Updated: 2017/10/18 00:47:45 by sbrochar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker

INC_DIR = ./inc
SRC_DIR = ./src
OBJ_DIR = ./obj

LIB_DIR = ./libft
LIB_INC = $(LIB_DIR)/inc

SRC = checker.c \
	  parsing_args.c \
	  instructions.c \
	  check.c
OBJ = $(patsubst %.c,$(OBJ_DIR)/%.o,$(SRC))

CC = clang
CFLAGS = -g -c -Wall -Wextra -Werror -I$(INC_DIR) -I$(LIB_INC)
LFLAGS = -L$(LIB_DIR) -lft

$(NAME): $(OBJ)
	make -C $(LIB_DIR)
	$(CC) -o $@ $^ $(LFLAGS)

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	make -C $(LIB_DIR) clean
	rm -f $(OBJ)

fclean: clean
	make -C $(LIB_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
