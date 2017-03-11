/*
** my_strdup.c for my_strdup in /home/antonin.rapini/CPool_Day08/task01
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Wed Oct 12 18:40:56 2016 Antonin Rapini
** Last update Wed Mar  1 17:54:02 2017 Antonin Rapini
*/

#include <stdlib.h>
#include "utils.h"

char	*my_strdup(char *src)
{
  char	*dest;
  int	i;

  i = my_strlen(src);
  if ((dest = malloc(sizeof(char) * (i + 1))) == NULL)
    return (NULL);
  dest[i] = '\0';
  i = 0;
  while (src[i++])
    dest[i - 1] = src[i - 1];
  return (dest);
}
