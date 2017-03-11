/*
** utils.h for tetris in /home/antonin.rapini/ModulesTek1/UnixSystemProgrammation/PSU_2016_bstetris/include
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Wed Feb 22 16:35:58 2017 Antonin Rapini
** Last update Sat Mar 11 18:41:30 2017 Antonin Rapini
*/

#ifndef UTILS_H_
# define UTILS_H_

#include "my_tetriminos.h"
#include "my_game.h"

void my_putchar(char);
int my_getnbr(char *);
void my_putstr(char *);
void my_show_wordtab(char **);
int my_wordtablen(char **);
void my_put_nbr(int);
int my_strcmp(char *, char *);
char **my_str_to_wordtab(char *);
char *my_strndup(char *, int);
char *my_strncpy(char *, char *, int);
int my_strlen(char *);
void my_sort_list(t_tlist **);
char *my_strdup(char *);
char *my_getterm(char **);
int my_strncmp(char *, char *, int);
int my_setlevel(char *, t_game *);
int my_setmapsize(char *, t_game *);
int my_nbrlen(int);
void my_print_help();
int my_miniprintf(char *, ...);

#endif /* !UTILS_H_ */
