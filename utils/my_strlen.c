/*
** my_strlen.c for my_strlen in /home/antonin.rapini/CPool_Day04
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Thu Oct  6 14:02:36 2016 Antonin Rapini
** Last update Fri Dec  2 21:52:52 2016 Antonin Rapini
*/

int	my_strlen(char *str)
{
  int	counter;

  counter = 0;
  while (str[counter++]);
  return (counter - 1);
}
