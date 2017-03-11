/*
** sources.h for base in /home/antonin.rapini/my_programs/include
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Thu Mar  2 17:18:06 2017 Antonin Rapini
** Last update Fri Mar 10 19:30:42 2017 Antonin Rapini
*/

#ifndef SOURCES_H_
# define SOURCES_H_

#include "my_tetriminos.h"
#include "my_game.h"

t_tetriminos *my_check_tetrimino(char *);
void my_show_tetrimino(t_tetriminos *);
t_game *my_create_game(int, char **);
t_tlist *my_create_tetriminoslist(t_game *);
t_input *my_set_inputs();

#endif /* !SOURCES_H_ */
