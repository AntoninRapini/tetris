/*
** my_create_tetriminoses.c for tetris in /home/antonin.rapini/ModulesTek1/UnixSystemProgrammation/PSU_2016_tetris/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Thu Mar  2 18:59:05 2017 Antonin Rapini
** Last update Thu Mar 16 17:55:37 2017 Antonin Rapini
*/

#include <dirent.h>
#include <sys/types.h>
#include <stdlib.h>
#include "my_tetriminos.h"
#include "sources.h"
#include "utils.h"
#include <fcntl.h>
#include "unistd.h"
#include "get_next_line.h"

int		my_create_listelement
(t_tlist **tlist, struct dirent *entry, t_game *game)
{
  t_tlist	*element;
  char		*fullpath;
  int		fd;
  char		*buffer;

  if ((fullpath = my_nstrcat(2, "tetriminos/", entry->d_name)) == NULL)
    return (0);
  if ((element = malloc(sizeof(t_tlist *))) == NULL)
    return (0);
  if ((fd = open(fullpath, O_RDONLY)) == -1)
    return (0);
  element->tetriminos = my_get_tetriminos(entry->d_name, fd);
  while ((buffer = get_next_line(fd)) != NULL)
    free(buffer);
  close(fd);
  if (my_check_tetriminos(element->tetriminos))
    return (0);
  game->tetriminoscount++;
  element->next = *tlist;
  *tlist = element;
  return (0);
}

void my_set_previous(t_tlist *tlist)
{
  tlist->previous = NULL;
  while (tlist->next != NULL)
    {
      tlist->next->previous = tlist;
      tlist = tlist->next;
    }
}

t_tlist		*my_create_tetriminoslist(t_game *game)
{
  t_tlist	*tlist;
  DIR		*dir;
  struct dirent *entry;

  tlist = NULL;
  if ((dir = opendir("tetriminos")) == NULL)
    return (NULL);
  while ((entry = readdir(dir)) != NULL)
    {
      if (entry->d_name[0] != '.')
	{
	  if (my_create_listelement(&tlist, entry, game))
	    return (NULL);
	}
    }
  if (tlist != NULL)
    {
      my_set_previous(tlist);
      my_sort_list(&tlist);
    }
  closedir(dir);
  return (tlist);
}
