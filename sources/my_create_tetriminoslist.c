/*
** my_create_tetriminoses.c for tetris in /home/antonin.rapini/ModulesTek1/UnixSystemProgrammation/PSU_2016_tetris/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Thu Mar  2 18:59:05 2017 Antonin Rapini
** Last update Sat Mar 11 16:46:01 2017 Antonin Rapini
*/

#include <dirent.h>
#include <sys/types.h>
#include <stdlib.h>
#include "my_tetriminos.h"
#include "sources.h"
#include "utils.h"

int		my_create_listelement
(t_tlist **tlist, struct dirent *entry, t_game *game)
{
  t_tlist	*element;

  if ((element = malloc(sizeof(t_tlist *))) == NULL)
    return (1);
  if ((element->tetriminos = my_check_tetrimino(entry->d_name)) == NULL)
    return (1);
  if (!element->tetriminos->valid && !game->debug)
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
    if (my_create_listelement(&tlist, entry, game))
      return (NULL);
  my_set_previous(tlist);
  my_sort_list(&tlist);
  closedir(dir);
  return (tlist);
}
