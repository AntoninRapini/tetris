/*
** my_get_tetriminos.c for tetris in /home/antonin.rapini/ModulesTek1/UnixSystemProgrammation/PSU_2016_tetris/sources/init
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Sun Mar 12 20:45:32 2017 Antonin Rapini
** Last update Sun Mar 12 21:41:20 2017 Antonin Rapini
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "utils.h"
#include "sources.h"
#include "get_next_line.h"
#include "my_tetriminos.h"

#include <stdio.h>
int	my_get_tetriminos_infos(char *buffer, t_tetriminos *ts)
{
  char	**infos;

  if (buffer == NULL)
    return (1);
  if ((infos = my_str_to_wordtab(buffer)) == NULL || my_wordtablen(infos) != 3)
  {
    my_free_wordtab(infos);
    free(buffer);
    return (1);
  }
  ts->width = my_getnbr(infos[0]);
  ts->height = my_getnbr(infos[1]);
  ts->color = my_getnbr(infos[2]);
  my_free_wordtab(infos);
  return (0);
}

char	*my_get_tetriminos_name(char *filename)
{
  char	*name;
  int	i;

  i = 0;
  while (filename[i] && filename[i] != '.')
    i++;
  if (my_strcmp(filename + i, ".tetrimino") != 0)
    return (NULL);
  if ((name = malloc(sizeof(char) * (i + 1))) == NULL)
    return (NULL);
  name[i] = '\0';
  i = 0;
  while (filename[i++] != '.')
    name[i - 1] = filename[i - 1];
  return (name);
}

int	my_fill_tetriminos(int fd, t_tetriminos *ts)
{
  int	i;
  char	*buffer;

  i = 0;
  while ((buffer = get_next_line(fd)) != NULL)
    {
      if (i >= ts->height || my_strlen(buffer) > ts->width)
	{
	  free(buffer);
	  return (1);
	}
      ts->shape[i] = buffer;
      i++;
    }
  return (0);
}

t_tetriminos	*my_get_tetriminos(char *file, int fd)
{
  t_tetriminos	*ts;

  ts = NULL;
  if ((ts = my_init_tetriminos()) == NULL)
    return (ts);
  if ((ts->name = my_get_tetriminos_name(file)) == NULL)
    return (ts);
  if (my_get_tetriminos_infos(get_next_line(fd), ts))
    return (ts);
  if ((ts->shape = my_init_wordtab(ts->height)) == NULL)
    return (ts);
  if (my_fill_tetriminos(fd, ts))
    return (ts);
  return (ts);
}
