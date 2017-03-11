/*
** showenv.c for kek in /home/antonin.rapini/ModulesTek1/UnixSystemProgrammation/PSU_2016_tetris/tests
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Fri Mar 10 17:03:54 2017 Antonin Rapini
** Last update Fri Mar 10 17:05:44 2017 Antonin Rapini
*/

#include <stdio.h>

int main(int ac, char **av, char **env)
{
  int	i;

  i = 0;
  while (env[i])
    {
      printf("%s\n", env[i]);
      i++;
    }
}
