/*
** my_archive.c for  in /home/yannick.suc/Corewar/part1/step1
** 
** Made by suc yannick
** Login   <yannick.suc@epitech.net>
** 
** Started on  Tue Feb 28 10:16:33 2017 suc yannick
** Last update Sat Mar  4 12:17:21 2017 suc yannick
*/

#include "my_archive.h"

void	print_file(FILE *file, FILE *my_archive, char *name)
{
  struct stat	fileStat;
  char		*buff;

  fprintf(my_archive, "f:%s\n", name);
  stat(name, &fileStat);
  buff = malloc(sizeof(char) * (fileStat.st_size + 1));
  if (buff == NULL)
    {
      printf("Error with malloc\n");
      exit (84);
    }
  memset(buff, 0, fileStat.st_size + 1);
  if (fread(buff, fileStat.st_size, 1, file) == 0)
    {
      printf("Error with read\n");
      exit (84);
    }
  if (buff[0] != 0)
    fprintf(my_archive, "%s\n", buff);
  fprintf(my_archive, "~\n");
  free(buff);
}

void		print_directory(DIR *dir, FILE *my_archive, char *path)
{
  struct dirent	*fileOrDir;
  char		*newPath;

  if (path[(int) strlen(path) - 1] != '/')
    path = my_strcat(path, "/");
  fprintf(my_archive, "d:%s\n", path);
  while ((fileOrDir = readdir(dir)) != NULL)
    {
      if (*fileOrDir->d_name != '.')
	{
	  newPath = my_strcat(path, fileOrDir->d_name);
	  if (fileOrDir->d_type == DT_DIR)
	    print_directory(opendir(newPath), my_archive, my_strcat(newPath, "/"));
	  else if (fileOrDir->d_type == DT_REG)
	    print_file(fopen(newPath, "r"), my_archive, newPath);
	  else
	    {
	      printf("%s : Not a file or a Directory\n", newPath);
	      exit (84);
	    }
	}
    }
  fprintf(my_archive, "<\n");
}

void	fill_archive(FILE *my_archive, char **list)
{
  DIR	*dir;
  FILE	*file;

  while (*list != NULL)
    {
      if ((dir = opendir(*list)) != NULL)
	print_directory(dir, my_archive, *list);
      else if ((file = fopen(*list, "r")) == 0)
	print_file(file, my_archive, *list);
      else
	{
	  printf("%s : Invalid file or Directory\n", *list);
	  exit(84);
	}
      list++;
    }
}

int	main(int ac, char **av)
{
  FILE	*my_archive;
  
  if (ac < 3 || av[1] == NULL || av[2] == NULL)
    {
      printf("Usage: ./my_archive [archive_name] [files ...]\n");
      return (84);
    }
  if ((my_archive = fopen(av[1], "w+")) == NULL)
    {
      printf("Can't create an archive file\n");
      return (84);
    }
  fill_archive(my_archive, av + 2);
  fclose(my_archive);
  return (0);
}
