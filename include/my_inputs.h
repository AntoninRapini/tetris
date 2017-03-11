/*
** my_inputs.h for tetris in /home/antonin.rapini/ModulesTek1/UnixSystemProgrammation/PSU_2016_tetris/include
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Fri Mar  3 14:45:34 2017 Antonin Rapini
** Last update Fri Mar 10 19:22:23 2017 Antonin Rapini
*/


#ifndef MY_INPUTS_H_
# define MY_INPUTS_H_

#define INPUT_LEFT 0
#define INPUT_RIGHT 1
#define INPUT_TURN 2
#define INPUT_DROP 3
#define INPUT_QUIT 4
#define INPUT_PAUSE 5

typedef struct	s_input
{
  char		*arg;
  char		*longarg;
  char		*input;
}		t_input;

#endif /* !MY_INPUTS_H_ */
