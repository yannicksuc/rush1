/*
** my.h for my.h in /home/pierre/delivery/Projet/PSU/PSU_2016_tetris
** 
** Made by Pierre
** Login   <pierre.lellu@epitech.eu@epitech.net>
** 
** Started on  Thu Mar  2 15:07:48 2017 Pierre
** Last update Sat Mar  4 01:53:49 2017 Pierre
*/

#ifndef MY_H_
#define MY_H_
# define BUFFER_SIZE 64000

#include <unistd.h>
#include <string.h>
#include <ncurses.h>
#include <curses.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <dirent.h>

int	open_file(char *filepath);
char	*my_strcat(char *s1, char *s2);

#endif /* !MY_H_ */

