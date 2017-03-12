/*
** my_sort_list.c for CPool_Day11 in /home/antonin.rapini/CPool_Day11/task10
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Mon Oct 17 14:16:13 2016 Antonin Rapini
** Last update Sun Mar 12 21:08:51 2017 Antonin Rapini
*/

#include <stdlib.h>
#include "my_tetriminos.h"

int	cmp(char a, char b)
{
  int	new_a;
  int	new_b;

  new_a = a >= 'A' && a <= 'Z' ? a + 32 : a;
  new_b = b >= 'A' && b <= 'Z' ? b + 32 : b;
  if (new_a == new_b)
    return (1);
  if (new_a < new_b)
    return (0);
  return (-1);
}

int	my_namecmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  while (s1[i] && s2[i] && cmp(s1[i], s2[i]) == 1)
    i++;
  return (cmp(s1[i], s2[i]) < 0);
}

void		my_sort_list(t_tlist **begin)
{
  int		sorted;
  t_tetriminos	*holder;
  t_tlist	*first;

  first = (*begin);
  sorted = 0;
  while (sorted == 0)
    {
      sorted = 1;
      while ((*begin)->next != NULL)
	{
	  if (my_namecmp((*begin)->tetriminos->name,
			 (*begin)->next->tetriminos->name))
	    {
	      holder = (*begin)->next->tetriminos;
	      (*begin)->next->tetriminos = (*begin)->tetriminos;
	      (*begin)->tetriminos = holder;
	      sorted = 0;
	    }
	  (*begin) = (*begin)->next;
	}
      (*begin) = first;
    }
}
