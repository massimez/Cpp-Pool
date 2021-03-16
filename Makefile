##
## EPITECH PROJECT, 2021
## rush3
## File description:
## Makefile for rush3
##

SRC	=	Monitors/DateTime.cpp		\
		Monitors/Hostname.cpp		\
		Monitors/UserName.cpp		\
		Monitors/OSName.cpp			\
		Monitors/CPU.cpp			\
		Monitors/RAM.cpp			\
		main.cpp

OBJ	=	$(SRC:.cpp=.o)

NAME	=	gkrellm

all:	build clean

build:	$(OBJ)
	g++ $(OBJ) -o $(NAME) -lsfml-graphics -lsfml-window -lsfml-system -lcurses

clean:
	find -name "*.o" -delete
	find -name "*~" -delete

fclean:	clean
	find -name "$(NAME)" -delete

re:	fclean all

.PHONY: all build clean fclean re
