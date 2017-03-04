/*
** open.c for open in /home/pierre/rush1/myarchive
** 
** Made by Pierre
** Login   <pierre.lellu@epitech.eu@epitech.net>
** 
** Started on  Fri Mar  3 20:43:56 2017 Pierre
** Last update Fri Mar  3 20:46:49 2017 Pierre
*/

#include "include/my.h"

int     open_file(char *filepath)
{
  int   checkfile;

  checkfile = open(filepath, O_RDONLY);
  if (checkfile == -1)
    return (-1);
  else
    return (checkfile);
}
