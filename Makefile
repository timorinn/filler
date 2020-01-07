# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bford <bford@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/05 13:37:52 by bford             #+#    #+#              #
#    Updated: 2020/01/06 14:55:07 by bford            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		bford.filler

SRC =		main.c

LIBFT = 	./libft

FILLER =	./filler

LIBFTA =	./libft/libft.a

FILLERA =	./filler/libfiller.a

OBJ = $(SRC:.c=.o)

.PHONY: 	all clean fclean re

all:		$(NAME)

%.o:		%.c
			gcc -Wall -Werror -Wextra -g -I $(LIBFT) -I $(FILLER) -o $@ -c $<

$(NAME):	$(LIBFTA) $(FILLERA) $(OBJ) ./libft/libft.a ./filler/libfiller.a
			gcc -Wall -Werror -Wextra -g -o bford.filler $(OBJ) -L ./libft -lft -L ./filler -lfiller 

FORCE:		;

$(FILLERA):		FORCE
			make -C ./filler

$(LIBFTA):	FORCE
			make -C ./libft

clean:
			rm -f main.o
			make clean -C ./libft
			make clean -C ./filler

fclean:		clean
			rm -f $(NAME)
			make fclean -C ./libft
			make fclean -C ./filler

re:			fclean all
