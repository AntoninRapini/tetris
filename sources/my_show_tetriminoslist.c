/*
** check_tetrimino.c for check_tetrimino in /home/antonin.rapini/ModulesTek1/UnixSystemProgrammation/PSU_2016_bstetris
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Wed Feb 22 14:38:43 2017 Antonin Rapini
** Last update Sat Mar 11 18:57:23 2017 Antonin Rapini
*/

#include <stdlib.h>
#include "utils.h"
#include "my_tetriminos.h"

void my_show_tetriminos(t_tetriminos *tetrimino)
{
  my_miniprintf("Tetriminos : Name %s : ", tetrimino->name);
  my_miniprintf("Size %i*%i : Color %i :\n",
		tetrimino->width, tetrimino->height, tetrimino->color);
  my_show_wordtab(tetrimino->shape);
}

void my_show_tetriminoslist(t_tlist *tlist)
{
  while (tlist != NULL)
    {
      my_show_tetriminos(tlist->tetriminos);
      tlist = tlist->next;
    }
}
