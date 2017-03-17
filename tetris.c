/*
** tetris.c for tetris in /home/antonin.rapini/ModulesTek1/UnixSystemProgrammation/PSU_2016_tetris
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Thu Mar  2 18:33:06 2017 Antonin Rapini
** Last update Fri Mar 17 01:15:48 2017 Antonin Rapini
*/

#include <stdlib.h>
#include <curses.h>
#include <term.h>
#include <string.h>
#include "sources.h"
#include "my_game.h"
#include "utils.h"

int		main(int ac, char **av, char **env)
{
  t_game	*game;
  int		ret;
  char		*term;
  int		i;

  i = 1;
  while (i++ < ac)
    if (my_strcmp(av[i - 1], "--help") == 0)
      {
	my_print_help(av[0]);
	return (0);
      }
  if ((term = my_getterm(env)) == NULL)
    return (84);
  if ((setupterm(term, 1, &ret)) != 0)
    return (84);
  if ((game = my_create_game(ac, av)) == NULL)
    return (84);
  if (game->debug)
    {
      my_print_debug(game);
      my_putstr("Press any key to start Tetris");
    }
  return (my_play(game));
}
