/*
** my_printf_3flags.c for flags_3 in /home/pierre/delivery/PSU_2016_my_printf
** 
** Made by Pierre
** Login   <pierre.lellu@epitech.eu@epitech.net>
** 
** Started on  Sun Nov 20 18:14:11 2016 Pierre
** Last update Sun Nov 20 19:33:19 2016 Pierre
*/

#include <stdarg.h>
#include "my.h"

int	my_printf_p(va_list *ap)
{
  my_put_ubase(va_arg(*ap, unsigned long long), 16, 'a');
}
