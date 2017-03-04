/*
** my_put_nbr.c for my_put_nbr in /home/pierre.lellu/CPool_Day07/lib/my
** 
** Made by pierre lellu
** Login   <pierre.lellu@epitech.net>
** 
** Started on  Tue Oct 11 09:49:27 2016 pierre lellu
** Last update Sun Nov 20 19:44:56 2016 Pierre
*/

void	my_putchar(char);
void	my_putstr(char *);

void	my_put_nbr2(int compteur, int result)
{
  while (compteur != 0)
    {
      my_putchar(result / compteur + '0');
      result = result % compteur;
      compteur = compteur / 10;
    }
}

int	my_put_nbr(int	nb)
{
  int	compteur;
  int	result;

  compteur = 1;
  if (nb == -2147483648)
    my_putstr("-2147483648");
  else
    {
      if (nb < 0)
	{
	  my_putchar ('-');
	  nb = nb * (-1);
	}
      result = nb;
      while (nb / 10 != 0)
	{
	  nb = nb / 10;
	  compteur *= 10;
	}
      my_put_nbr2(compteur, result);
    }
}
