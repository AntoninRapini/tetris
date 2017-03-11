/*
** my_free_tetriminos.c for tetris in /home/antonin.rapini/ModulesTek1/UnixSystemProgrammation/PSU_2016_tetris/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Fri Mar  3 15:37:04 2017 Antonin Rapini
** Last update Mon Mar  6 17:39:18 2017 Antonin Rapini
*/

#include <stdlib.h>
#include "my_tetriminos.h"

void	my_free_tetriminos(t_tetriminos *tetriminos)
{
  int	i;

  i = 0;
  if (tetriminos->name != NULL)
    free(tetriminos->name);
  if (tetriminos->shape != NULL)
    {
      while (i < tetriminos->height)
	{
	  free(tetriminos->shape[i]);
	  i++;
	}
      free(tetriminos->shape);
    }
}
