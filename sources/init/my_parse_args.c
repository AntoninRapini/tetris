/*
** my_parse_args.c for tetris in /home/antonin.rapini/ModulesTek1/UnixSystemProgrammation/PSU_2016_tetris/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Fri Mar 10 19:02:17 2017 Antonin Rapini
** Last update Mon Mar 13 06:37:53 2017 Antonin Rapini
*/

#include <stdlib.h>
#include "my_game.h"
#include "utils.h"

#include <stdio.h>

int my_parse_option(int *i, int ac, char **av, t_game *game)
{
  if (my_strncmp("--level=", av[*i], 8) == 0)
    return (my_setlevel(av[*i] + 8, game));
  else if (my_strcmp("-l", av[*i]) == 0)
    {
      if ((*i) + 1 < ac)
	{
	  (*i)++;
	  return (my_setlevel(av[(*i) + 1], game));
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

int	my_parse_input(int *i, int ac, char **av, t_game *game)
{
  int	j;

  j = 0;
  while (game->inputs[j].arg != NULL)
    {
      if (my_strcmp(game->inputs[j].arg, av[*i]) == 0)
	{
	  if (*i + 1 < ac)
	    {
	      (*i)++;
	      game->inputs[j].arg = av[*i];
	      return (2);
	    }
	  else
	    return (1);
	}
      else if (my_strncmp(game->inputs[j].longarg, av[*i],
			  my_strlen(game->inputs[j].longarg)) == 0)
	{
	  if (my_strlen(av[*i]) > my_strlen(game->inputs[j].longarg))
	    {
	      game->inputs[j].input = my_strdup(av[*i] +
						my_strlen(game->inputs[j].longarg));
	      return (2);
	    }
	  else
	    return (1);
	}
      j++;
    }
  return (0);
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
