/*
** my_print_help.c for tetris in /home/antonin.rapini/ModulesTek1/UnixSystemProgrammation/PSU_2016_tetris/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Fri Mar 10 22:30:00 2017 Antonin Rapini
** Last update Sun Mar 19 21:03:14 2017 Antonin Rapini
*/

#include "utils.h"

void my_print_firsterrorline(char *name)
{
  my_puterror("Usage : ");
  my_puterror(name);
  my_puterror(" [options]\n");
}

int my_print_error(char *name)
{
  my_print_firsterrorline(name);
  my_puterror("Options:\n");
  my_puterror("\t--help\t\t\tDisplay this help\n");
  my_puterror("\t-l --level={num}\tStart Tetris at level num (def: 1)\n");
  my_puterror("\t-kl --key-left={K}");
  my_puterror("\tMove the tetrimino LEFT using the K key (def: left arrow)\n");
  my_puterror("\t-kr --key-right={K}");
  my_puterror
    ("\tMove the tetrimino RIGHT using the K key (def: right arrow)\n");
  my_puterror("\t-kt --key-turn={K}");
  my_puterror
    ("\tTURN the tetrimino clockwise 90d using the K key (def: top arrow)\n");
  my_puterror("\t-kd --key-drop={K}");
  my_puterror("\tDROP the tetrimino using the K key (def: down arrow)\n");
  my_puterror("\t-kq --key-quit={K}");
  my_puterror("\tQUIT the game using the K key (def: 'q' key\n");
  my_puterror("\t-kp --key-pause={K}");
  my_puterror("\tPAUSE/RESTART the game using the K key (def: space bar)\n");
  my_puterror("\t--map-size={row,col}\t");
  my_puterror
    ("Set the numbers of rows and columns of the map (def: 20, 10)\n");
  my_puterror("\t-w --without-next\tHide next tetrimino (def: false)\n");
  my_puterror("\t-d --debug\t\tDebug mode (def: false)\n");
  return (84);
}
