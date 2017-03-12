/*
** my_free_tetriminos.c for tetris in /home/antonin.rapini/ModulesTek1/UnixSystemProgrammation/PSU_2016_tetris/utils
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Sun Mar 12 19:55:40 2017 Antonin Rapini
** Last update Sun Mar 12 21:42:22 2017 Antonin Rapini
*/

#include <stdlib.h>
#include "my_tetriminos.h"
#include "utils.h"
#include <stdio.h>

void my_free_tetriminos(t_tetriminos *ts)
{
  if (ts != NULL)
    {
      if (ts->name != NULL)
	free(ts->name);
      my_free_wordtab(ts->shape);
      free(ts);
    }
}

int	my_check_tetriminos(t_tetriminos *ts)
{
  int	i;

  i = 0;
  if (ts == NULL || ts->name == NULL || ts->shape == NULL
      || ts->width == 0 || ts->height == 0 || ts->color == 0
      || my_wordtablen(ts->shape) < ts->height)
    {
      my_free_tetriminos(ts);
      return (1);
    }
  while (ts->shape[i])
    {
      if (my_strlen(ts->shape[i]) == ts->width)
	return (0);
      i++;
    }
  my_free_tetriminos(ts);
  return (1);
}

t_tetriminos	*my_init_tetriminos()
{
  t_tetriminos	*ts;
  if ((ts = malloc(sizeof(t_tetriminos))) == NULL)
    return (NULL);
  ts->name = NULL;
  ts->shape = NULL;
  ts->valid = 1;
  ts->height = 0;
  ts->width = 0;
  ts->color = 0;
  return (ts);
}