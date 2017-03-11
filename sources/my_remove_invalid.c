/*
** my_remove_invalid.c for tetris in /home/antonin.rapini/ModulesTek1/UnixSystemProgrammation/PSU_2016_tetris/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Fri Mar  3 15:24:48 2017 Antonin Rapini
** Last update Fri Mar  3 15:48:37 2017 Antonin Rapini
*/

#include "my_tetriminos.h"
#include <stdlib.h>

void		my_remove_invalid(t_tlist **list)
{
  t_tlist	*curr;
  t_tlist	*nextholder;

  curr = *list;
  while ((*list) != NULL)
    {
      if (!(*list)->tetriminos->valid)
	{
	  if ((*list)->previous != NULL)
	    (*list)->previous->next = (*list)->next;
	  else
	    curr = (*list)->next;
	  nextholder = (*list)->next;
	  my_free_tetriminos((*list)->tetriminos);
	  free((*list)->tetriminos);
	  free((*list));
	  (list) = nextholder;
	}
      else
	(*list) = (*list)->next;
    }
  (*list) = curr;
}
