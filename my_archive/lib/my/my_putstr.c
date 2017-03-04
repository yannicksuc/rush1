/*
** toto.c for toto in /home/pierre.lellu/CPool_Day04
** 
** Made by pierre lellu
** Login   <pierre.lellu@epitech.net>
** 
** Started on  Thu Oct  6 11:47:06 2016 pierre lellu
** Last update Sun Nov 20 22:55:49 2016 Pierre
*/

void	my_putchar(char);

int	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str && '\0' != str[i])
    {
      my_putchar(str[i]);
      i++;
    }
  if (!str)
    my_putstr("(null)");
  return (i);
}
