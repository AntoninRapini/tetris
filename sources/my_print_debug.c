/*
** my_print_debug.c for tetris in /home/antonin.rapini/ModulesTek1/UnixSystemProgrammation/PSU_2016_tetris/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Sat Mar 11 17:11:12 2017 Antonin Rapini
** Last update Sun Mar 12 21:29:42 2017 Antonin Rapini
*/

#include "utils.h"
#include "my_game.h"
#include "sources.h"
#include <stdlib.h>

void	my_print_input(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (str[i] == 27)
	my_putstr("^E");
      else if (str[i] == 32)
	my_putstr("(space)");
      else
	my_putchar(str[i]);
      i++;
    }
  my_putchar('\n');
}

void my_print_inputs(t_input *inputs)
{
  my_putstr("Key Left : ");
  my_print_input(inputs[INPUT_LEFT].input);
  my_putstr("Key Right : ");
  my_print_input(inputs[INPUT_RIGHT].input);
  my_putstr("Key Turn : ");
  my_print_input(inputs[INPUT_TURN].input);
  my_putstr("Key Drop : ");
  my_print_input(inputs[INPUT_DROP].input);
  my_putstr("Key Quit : ");
  my_print_input(inputs[INPUT_QUIT].input);
  my_putstr("Key Pause : ");
  my_print_input(inputs[INPUT_PAUSE].input);
}

void my_print_debug(t_game *game)
{
  my_putstr("*** DEBUG MODE ***\n");
  my_print_inputs(game->inputs);
  my_miniprintf("Next : %s", game->shownext ? "Yes\n" : "No\n");
  my_miniprintf("Level : %i\n", game->startlevel);
  my_miniprintf("Size : %i*%i\n", game->mapsize.x, game->mapsize.y);
  my_miniprintf("Tetriminos : %i\n", game->tetriminoscount);
  my_show_tetriminoslist(game->tetriminoslist);
}
