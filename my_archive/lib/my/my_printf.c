/*
** main.c for main in /home/pierre/delivery/PSU_2016_my_printf
** 
** Made by Pierre
** Login   <pierre.lellu@epitech.eu@epitech.net>
** 
** Started on  Mon Nov 14 09:49:32 2016 Pierre
** Last update Sun Nov 20 18:33:17 2016 Pierre
*/

#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include "my.h"
#include "global.h"

void		toto(char *s, int i, va_list *ap)
{
  int		k;
  int		nbr;
  
  k = 0;	  
  if (s[i] == '%' || s[i] == '\0')
    my_putchar('%');
  else
    {
      while (tab[k].c != s[i] && k < 11)
	k++;
      if (k < 11)
	nbr = tab[k].function(ap);
      else
	{
	  my_putchar('%');
	  my_putchar(s[i]);
	}
    }
}


void		my_printf(char *s, ...)
{
  va_list	ap;
  int		i;
  
  i = 0;
  va_start(ap, s);
  while (s[i] != '\0')
    {
      if (s[i] == '%')
	{
	  i++;
	  toto(s, i, &ap);
	}
      else
	my_putchar(s[i]);
      i++;
    }
  va_end(ap);
}
