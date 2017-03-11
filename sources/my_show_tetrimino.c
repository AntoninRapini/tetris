/*
** check_tetrimino.c for check_tetrimino in /home/antonin.rapini/ModulesTek1/UnixSystemProgrammation/PSU_2016_bstetris
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Wed Feb 22 14:38:43 2017 Antonin Rapini
** Last update Mon Mar  6 14:46:59 2017 Antonin Rapini
*/

#include "utils.h"
#include "my_tetriminos.h"

void my_show_tetrimino(t_tetriminos *tetrimino)
{
  my_putstr("Tetriminos : Name ");
  my_putstr(tetrimino->name);
  my_putstr(" : Size ");
  my_put_nbr(tetrimino->width);
  my_putstr("*");
  my_put_nbr(tetrimino->height);
  my_putstr(" : Color ");
  my_put_nbr(tetrimino->color);
  my_putstr(" :\n");
  my_show_wordtab(tetrimino->shape);
}
