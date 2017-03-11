/*
** my_getterm.c for tetris in /home/antonin.rapini/ModulesTek1/UnixSystemProgrammation/PSU_2016_tetris/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Fri Mar 10 16:49:50 2017 Antonin Rapini
** Last update Fri Mar 10 17:36:33 2017 Antonin Rapini
*/

#include <stdlib.h>
#include "utils.h"
#include <stdio.h>

char	*my_getterm(char **env)
{
  int	i;
  char	*term;

  term = NULL;
  i = 0;
  while (env[i] && my_strncmp(env[i], "TERM", 4) != 0)
    i++;
  if (env[i] && my_strlen(env[i]) > 5)
    term = my_strdup(env[i] + 5);
  return (term);
}
