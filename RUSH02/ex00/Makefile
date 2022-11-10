# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wyoon <wyoon@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/11 02:13:06 by woojun            #+#    #+#              #
#    Updated: 2022/09/11 20:49:09 by wyoon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
# 컴파일러
CFLAGS = -Werror -Wall -Wextra
# 컴파일 옵션
NAME = rush-02

all: $(NAME)

$(NAME) : 
	$(CC) $(CFLAGS) main.c -o $(NAME)

clean :
	rm -rf *.o

fclean : clean
	rm -rf $(NAME)

re:	fclean all