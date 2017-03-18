/*
** my_params.c for tetris in /home/antonin.rapini/ModulesTek1/UnixSystemProgrammation/PSU_2016_tetris/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Sat Mar 11 00:00:17 2017 Antonin Rapini
** Last update Sat Mar 18 14:13:37 2017 Antonin Rapini
*/

#include "my_game.h"
#include "utils.h"

int		my_setlevel(char *arg, t_game *game)
{
  int		level;
  static int	set = 0;

  if (set)
    return (1);
  set = 1;
  level = 0;
  level = my_getnbr(arg);
  if (level > 0)
    {
      game->startlevel = level;
      return (0);
    }
  else
    return (1);
}

int		my_setmapsize(char *arg, t_game *game)
{
  int		rows;
  int		cols;
  static int	set = 0;

  if (set)
    return (1);
  set = 1;
  rows = my_getnbr(arg);
  if (rows > 0)
    {
      arg += my_nbrlen(rows);
      if (*arg == ',')
	{
	  arg++;
	  cols = my_getnbr(arg);
	  if (cols > 0)
	    {
	      game->mapsize.x = rows;
	      game->mapsize.y = cols;
	      return (0);
	    }
	}
    }
  return (1);
}
