/*
** my_putchar.c for my_putchar in /home/pierre.lellu/CPool_Day07/lib/my
** 
** Made by pierre lellu
** Login   <pierre.lellu@epitech.net>
** 
** Started on  Tue Oct 11 09:53:31 2016 pierre lellu
** Last update Fri Nov 18 12:32:10 2016 Pierre
*/

#include <unistd.h>

int	my_putchar(char c)
{
  write(1, &c, 1);
  return (1);
}
