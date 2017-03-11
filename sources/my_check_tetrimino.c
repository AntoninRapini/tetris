/*
** check_tetrimino.c for check_tetrimino in /home/antonin.rapini/ModulesTek1/UnixSystemProgrammation/PSU_2016_bstetris
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Wed Feb 22 14:38:43 2017 Antonin Rapini
** Last update Mon Mar  6 14:48:07 2017 Antonin Rapini
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "utils.h"
#include "get_next_line.h"
#include "my_tetriminos.h"

int	get_infos(char *buffer, t_tetriminos *tetrimino)
{
  char	**infos;

  infos = my_str_to_wordtab(buffer);
  if (my_wordtablen(infos) != 3)
    return (1);
  tetrimino->width = my_getnbr(infos[0]);
  tetrimino->height = my_getnbr(infos[1]);
  tetrimino->color = my_getnbr(infos[2]);
  return (tetrimino->width == 0 || tetrimino->height == 0 || tetrimino->color == 0);
}

char	*my_getname(char *filename)
{
  char	*name;
  int	i;
  int	j;

  j = 0;
  while (filename[i])
    i++;
  while (i > 0 && filename[i] != '/')
    i--;
  if (filename[i] == '/')
    i++;
  while (filename[i + j] && filename[i + j] != '.')
    j++;
  if (!filename[i + j])
    return (NULL);
  if (my_strcmp(filename + i + j, ".tetrimino") != 0)
    return (NULL);
  if ((name = malloc(sizeof(char) * j)) == NULL)
    return (NULL);
  j = 0;
  while (filename[i + j] != '.')
    {
      name[j] = filename[i + j];
      j++;
    }
  return (name);
}

t_tetriminos	*my_check_tetrimino(char *file)
{
  int		i;
  int		fd;
  t_tetriminos	*tetrimino;
  char		*buffer;

  i = 0;
  if ((tetrimino = malloc(sizeof(t_tetriminos))) == NULL)
    return (NULL);
  if ((fd = open(file, O_RDONLY)) == -1)
    return (NULL);
  if ((tetrimino->name = my_getname(file)) == NULL)
    return (NULL);
  if ((buffer = get_next_line(fd)) == NULL)
    return (NULL);
  get_infos(buffer, tetrimino);
  if ((tetrimino->shape = malloc(sizeof(char *) * tetrimino->height)) == NULL)
    return (NULL);
  while ((buffer = get_next_line(fd)) != NULL)
    {
      if (i > tetrimino->height || my_strlen(buffer) > tetrimino->width)
	{
	  tetrimino->valid = 0;
	  return (tetrimino);
	}
      tetrimino->shape[i] = buffer;
      i++;
    }
  tetrimino->valid = 1;
  return (tetrimino);
}
