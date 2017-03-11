##
## Makefile for navy bootstrap in /home/antonin.rapini/ModulesTek1/UnixSystemProgrammation/PSU_2016_navy_bootstrap
## 
## Made by Antonin Rapini
## Login   <antonin.rapini@epitech.net>
## 
## Started on  Wed Feb  1 18:39:58 2017 Antonin Rapini
## Last update Sat Mar 11 16:38:14 2017 Antonin Rapini
##

CFLAGS	+= -Wall -Werror -Wextra
CFLAGS	+= -I include

SRC	=	utils/my_getnbr.c	\
		utils/get_next_line.c	\
		utils/my_putstr.c	\
		utils/my_show_wordtab.c	\
		utils/my_wordtablen.c	\
		utils/my_put_nbr.c	\
		utils/my_strcmp.c	\
		utils/my_strncmp.c	\
		utils/my_str_to_wordtab.c	\
		utils/my_strndup.c	\
		utils/my_strncpy.c	\
		utils/my_strlen.c	\
		utils/my_putchar.c	\
		utils/my_sort_list.c	\
		utils/my_strdup.c	\
		utils/my_getterm.c	\
		utils/my_params_utils.c	\
		sources/my_set_inputs.c	\
		sources/my_free_tetriminos.c	\
		sources/my_show_tetrimino.c	\
		sources/my_create_tetriminoslist.c	\
		sources/my_check_tetrimino.c	\
		sources/my_create_game.c	\
		sources/my_print_help.c		\
		sources/my_parse_args.c		\
		tetris.c

OBJ	= 	$(SRC:.c=.o)

NAME	=	tetris

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(OBJ) -lncurses -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
