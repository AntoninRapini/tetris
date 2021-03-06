/*
** sources.h for base in /home/antonin.rapini/my_programs/include
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Thu Mar  2 17:18:06 2017 Antonin Rapini
** Last update Sun Mar 19 21:01:30 2017 Antonin Rapini
*/

#ifndef SOURCES_H_
# define SOURCES_H_

#include "my_tetriminos.h"
#include "my_game.h"

t_tetriminos *my_get_tetriminos(char *, int fd, t_game *);
void my_show_tetriminoslist(t_tlist *);
t_game *my_create_game(int, char **);
t_tlist *my_create_tetriminoslist(t_game *);
t_input *my_set_inputs();
int my_parse_args(int, char**, t_game *);
void my_print_debug(t_game *);
void my_show_tetriminoslist(t_tlist *);
t_tetriminos *my_init_tetriminos();
int my_check_tetriminos(t_tetriminos *, t_game *);
void my_free_tetriminos(t_tetriminos *);
int my_parse_input(int *, int, char **, t_game *);
int my_play(t_game *);
int my_print_error(char *);

#endif /* !SOURCES_H_ */
