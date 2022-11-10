# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wyoon <wyoon@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/12 18:33:50 by wyoon             #+#    #+#              #
#    Updated: 2022/09/13 15:27:21 by wyoon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Werror -Wall -Wextra

SRC = ft_atoi.c ft_do_op.c ft_print.c main.c

OBJ = $(SRC:.c=.o)

RM = rm -f

NAME = do-op

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I .

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)


clean :
	$(RM) *.o

fclean : clean
	$(RM) $(NAME)