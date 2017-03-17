/*
** my_parse_args.c for tetris in /home/antonin.rapini/ModulesTek1/UnixSystemProgrammation/PSU_2016_tetris/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Fri Mar 10 19:02:17 2017 Antonin Rapini
** Last update Fri Mar 17 01:42:02 2017 Antonin Rapini
*/

#include <stdlib.h>
#include "my_game.h"
#include "sources.h"
#include "utils.h"

int my_parse_option(int *i, int ac, char **av, t_game *game)
{
  if (my_strncmp("--level=", av[*i], 8) == 0)
    return (my_setlevel(av[*i] + 8, game));
  else if (my_strcmp("-l", av[*i]) == 0)
    {
      if ((*i) + 1 < ac)
	{
	  (*i)++;
	  return (my_setlevel(av[(*i)], game));
	}
      return (1);
    }
  else if (my_strcmp("-w", av[*i]) == 0
	   || my_strcmp("--without-next", av[*i]) == 0)
    {
      game->shownext = 0;
      return (0);
    }
  else if (my_strcmp("-d", av[*i]) == 0 || my_strcmp("--debug", av[*i]) == 0)
    {
      game->debug = 1;
      return (0);
    }
  else if (my_strncmp("--map-size=", av[*i], 11) == 0)
      return (my_setmapsize(av[*i] + 11, game));
  return (1);
}

int	my_parse_args(int ac, char **av, t_game *game)
{
  int	i;
  int	status;

  i = 1;
  while (i < ac)
    {
      status = 0;
      status = my_parse_input(&i, ac, av, game);
      if (!status)
	status = my_parse_option(&i, ac, av, game);
      if (status == 1)
	return (1);
      i++;
    }
  return (0);
}
