/*
** my_parse_args.c for tetris in /home/antonin.rapini/ModulesTek1/UnixSystemProgrammation/PSU_2016_tetris/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Fri Mar 10 19:02:17 2017 Antonin Rapini
** Last update Sat Mar 11 16:33:06 2017 Antonin Rapini
*/

#include "my_game.h"
#include "utils.h"

int my_parse_option(char *arg, t_game *game)
{
  if (my_strcmp("-w", arg) == 0 || my_strcmp("--without-next", arg) == 0)
    game->shownext = 0;
  else if (my_strcmp("-d", arg) == 0 || my_strcmp("--debug", arg) == 0)
    game->debug = 1;
  else if (my_strncmp("--map-size=", arg, 11) == 0)
    return (my_setmapsize(game, arg + 11));
  else
    return (1);
  return (0);
}

int	my_parse_input(int *i, int ac, char **av, t_game *game)
{
  int	j;

  j = 0;
  while (game->inputs[j])
    {
      if (my_strcmp(game->inputs[j].arg, av[*i]))
	{
	  if (*i + 1 <= ac)
	    {
	      *i = *i + 1;
	      game->inputs[j].arg = av[*i];
	      return (0);
	    }
	  else
	    return (1);
	}
      else if (my_strncmp(game->inputs[j].longarg, av[*i],
			  my_strlen(game->inputs[j].longarg)) == 0)
	{
	  if (my_strlen(av[*i]) > my_strlen(game->inputs[j].longarg))
	    {
	      game->inputs[j].input = my_strdup(av[*i] + game->inputs[j].longarg);
	    }
	}
      j++;
    }
}

int	my_parse_args(int ac, char **av, t_game *game)
{
  int	i;

  i = 0;
  while (i < ac)
    {
      if (my_parse_input(&i, ac, av, game))
	return (1);
      else if (my_strncmp("--level=", av[i], 8) == 0)
	{
	  if (my_setlevel(av[i] + 8, game))
	    return (1);
	}
      else if (my_strcmp("-l", av[i]) == 0)
	{
	  if (i + 1 <= ac)
	    {
	      if (my_setlevel(av[i + 1], game))
		return (1);
	      i++;
	    }
	  else
	    return (1);
	}
      else if (my_parse_option(av[i], game))
	return (1);
      i++;
    }
  return (0);
}
