/*
** my_str_to_wordtab.c for my_str_to_wordtab in /home/antonin.rapini/CPool_Day08/task04
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Wed Oct 12 22:17:24 2016 Antonin Rapini
** Last update Sun Mar 19 16:43:24 2017 Antonin Rapini
*/

#include <stdlib.h>
#include "utils.h"

int char_is_alphanum(char c)
{
  return ((c >= 'A' && c <= 'Z')
	  || (c >= 'a' && c <= 'z')
	  || (c >= '0' && c <= '9'));
}

int	get_word_count(char *str)
{
  int	i;
  int	size;

  size = 0;
  i = 0;
  while (str[i])
    {
      if (char_is_alphanum(str[i]))
	{
	  size++;
	  while (char_is_alphanum(str[i]))
	    i++;
	}
      else
	i++;
    }
  return (size);
}

void	populate_arr(char *str, char **arr)
{
  int	i;
  int	arr_index;

  i = 0;
  arr_index = 0;
  while (*str)
    {
      if (char_is_alphanum(*str))
	{
	  i = 0;
	  while (char_is_alphanum(str[i]))
	    i++;
	  arr[arr_index] = my_strndup(str, i);
	  arr_index++;
	  str += i;
	}
      else
	str++;
    }
  arr[arr_index] = NULL;
}

char	**my_str_to_wordtab(char *str)
{
  char	**arr;

  arr = malloc((get_word_count(str) + 1) * sizeof(char *));
  populate_arr(str, arr);
  return (arr);
}
