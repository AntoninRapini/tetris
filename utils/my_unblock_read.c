/*
** my_unblock_read.c for tetris in /home/antonin.rapini/ModulesTek1/UnixSystemProgrammation/PSU_2016_tetris/utils
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Fri Mar 17 23:51:45 2017 Antonin Rapini
** Last update Sat Mar 18 00:05:57 2017 Antonin Rapini
*/

#include <sys/ioctl.h>
#include <termios.h>
#include <unistd.h>

int			my_unblock_read(struct termios oldT)
{
  struct termios	newT;

  newT = oldT;
  newT.c_lflag &= ~ECHO;
  newT.c_lflag &= ~ICANON;
  ioctl(0, TCSETS, &newT);
  return (0);
}
