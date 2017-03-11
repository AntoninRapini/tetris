/*
** my_putchar.c for kek in /home/antonin.rapini/ModulesTek1/UnixSystemProgrammation/PSU_2016_bstetris/utils
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Wed Feb 22 16:40:14 2017 Antonin Rapini
** Last update Wed Feb 22 16:40:32 2017 Antonin Rapini
*/

#include <unistd.h>

void my_putchar(char c)
{
  write(1, &c, 1);
}
