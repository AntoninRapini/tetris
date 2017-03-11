/*
** my_strncpy.c for my_strncpy in /home/antonin.rapini/CPool_Day06
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Mon Oct 10 08:56:51 2016 Antonin Rapini
** Last update Mon Oct 10 09:33:52 2016 Antonin Rapini
*/

char	*my_strncpy(char *dest, char *src, int n)
{
  int	index;

  index = 0;
  while (index < n && src[index] != '\0')
    {
      dest[index] = src[index];
      index = index + 1;
    }
  while (index < n)
    {
      dest[index] = '\0';
      index = index + 1;
    }
  return (dest);
}
