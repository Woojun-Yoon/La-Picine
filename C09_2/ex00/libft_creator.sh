#!/bin/bash
gcc -Werror -Wall -Wextra -c ft_putchar.c ft_putstr.c ft_strcmp.c ft_strlen.c ft_swap.c
ar rc libft.a ft_putchar.o ft_putstr.o ft_strcmp.o ft_strlen.o ft_swap.o
# ar : 오브젝트 파일을 묶어 주는 명령어
# r : 새로운 오브젝트 파일이면 추가, 기존 파일이면 치환
# c : 라이브러리 파일 생성, 존재하지 않는 경우에도 경고 메세지를 출력하지 않음