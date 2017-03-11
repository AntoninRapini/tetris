/*
** my_wordtablen.c for tetris in /home/antonin.rapini/ModulesTek1/UnixSystemProgrammation/PSU_2016_bstetris/utils
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Wed Feb 22 16:34:53 2017 Antonin Rapini
** Last update Wed Feb 22 16:35:32 2017 Antonin Rapini
*/

int	my_wordtablen(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    i++;
  return (i);
}
