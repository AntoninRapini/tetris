/*
** my_tetriminos.h for tetris in /home/antonin.rapini/ModulesTek1/UnixSystemProgrammation/PSU_2016_tetris/include
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Thu Mar  2 18:56:59 2017 Antonin Rapini
** Last update Fri Mar 10 22:43:32 2017 Antonin Rapini
*/

#ifndef MY_GAME_H_
# define MY_GAME_H_

#include "my_tetriminos.h"
#include "my_inputs.h"
#include "my_vector2.h"

typedef struct	s_game
{
  int		startlevel;
  int		tetriminoscount;
  t_vector2	mapsize;
  t_tlist	*tetriminoslist;
  t_input	*inputs;
  int		debug;
  int		shownext;
}		t_game;

#endif /* !MY_GAME_H_ */
