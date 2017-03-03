/*
** write_some_text.c for  in /home/yannick.suc/Corewar/part1/step1
** 
** Made by suc yannick
** Login   <yannick.suc@epitech.net>
** 
** Started on  Tue Feb 28 10:16:33 2017 suc yannick
** Last update Tue Feb 28 10:33:31 2017 suc yannick
*/

#include "write_a_number_as_int.h"

int	main()
{
  int	fd;
  int	num;

  num = 12345678;
  fd = open("number-as-int.yolo", O_CREAT | O_TRUNC | O_WRONLY, S_IRUSR | S_IWUSR);
  if (fd < 0)
    return (84);
  write(fd, &num, 4);
  close(fd);
  return (0);
}
