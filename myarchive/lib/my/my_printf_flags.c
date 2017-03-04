/*
** my_printf_flags.c for  in /home/pierre/delivery/PSU_2016_my_printf
** 
** Made by Pierre
** Login   <pierre.lellu@epitech.eu@epitech.net>
** 
** Started on  Fri Nov 18 12:34:58 2016 Pierre
** Last update Fri Nov 18 15:34:45 2016 Pierre
*/

#include <stdarg.h>
#include "my.h"

int	my_printf_c(va_list *ap)
{
  my_putchar(((char) va_arg(*ap, int)));
}

int	my_printf_s(va_list *ap)
{
  my_putstr(va_arg(*ap, char*));
}

int	my_printf_i(va_list *ap)
{
  my_put_nbr(va_arg(*ap, int));
}

int	my_printf_d(va_list *ap)
{
  my_put_nbr(va_arg(*ap, int));
}

int	my_printf_b(va_list *ap)
{
  my_put_ubase(va_arg(*ap, unsigned int), 2, 'a');
}
