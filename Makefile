# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pcahier <pcahier@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 11:03:45 by pcahier           #+#    #+#              #
#    Updated: 2018/11/29 17:50:57 by pcahier          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pcahier.filler

SRCS_PATH = srcs/
OBJ_PATH  = obj/
LIBFT_PATH = libft/

FLAGS = -Wall -Werror -Wextra
INC = -I ./includes/ -I ./$(LIBFT_PATH)/

SRCS_NAME = filler.c		\
			fil_process.c	\
			filheat.c		\
			fil_piece.c		\

SRCS = $(addprefix $(SRCS_PATH), $(SRCS_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(SRCS_NAME:.c=.o))

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBFT_PATH)
	@gcc $(FLAGS) $(OBJ) $(INC) -L $(LIBFT_PATH) -lft -o $(NAME)
	@echo "\033[32mBinary \033[1;32m$(NAME)\033[1;0m\033[32m created.\033[0m"

$(OBJ_PATH)%.o: $(SRCS_PATH)%.c
	@mkdir -p obj
	@gcc -c $(FLAGS) $(INC) $< -o $@
	@echo "\033[34m\033[1mCompilation of \033[0m\033[36m$(notdir $<)\033[1m\033[34m done.\033[0m"

clean:
	@make -C $(LIBFT_PATH)/ clean
	@/bin/rm -rf $(OBJ_PATH)
	@echo "\033[31mObjects files directory for \033[1;31m$(NAME)\033[1;0m\033[31m removed.\033[0m"

fclean: clean
	@make -C $(LIBFT_PATH)/ mfclean
	@/bin/rm -rf $(NAME)
	@echo "\033[31mBin \033[1;31m$(NAME)\033[1;0m\033[31m removed.\033[0m"

re: 
	@make fclean
	@make all

.PHONY: all, clean, fclean, re
