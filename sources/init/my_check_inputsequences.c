/*
** my_check_inputsequences.c for tetris in /home/antonin.rapini/ModulesTek1/UnixSystemProgrammation/PSU_2016_tetris/sources/init
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Thu Mar 16 18:41:02 2017 Antonin Rapini
** Last update Thu Mar 16 18:55:28 2017 Antonin Rapini
*/

#include "utils.h"
#include "my_inputs.h"

int	my_check_inputsequences(t_input *inputs)
{
  int	i;
  int	j;

  i = 0;
  while (inputs[i].arg)
    {
      j = 0;
      while (inputs[j].arg)
	{
	  if (i != j && my_strstr(inputs[j].input, inputs[i].input))
	    return (1);
	  j++;
	}
      i++;
    }
  return (0);
}
