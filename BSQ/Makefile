# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wyoon <wyoon@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/13 13:01:53 by woojun            #+#    #+#              #
#    Updated: 2022/09/14 14:12:25 by wyoon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror

NAME = BSQ

SRC_DIR = ./srcs

HD_DIR = ./includes

SRCS = $(SRC_DIR)/main.c $(SRC_DIR)/make_map.c $(SRC_DIR)/print_map.c $(SRC_DIR)/print_map_sub.c

OBJS = $(SRCS:.c=.o)

RM = rm -f

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@
# $^ : 현재 Target이 의존하는 대상들의 전체 목록
%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(HD_DIR)
# $< : 현재 Target이 의존하는 대상들 중 변경된 것들의 목록
clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re