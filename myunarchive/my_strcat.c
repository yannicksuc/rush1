/*
** my_strcat.c for  in /home/yannick.suc/rush/rush1/myunarchive
** 
** Made by suc yannick
** Login   <yannick.suc@epitech.net>
** 
** Started on  Fri Mar  3 23:17:20 2017 suc yannick
** Last update Fri Mar  3 23:32:03 2017 suc yannick
*/

#include "my_strcat.h"

char	*my_strcat(char *s1, char *s2)
{
  int	i;
  int	j;
  char	*new;

  new = malloc(sizeof(char) * (int) (strlen(s1) + strlen(s2) + 1));
  i = -1;
  while (s1[++i] != 0)
    {
      new[i] = s1[i];
    }
  j = -1;
  while (s2[++j] != 0)
    {
      new[i + j] = s2[j];
    }
  new[i + j] = 0;
  return (new);
}
