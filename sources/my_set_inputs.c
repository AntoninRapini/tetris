/*
** my_set_inputs.c for tetris in /home/antonin.rapini/ModulesTek1/UnixSystemProgrammation/PSU_2016_tetris/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Fri Mar  3 16:35:16 2017 Antonin Rapini
** Last update Fri Mar 10 19:27:50 2017 Antonin Rapini
*/

#include <curses.h>
#include <stdlib.h>
#include "my_inputs.h"
#include "utils.h"

t_input		*my_set_inputs()
{
  t_input	*inputs;

  if ((inputs = malloc(sizeof(t_input *) * 7)) == NULL)
    return (NULL);
  inputs[INPUT_LEFT].arg = my_strdup("-kl");
  inputs[INPUT_LEFT].longarg = my_strdup("--key-left");
  inputs[INPUT_LEFT].input = tigetstr("kcub1");
  inputs[INPUT_RIGHT].arg = my_strdup("-kr");
  inputs[INPUT_RIGHT].longarg = my_strdup("--key-right");
  inputs[INPUT_RIGHT].input = tigetstr("kcuf1");
  inputs[INPUT_TURN].arg = my_strdup("-kt");
  inputs[INPUT_TURN].longarg = my_strdup("--key-turn");
  inputs[INPUT_TURN].input = my_strdup("(space)");
  inputs[INPUT_DROP].arg = my_strdup("-kd");
  inputs[INPUT_DROP].longarg = my_strdup("--key-drop");
  inputs[INPUT_DROP].input = my_strdup("(space)");
  inputs[INPUT_QUIT].arg = my_strdup("-kq");
  inputs[INPUT_QUIT].longarg = my_strdup("--key-quit");
  inputs[INPUT_QUIT].input = my_strdup("q");
  inputs[INPUT_PAUSE].arg = my_strdup("-kp");
  inputs[INPUT_PAUSE].longarg = my_strdup("--key-pause");
  inputs[INPUT_PAUSE].input = my_strdup(" ");
  inputs[6].arg = NULL;
  inputs[6].longarg = NULL;
  inputs[6].input = NULL;
  return (inputs);
}
