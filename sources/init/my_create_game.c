/*
** my_create_game.c for tetris in /home/antonin.rapini/ModulesTek1/UnixSystemProgrammation/PSU_2016_tetris/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Fri Mar  3 00:11:58 2017 Antonin Rapini
** Last update Sun Mar 12 21:44:36 2017 Antonin Rapini
*/

#include "sources.h"
#include "my_tetriminos.h"
#include "my_game.h"
#include <stdlib.h>

#include <stdio.h>

int my_set_default(t_game *game)
{
  game->startlevel = 1;
  game->mapsize.x = 20;
  game->mapsize.y = 10;
  game->debug = 0;
  game->shownext = 1;
  game->tetriminoscount = 0;
  if ((game->inputs = my_set_inputs()) == NULL)
    return (1);
  return (0);
}

t_game		*my_create_game(int ac, char **av)
{
  t_game	*game;

  if ((game = malloc(sizeof(t_game))) == NULL)
    return (NULL);
  if (my_set_default(game))
    return (NULL);
  if (my_parse_args(ac, av, game))
    return (NULL);
  if ((game->tetriminoslist = my_create_tetriminoslist(game)) == NULL)
    return (NULL);
  return (game);
}
