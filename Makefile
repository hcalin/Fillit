# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chrihorc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/23 20:29:01 by chrihorc          #+#    #+#              #
#    Updated: 2017/02/03 20:59:52 by chrihorc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRCS = src/main.c src/valid.c src/back.c src/fill.c src/verif.c

OBJ = *.o

INC = includes/

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME) :
	make -C libft
	gcc $(FLAGS) -I $(INC) -c $(SRCS)
	gcc $(OBJ) -L libft/ -lft -o $(NAME)

clean:
	make -C libft/ clean
	rm -f $(OBJ)

fclean: clean
	make -C libft/ fclean
	rm -f $(NAME)

re: fclean all
