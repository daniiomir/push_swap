# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: swarner <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/02 13:43:12 by swarner           #+#    #+#              #
#    Updated: 2019/09/12 18:59:24 by swarner          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT = lib
LIBFT_PATH = lib/libft.a
PUSH_SWAP = push_swap
CHECKER = checker

HEADERS = -I includes/
FLAGS = -Wall -Wextra -Werror

SRC_FOLDER = src
OBJ_FOLDER = obj

CH_SRC_NAMES = ch_main.c tools.c tools2.c p.c s.c r.c rr.c
PS_SRC_NAMES = ps_main.c tools.c tools2.c p.c s.c r.c rr.c algorithm.c sort.c

CH_SRC = $(addprefix $(SRC_FOLDER)/, $(CH_SRC_NAMES))
PS_SRC = $(addprefix $(SRC_FOLDER)/, $(PS_SRC_NAMES))

CH_OBJ = $(addprefix $(OBJ_FOLDER)/, $(CH_SRC_NAMES:.c=.o))
PS_OBJ = $(addprefix $(OBJ_FOLDER)/, $(PS_SRC_NAMES:.c=.o))

all: $(LIBFT_PATH) $(PUSH_SWAP) $(CHECKER)

$(OBJ_FOLDER)/%.o: $(SRC_FOLDER)/%.c
	@mkdir -p $(OBJ_FOLDER)
	@gcc $(FLAGS) $(HEADERS) -c $< -o $@
	@echo "Obj -> done"

$(LIBFT_PATH):
	@make -C $(LIBFT)
	@echo "Libft -> done"

$(CHECKER): $(CH_OBJ)
	@gcc $(CH_OBJ) $(HEADERS) -L. $(LIBFT_PATH) -o $(CHECKER)
	@echo "Checker binary -> done"

$(PUSH_SWAP): $(PS_OBJ)
	@gcc $(PS_OBJ) $(HEADERS) -L. $(LIBFT_PATH) -o $(PUSH_SWAP)
	@echo "Push_swap binary -> done"

clean:
	@make clean -C $(LIBFT)
	@/bin/rm -rf $(OBJ_FOLDER)
	@echo "Obj removed"

fclean: clean
	@make fclean -C $(LIBFT)
	@/bin/rm -f $(PUSH_SWAP) $(CHECKER)
	@echo "Binaries removed"

re: fclean all
