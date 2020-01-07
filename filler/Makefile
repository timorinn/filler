# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bford <bford@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/06 11:34:46 by bford             #+#    #+#              #
#    Updated: 2020/01/06 19:24:19 by bford            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC	=		ft_check_exec.c

OBJ =		$(SRC:.c=.o)

HEAD =		filler.h

NAME =		libfiller.a

all:		$(NAME)

$(NAME):	$(OBJ) filler.h
			ar -rcs $(NAME) $(OBJ)

%.o:		%.c $(HEAD)
			gcc -I ./ -Wall -Wextra -Werror -g -c $< -o $@

clean:
			rm -f $(OBJ)

fclean:		clean
			rm -f $(NAME)

re:			fclean all
