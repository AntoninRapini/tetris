/*
** tetris.c for tetris in /home/antonin.rapini/ModulesTek1/UnixSystemProgrammation/PSU_2016_tetris
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Thu Mar  2 18:33:06 2017 Antonin Rapini
** Last update Fri Mar 10 22:51:57 2017 Antonin Rapini
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

  if (game)
    {
    }
  if (ac >= 2)
    {
      if (my_strcmp(av[1], "--help") == 0)
	{
	  my_print_help();
	  return (0);
	}
    }
  if ((term = my_getterm(env)) == NULL)
    return (84);
  if ((setupterm(term, 1, &ret)) != 0)
    return (84);
  if ((game = my_create_game(ac, av)) == NULL)
    return (84);
  return (0);
}
