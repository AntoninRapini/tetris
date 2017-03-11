/*
** my_print_help.c for tetris in /home/antonin.rapini/ModulesTek1/UnixSystemProgrammation/PSU_2016_tetris/sources
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Fri Mar 10 22:30:00 2017 Antonin Rapini
** Last update Fri Mar 10 22:40:37 2017 Antonin Rapini
*/

void my_print_help()
{
  my_putstr("Usage: ./tetris [options]\n");
  my_putstr("Options:\n");
  my_putstr("\t--help\t\t\tDisplay this help\n");
  my_putstr("\t-l --level={num}\tStart Tetris at level num (def: 1)\n");
  my_putstr("\t-kl --key-left={K}");
  my_putstr("\tMove the tetrimino LEFT using the K key (def: left arrow)\n");
  my_putstr("\t-kr --key-right={K}");
  my_putstr("\tMove the tetrimino RIGHT using the K key (def: right arrow)\n");
  my_putstr("\t-kt --key-turn={K}");
  my_putstr
    ("\tTURN the tetrimino clockwise 90d using the K key (def: top arrow)\n");
  my_putstr("\t-kd --key-quit={K}");
  my_putstr("\tDROP the tetrimino using the K key (def: down arrow)\n");
  my_putstr("\t-kq --key-quit={K}");
  my_putstr("\tQuit the game using the K key (def: 'q' key\n");
  my_putstr("\t-kp --key-pause={K}");
  my_putstr("\tPAUSE/RESTART the game using the K key (def: space bar\n");
  my_putstr("\t--map-size={row,col}");
  my_putstr("\tSet the numbers of rows and columns of the map (def: 20, 10)\n");
  my_putstr("\t-w --without-next\tHide next tetrimino (def: false)\n");
  my_putstr("\t-d --debug\t\t\tDebug mode (def: false)\n");
}
