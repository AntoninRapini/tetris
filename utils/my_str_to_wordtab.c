/*
** my_str_to_wordtab.c for my_str_to_wordtab in /home/antonin.rapini/CPool_Day08/task04
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Wed Oct 12 22:17:24 2016 Antonin Rapini
** Last update Wed Feb 22 16:47:36 2017 Antonin Rapini
*/

#include <stdlib.h>
#include "utils.h"

int	char_is_alphanum(char c)
{
  int	return_value;

  return_value = 0;
  return_value = (c >= 65 && c <= 90) ? 1 : return_value;
  return_value = (c >= 48 && c <= 57) ? 1 : return_value;
  return_value = (c >= 97 && c <= 122) ? 1 : return_value;
  return (return_value);
}

int	my_word_is_alphanum(char *str)
{
  int	index;

  index = 0;
  while (char_is_alphanum(str[index]) != 0)
    {
      index = index + 1;
    }
  return (index);
}

int	get_word_count(char *str)
{
  int	index;
  int	size;

  size = 0;
  index = 0;
  while (str[index])
    {
      if (my_word_is_alphanum(str + index) > 0)
	{
	  index = index + my_word_is_alphanum(str + index);
	  size = size + 1;
	}
      else
	{
	  index = index + 1;
	}
    }
  return (size);
}

void	populate_arr(char *str, char **arr)
{
  int	curr_word_size;
  int	arr_index;

  curr_word_size = 0;
  arr_index = 0;
  while (*str)
    {
      if (char_is_alphanum(*str) != 0)
	{
	  curr_word_size = 0;
	  while (char_is_alphanum(*str) != 0)
	    {
	      curr_word_size = curr_word_size + 1;
	      str = str + 1;
	    }
	  arr[arr_index] = my_strndup(str - curr_word_size, curr_word_size);
	  arr_index = arr_index + 1;
	  str = str - 1;
	}
      str = str + 1;
    }
  arr[arr_index] = malloc(sizeof(char));
  arr[arr_index] = 0;
}

char	**my_str_to_wordtab(char *str)
{
  char	**arr;
  arr = malloc((get_word_count(str) + 1) * sizeof(char *));
  populate_arr(str, arr);
  return (arr);
}
