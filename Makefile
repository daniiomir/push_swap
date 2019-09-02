# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: swarner <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/02 13:43:12 by swarner           #+#    #+#              #
#    Updated: 2019/09/02 13:43:17 by swarner          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT = lib/
LIBFT_PATH = lib/libft.a
PUSH_SWAP = push_swap
CHECKER = checker

HEADERS = -I includes/
FLAGS = -Wall -Wextra -Werror

SRC_FOLDER = src

CH_SRC_NAMES = ch_main.c
PS_SRC_NAMES = ps_main.c

CH_SRC = $(addprefix $(SRC_FOLDER)/, $(CH_SRC_NAMES))
PS_SRC = $(addprefix $(SRC_FOLDER)/, $(PS_SRC_NAMES))

CH_OBJ = $(CH_SRC_NAMES:.c=.o)
PS_OBJ = $(PS_SRC_NAMES:.c=.o)

all: $(LIB) $(PS) # $(CHECKER)

%.o: $(SRC_FOLDER)/%.c
	gcc $(FLAGS) $(HEADERS) -c $< -o $@

$(LIB):
	make -C $(LIBFT)

$(CHECKER): $(CH_OBJ)
	gcc -o $@ $(CH_OBJ) $(HEADERS) $(LIBFT_PATH)

$(PS): $(PS_OBJ)
	gcc -o $(PUSH_SWAP) $(PS_OBJ) $(HEADERS) $(LIBFT_PATH)

clean:
	@make clean -C $(LIBFT)
	@/bin/rm -f $(CH_OBJ) $(PS_OBJ)

fclean: clean
	@make fclean -C $(LIBFT)
	@/bin/rm -f $(PUSH_SWAP) $(CHECKER)

re: fclean all