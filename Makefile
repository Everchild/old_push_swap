# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/15 17:13:45 by sbrochar          #+#    #+#              #
#    Updated: 2017/11/06 13:36:37 by sbrochar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = checker
NAME2 = push_swap

INC_DIR = ./inc
SRC_DIR = ./src
OBJ_DIR = ./obj

LIB_DIR = ./libft
LIB_INC = $(LIB_DIR)/inc

SRC1 = checker.c \
	   check.c
SRC2 = push_swap.c \
	   push_n_swap.c \
	   insert_in_a.c
SRC_COMMON = instructions.c \
			 parsing_args.c

OBJ1 = $(patsubst %.c,$(OBJ_DIR)/%.o,$(SRC1))
OBJ2 = $(patsubst %.c,$(OBJ_DIR)/%.o,$(SRC2))
OBJ_COMMON = $(patsubst %.c,$(OBJ_DIR)/%.o,$(SRC_COMMON))

CC = clang
CFLAGS = -g3 -c -Wall -Wextra -Werror -I$(INC_DIR) -I$(LIB_INC)
LFLAGS = -L$(LIB_DIR) -lft -fsanitize=address

all: $(NAME1) $(NAME2)

$(NAME1): $(OBJ1) $(OBJ_COMMON)
	make -C $(LIB_DIR)
	$(CC) -o $@ $^ $(LFLAGS)

$(NAME2): $(OBJ2) $(OBJ_COMMON)
	make -C $(LIB_DIR)
	$(CC) -o $@ $^ $(LFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	make -C $(LIB_DIR) clean
	rm -f $(OBJ)

fclean: clean
	make -C $(LIB_DIR) fclean
	rm -f $(NAME1)
	rm -f $(NAME2)

re: fclean all

.PHONY: all clean fclean re
