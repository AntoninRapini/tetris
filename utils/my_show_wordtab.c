/*
** my_showa_wordtab.c for my_show_wordtab in /home/antonin.rapini/CPool_Day08/task03
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Wed Oct 12 21:18:48 2016 Antonin Rapini
** Last update Wed Feb 22 16:41:13 2017 Antonin Rapini
*/

#include "utils.h"

void	my_show_wordtab(char **tab)
{
  int	index;

  index = 0;
  while (tab[index])
    {
      my_putstr(tab[index]);
      my_putchar('\n');
      index = index + 1;
    }
}
