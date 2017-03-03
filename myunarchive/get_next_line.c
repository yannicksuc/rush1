/*
** get_next_line.c for  in /home/yannick.suc/CPE/CPE_2016_getnextline
** 
** Made by suc yannick
** Login   <yannick.suc@epitech.net>
** 
** Started on  Mon Jan  9 16:55:28 2017 suc yannick
** Last update Fri Mar  3 22:50:55 2017 suc yannick
*/

#include "get_next_line.h"
#define READ_SIZE 10

void	my_spe_memset(char *str, char c, int l, int max)
{
  while (--l >= max)
    str[l] = c;
}

char    *my_spe_strcat(char *s1, char *s2, int *len)
{
  char  *r;
  int   i;
  int   j;

  i = -1;
  j = -1;
  r = malloc(sizeof(char) * (int) (strlen(s1) + READ_SIZE + 1));
  if (r == NULL)
    return (NULL);
  while (s1[++i] != 0)
    r[i] = s1[i];
  while (++j > -42 && j < *len && s2[j] != '\n')
    r[i + j] = s2[j];
  if (s2[j] == '\n')
    {
      s2 = s2 + j;
      *len = j;
    }
  else
    *len = READ_SIZE;
  r[i + j] = 0;
  return (r);
}

char	*copy_buff_to_result(int *len, char *buff, char *result, int fd)
{
  int	r;

  r = 1;
  while (*len == READ_SIZE && (r = read(fd, buff, READ_SIZE)) > 0)
    {
      if (r != READ_SIZE)
	my_spe_memset(buff, '\0', r, READ_SIZE);
      result = my_spe_strcat(result, buff, len);
    }
  return (result);
}

char		*get_next_line(int fd)
{
  static char	buff[READ_SIZE];
  static int	len = READ_SIZE;
  char		*result;
  int		i;

  i = 0;
  result = malloc(sizeof(char) * 1);
  if (len < READ_SIZE)
    {
      if ((result = malloc(sizeof(char) * (READ_SIZE - len))) == NULL)
	return (NULL);
      while (len + i + 1 < READ_SIZE && buff[len + i + 1] != '\n')
	{
	  result[i] = buff[len + i + 1];
	  i++;
	}
      len = len + i + 1;
    }
  if (result == NULL)
    return (NULL);
  result[i] = '\0';
  result = copy_buff_to_result(&len, buff, result, fd);
  if (result[0] == '\0' && buff[len] != '\n')
    return (NULL);
  return (result);
}
