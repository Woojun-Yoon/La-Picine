# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wyoon <wyoon@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/10 14:00:01 by wyoon             #+#    #+#              #
#    Updated: 2022/09/10 15:08:38 by wyoon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
# 컴파일러 내장변수
CFLAGS = -Wall -Werror -Wextra
# 컴파일 옵션 내장변수
SRC = srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c
# srcs 폴더 안의 각 c 파일들을 나타내는 변수 선언
RM = rm -f
# 삭제 명령어 선언
NAME = libft.a
# 만들고자 하는 파일의 이름 선언
OBJ = $(SRC:.c=.o)
# 오브젝트 파일들을 선언
all: $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I includes/
# -I옵션으로 디렉토리를 지정하면 시스템 헤더 디렉토리보다 우선해서 찾는다
$(NAME) : $(OBJ)
	ar -rc $(NAME) $(OBJ)

clean: 
	$(RM) $(OBJ)

fclean: clean 
	$(RM) $(NAME)

re: fclean all

# 타겟(목표 파일) : 의존성(목표 파일을 만드는데 필요한 구성요소들)
#	명령어(목적을 달성하기 위한 명령)
#	명령어(목적을 달성하기 위한 명령)