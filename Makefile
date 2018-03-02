# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/28 10:34:43 by mtan              #+#    #+#              #
#    Updated: 2018/03/02 13:28:35 by ikozlov          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fillit

CC		= gcc
CFLAGS 	= -Wall -Wextra -Werror

SRC_DIR = ./src/
INC_DIR	= ./includes/
OBJ_DIR = ./obj/
LIB_DIR	= ./lib/libft/

SRC = $(addprefix $(SRC_DIR),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_DIR),$(OBJ_NAME))
INC = $(addprefix -I,$(INC_DIR))

SRC_NAME = main.c \
		   read.c \
		   solver.c
OBJ_NAME = $(SRC_NAME:.c=.o)
INC_NAME = fillit.h

.PHONY: all $(NAME) clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIB_DIR)
	@$(CC) $(OBJ) -L $(LIB_DIR) -l ft -o $(NAME)
	@echo "[INFO] Fillit created"

$(OBJ_DIR)%.o:$(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INC) -I$(LIB_DIR) -o $@ -c $<

clean:
	@make -C $(LIB_DIR) clean
	rm -rf $(OBJ_DIR)
	@echo "[INFO] Object folder removed"

fclean: clean
	@make -C $(LIB_DIR) fclean
	rm -rf $(NAME)
	@echo "[INFO] Executable removed"

re:
	@$(MAKE) fclean --no-print-directory
	@$(MAKE) all --no-print-directory

relib:
	@$(MAKE) -C $(LIB_DIR) re --no-print-directory
	@$(MAKE) re --no-print-directory
