/*
** my_put_nbr.c for my_put_nbr in /home/pierre.lellu/CPool_Day07/lib/my
** 
** Made by pierre lellu
** Login   <pierre.lellu@epitech.net>
** 
** Started on  Tue Oct 11 09:49:27 2016 pierre lellu
** Last update Sun Nov 20 22:54:22 2016 Pierre
*/

void	my_putchar(char);

int	my_put_ubase(long long nb, int	base, char str)
{
  if (nb < base)
    {
      if (nb >= 10)
	{
	  my_putchar(nb + str - 10);
	}
      else
	my_putchar(nb + '0');
    }
  else
    {
      my_put_ubase(nb / base, base, str);
      my_put_ubase(nb % base, base, str);
    }
}
