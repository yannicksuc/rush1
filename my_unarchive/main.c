/*
** main.c for  in /home/yannick.suc/rush/rush1/myunarchive
** 
** Made by suc yannick
** Login   <yannick.suc@epitech.net>
** 
** Started on  Fri Mar  3 20:36:52 2017 suc yannick
** Last update Sat Mar  4 00:16:36 2017 suc yannick
*/

#include "main.h"

void	parse_my_archive(int, char*);

void    create_file(char *path, char *name, int fd)
{
  FILE  *newFile;
  char  *tmp;

  
  if (path != NULL)
    name = my_strcat(path, name);
  newFile = fopen(name, "w+");
  if (newFile == NULL)
    {
      printf("%s : Error while creating the file\n", name);
      exit(84);
    }
  while (strcmp((tmp = get_next_line(fd)), "-") != 0 && tmp != NULL)
    fprintf(newFile, "%s\n", tmp);
  free(tmp);
  fclose(newFile);
}

void    create_dir(char *path, char *name, int fd)
{
  if (path != NULL)
    name = my_strcat(path, name);
  if (mkdir(name, 0777) == -1 && opendir(name) == NULL)
    {
      printf("%s : The directory already exist\n", name);
      exit (84);
    }
  parse_my_archive(fd, my_strcat(name, "/"));
}

void	parse_my_archive(int fd, char *path)
{
  char	*line;
  char	*tmp;
  
  line = get_next_line(fd);
  while (line != NULL && *line != '<')
    {
      tmp = strtok(line, ":");
      if (strcmp(tmp, "f") == 0)
	create_file(path, strtok(NULL, ":"), fd);
      else if (strcmp(tmp, "d") == 0)
	create_dir(path, strtok(NULL, ":"), fd);
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
    parse_my_archive(fd, NULL);
  else
    {
      printf("Can't read the archive\n");
      return (84);
    }
  close(fd);
  return (0);
}
