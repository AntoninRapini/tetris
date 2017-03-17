/*
** my_parse_args.c for tetris in /home/antonin.rapini/ModulesTek1/UnixSystemProgrammation/PSU_2016_tetris/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Fri Mar 10 19:02:17 2017 Antonin Rapini
** Last update Fri Mar 17 01:41:44 2017 Antonin Rapini
*/

#include <stdlib.h>
#include "my_game.h"
#include "utils.h"

int	my_parse_longarg(int i, char **av, t_input *input)
{
  int	longarglen;

  longarglen = my_strlen(input->longarg);
  if (my_strncmp(input->longarg, av[i], longarglen) == 0)
    {
      if (my_strlen(av[i]) > longarglen)
	{
	  input->input = my_strdup(av[i] + longarglen);
	  return (2);
	}
      return (1);
    }
  return (0);
}

int my_parse_inputarg(int *i, int ac, char **av, t_input *input)
{
  if (my_strcmp(av[*i], input->arg) == 0)
    {
      if (*i + 1 < ac)
	{
	  (*i)++;
	  input->input = av[*i];
	  return (2);
	}
      return (1);
    }
  return (0);
}

int	my_parse_input(int *i, int ac, char **av, t_game *game)
{
  int	j;
  int	returnvalue;

  j = 0;
  while (game->inputs[j].arg != NULL)
    {
      if ((returnvalue = my_parse_inputarg(i, ac, av, game->inputs + j)))
	return (returnvalue);
      if ((returnvalue = my_parse_longarg(*i, av, game->inputs + j)))
	return (returnvalue);
      j++;
    }
  return (0);
}
