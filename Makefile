##
## Makefile for navy bootstrap in /home/antonin.rapini/ModulesTek1/UnixSystemProgrammation/PSU_2016_navy_bootstrap
## 
## Made by Antonin Rapini
## Login   <antonin.rapini@epitech.net>
## 
## Started on  Wed Feb  1 18:39:58 2017 Antonin Rapini
## Last update Thu Mar 16 19:00:44 2017 Antonin Rapini
##

CFLAGS	+= -Wall -Werror -Wextra
CFLAGS	+= -I include

SRC	=	utils/my_getnbr.c	\
		utils/get_next_line.c	\
		utils/my_putstr.c	\
		utils/my_put_nbr.c	\
		utils/my_wordtab_utils.c	\
		utils/my_strcmp.c	\
		utils/my_strncmp.c	\
		utils/my_str_to_wordtab.c	\
		utils/my_strndup.c	\
		utils/my_strncpy.c	\
		utils/my_nstrcat.c	\
		utils/my_strlen.c	\
		utils/my_putchar.c	\
		utils/my_nbrlen.c	\
		utils/my_sort_list.c	\
		utils/my_strdup.c	\
		utils/my_getterm.c	\
		utils/my_strstr.c	\
		utils/my_params_utils.c	\
		utils/my_miniprintf.c	\
		utils/my_tetriminos_utils.c	\
		sources/game/my_play.c		\
		sources/init/my_set_inputs.c	\
		sources/my_show_tetriminoslist.c	\
		sources/init/my_parse_input.c		\
		sources/init/my_create_tetriminoslist.c	\
		sources/init/my_get_tetriminos.c	\
		sources/init/my_create_game.c	\
		sources/init/my_parse_args.c		\
		sources/init/my_check_inputsequences.c	\
		sources/my_print_help.c		\
		sources/my_print_debug.c	\
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
