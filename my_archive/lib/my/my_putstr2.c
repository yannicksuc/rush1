/*
** my_putstr2.c for str in /home/pierre/delivery/PSU_2016_my_printf
** 
** Made by Pierre
** Login   <pierre.lellu@epitech.eu@epitech.net>
** 
** Started on  Fri Nov 18 19:52:17 2016 Pierre
** Last update Sun Nov 20 22:56:26 2016 Pierre
*/

void    my_putchar(char);

int     my_putstr2(char *str)
{
  int   i;

  i = 0;
  while (str && '\0' != str[i])
    {
      if (str[i] >= 32 && str[i] < 127)
	my_putchar(str[i]);
      else
	{
	  my_putchar('\\');
	  my_putchar(str[i] / 8 / 8 + '0');
	  my_putchar(str[i] / 8 % 8 + '0');
	  my_putchar(str[i] % 8 + '0');
	  
	  
	} 
      i++;
    }
  if (!str)
    my_putstr2("(null)");
  return (i);
}
