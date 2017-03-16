/*
** my_tetrimino.h for tetris in /home/antonin.rapini/ModulesTek1/UnixSystemProgrammation/PSU_2016_bstetris/include
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Wed Feb 22 16:43:02 2017 Antonin Rapini
** Last update Thu Mar 16 17:52:40 2017 Antonin Rapini
*/

#ifndef MY_TETRIMINOS_H_
# define MY_TETRIMINOS_H_

typedef struct	s_tetriminos
{
  int		valid;
  char		*name;
  int		height;
  int		width;
  int		color;
  char		**shape;
}		t_tetriminos;

typedef struct			s_tlist
{
  t_tetriminos			*tetriminos;
  struct s_tlist		*next;
  struct s_tlist		*previous;
}				t_tlist;

#endif /* !MY_TETRIMINOS_H_ */
