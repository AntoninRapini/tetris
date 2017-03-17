/*
** check_tetrimino.c for check_tetrimino in /home/antonin.rapini/ModulesTek1/UnixSystemProgrammation/PSU_2016_bstetris
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Wed Feb 22 14:38:43 2017 Antonin Rapini
** Last update Fri Mar 17 01:29:41 2017 Antonin Rapini
*/

#include <stdlib.h>
#include "utils.h"
#include "my_tetriminos.h"

void my_show_tetriminos(t_tetriminos *tetrimino)
{
  my_miniprintf("Tetriminos : Name %s : ", tetrimino->name);
  if (tetrimino->valid)
    {
      my_miniprintf("Size %i*%i : Color %i :\n",
		    tetrimino->width, tetrimino->height, tetrimino->color);
      my_show_wordtab(tetrimino->shape);
    }
  else
    my_putstr("Error\n");
}

void my_show_tetriminoslist(t_tlist *tlist)
{
  while (tlist != NULL)
    {
      my_show_tetriminos(tlist->tetriminos);
      tlist = tlist->next;
    }
}
