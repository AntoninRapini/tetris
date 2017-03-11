/*
** my_strdup_size.c for my_strdup_size in /home/antonin.rapini/MyPrograms
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Thu Oct 13 15:26:27 2016 Antonin Rapini
** Last update Wed Feb 22 16:50:08 2017 Antonin Rapini
*/

#include <stdlib.h>
#include "utils.h"

char	*my_strndup(char *src, int size)
{
  char	*dest;

  dest = malloc(size * sizeof(char));
  return (my_strncpy(dest, src, size));
}
