/*
** my_play.c for tetris in /home/antonin.rapini/ModulesTek1/UnixSystemProgrammation/PSU_2016_tetris/sources/game
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Thu Mar 16 18:58:17 2017 Antonin Rapini
** Last update Fri Mar 17 13:15:03 2017 Antonin Rapini
*/

#include "my_game.h"
#include <fcntl.h>
#include "utils.h"
#include <stdlib.h>
#include <unistd.h>

int	my_play(t_game *game)
{
  int	flags;
  char	buffer[512];
  int	rd_size;

  flags = fcntl(0, F_GETFL, 0);
  fcntl(0, F_SETFL, flags | O_NONBLOCK);
  while (1)
    {
      rd_size = read(0, buffer, 511);
      if (rd_size >= 0)
	{
	  //	  buffer[rd_size] = '\0';
	  //printf("[%s]", buffer);
	}
    }
  if (game)
    return (0);
  return (84);
}
