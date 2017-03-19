/*
** my_putstr.c for my_putstr in /home/antonin.rapini/CPool_Day04
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Thu Oct  6 12:21:08 2016 Antonin Rapini
** Last update Sun Mar 19 20:55:11 2017 Antonin Rapini
*/

#include <unistd.h>

void	my_puterror(char *str)
{
  int	index;

  index = 0;
  while (str[index++]);
  write(2, str, index - 1);
}
