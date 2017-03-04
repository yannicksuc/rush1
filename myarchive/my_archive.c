/*
** my_archive.c for  in /home/yannick.suc/Corewar/part1/step1
** 
** Made by suc yannick
** Login   <yannick.suc@epitech.net>
** 
** Started on  Tue Feb 28 10:16:33 2017 suc yannick
** Last update Sat Mar  4 02:13:04 2017 Pierre
*/

#include "include/my.h"

void	print_file(int fd, FILE *my_archive, char *name)
{
  struct stat	fileStat;
  char		*buff;

  printf("%d\n", fd);
  fprintf(my_archive, "f:%s\n", name);
  fstat(fd, &fileStat);
  buff = malloc(sizeof(char) * (fileStat.st_size + 1));
  if (buff == NULL)
    {
      printf("Error with malloc\n");
      exit (84);
    }
  memset(buff, fileStat.st_size + 1, 0);
  if (read(fd, buff, fileStat.st_size) < 0)
    {
      printf("Error with read\n");
      exit (84);
    }
  if (buff[0] != 0)
    {
      printf("%s\n", buff);
      fprintf(my_archive, "%s\n", buff);
    }
  fprintf(my_archive, "~\n");
}

void		print_directory(DIR *dir, FILE *my_archive, char *name, char *path)
{
  struct dirent	*fileOrDir;
  char		*newPath;

  fprintf(my_archive, "d:%s\n", name);
  while ((fileOrDir = readdir(dir)) != NULL)
    {
      if (*fileOrDir->d_name != '.')
	{
	  if (path == NULL)
	    newPath = my_strcat(my_strcat(name, "/"), fileOrDir->d_name);
	  else
	    newPath = my_strcat(my_strcat(path, "/"), fileOrDir->d_name);
	  if (fileOrDir->d_type == DT_DIR)
	    print_directory(opendir(newPath), my_archive, fileOrDir->d_name, newPath);
	  else if (fileOrDir->d_type == DT_REG)
	    print_file(open(newPath, O_RDONLY), my_archive, fileOrDir->d_name);
	  else
	    {
	      printf("%s : Not a file or a Directory\n", name);
	      exit (84);
	    }
	}
    }
  fprintf(my_archive, "<\n");
}

void	fill_archive(FILE *my_archive, char *path, char **list)
{
  DIR	*dir;
  int	file;

  while (*list != NULL)
    {
      if ((dir = opendir(*list)) != NULL)
	print_directory(dir, my_archive, *list, path);
      else if ((file = open(*list, O_RDONLY)) > 0)
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
  int	fd;
  FILE	*my_archive;
  
  if (ac == 1)
    {
      printf("Usage: ./my_archive [archive_name] [files ...]\n");
      return (84);
    }
  if ((my_archive = fopen(av[1],"w+")) == NULL)
    return (84);
  fill_archive(my_archive, NULL, av + 2);
  fclose(my_archive);
  return (0);
}
