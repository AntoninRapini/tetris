/*
** my_strstr.c for my_strstr in /home/antonin.rapini/CPool_Day06
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Mon Oct 10 16:52:14 2016 Antonin Rapini
** Last update Fri Mar 17 14:42:53 2017 Antonin Rapini
*/

int	my_strstr(char *str, char *to_find)
{
  int	f_index;
  int	index;

  index = 0;
  f_index = 0;
  while (*str)
    {
      while (str[index++] == to_find[f_index++])
	{
	  if (to_find[f_index] == '\0')
	      return (1);
	  else if (str[index] == '\0')
	    return (0);
	}
      index = 0;
      f_index = 0;
      str++;
    }
  return (0);
}
