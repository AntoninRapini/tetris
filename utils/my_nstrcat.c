/*
** my_strcat.c for my_strcat in /home/antonin.rapini/CPool_Day07
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Wed Oct 12 11:25:45 2016 Antonin Rapini
** Last update Wed Mar  1 17:50:31 2017 Antonin Rapini
*/

#include <stdarg.h>
#include <stdlib.h>
#include "utils.h"

char	*my_fill_string(char **arr, int size)
{
  char	*final;
  int	i;
  int	j;

  final = malloc(sizeof(char) * (size + 1));
  final[size] = '\0';
  i = 0;
  j = 0;
  while (j < size)
    {
      while (*arr[i])
	{
	  final[j] = *arr[i];
	  j++;
	  arr[i]++;
	}
      i++;
    }
  return (final);
}

char		*my_nstrcat(int nbr, ...)
{
  va_list	list;
  int		i;
  int		size;
  char		**arr;

  size = 0;
  i = 0;
  if ((arr = malloc(sizeof(char *) * nbr)) == NULL)
    return (NULL);
  va_start(list, nbr);
  while (i++ < nbr)
    {
      arr[i - 1] = va_arg(list, char *);
      size += my_strlen(arr[i - 1]);
    }
  return (my_fill_string(arr, size));
}
