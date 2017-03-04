/*
** my_unarchive.c for  in /home/yannick.suc/rush/rush1/myunarchive
** 
** Made by suc yannick
** Login   <yannick.suc@epitech.net>
** 
** Started on  Fri Mar  3 20:36:52 2017 suc yannick
** Last update Sat Mar  4 04:03:20 2017 suc yannick
*/

#include "my_unarchive.h"

void	parse_my_archive(int fd);

void    create_file(char *path, int fd)
{
  FILE  *newFile;
  char  *tmp;

  newFile = fopen(path, "w+");
  if (newFile == NULL)
    {
      printf("%s : Error while creating the file\n", path);
      exit(84);
    }
  while (strcmp((tmp = get_next_line(fd)), "~") != 0 && tmp != NULL)
    fprintf(newFile, "%s\n", tmp);
  free(tmp);
  fclose(newFile);
}

void    create_dir(char *path, int fd)
{
  if (mkdir(path, 0777) == -1 && opendir(path) == NULL)
    {
      printf("%s : Error while creating the directory\n", path);
      exit (84);
    }
  parse_my_archive(fd);
}

void	parse_my_archive(int fd)
{
  char	*line;
  char	*type;
  char	*name;
  
  line = get_next_line(fd);
  while (line != NULL && *line != '<')
    {
      type = strtok(line, ":");
      name = strtok(NULL, ":");
      if (*type == 'f')
	create_file(name, fd);
      else if (*type == 'd')
	create_dir(name, fd);
      line = get_next_line(fd);
    }
}

int	main(int ac, char **av)
{
  int	fd;

  fd = 0;
  if (ac != 2 || av[1] == NULL)
    {
      printf("Usage : ./my_unarchive [archive name]\n");
      return (84);
    }
  if ((fd = open(av[1], O_RDONLY)) > 0)
    parse_my_archive(fd);
  else
    {
      printf("Can't read the archive\n");
      return (84);
    }
  close(fd);
  return (0);
}
