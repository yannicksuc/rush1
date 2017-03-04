/*
** my_printf_2flags.c for 2flags in /home/pierre/delivery/PSU_2016_my_printf
** 
** Made by Pierre
** Login   <pierre.lellu@epitech.eu@epitech.net>
** 
** Started on  Fri Nov 18 12:53:41 2016 Pierre
** Last update Sat Nov 19 13:29:46 2016 Pierre
*/

#include <stdarg.h>
#include "my.h"

int	my_printf_u(va_list *ap)
{
  my_put_ubase(va_arg(*ap, unsigned int), 10, 'a');
}

int	my_printf_o(va_list *ap)
{
  my_put_ubase(va_arg(*ap, unsigned int), 8, 'a');
}

int	my_printf_x(va_list *ap)
{
  my_put_ubase(va_arg(*ap, unsigned int), 16, 'a');
}

int	my_printf_X(va_list *ap)
{
  my_put_ubase(va_arg(*ap, unsigned int), 16, 'A');
}
int     my_printf_S(va_list *ap)
{
  my_putstr2(va_arg(*ap, char*));
}
