/*
** read_options.c for  in /home/yannick.suc/rush/rush1/task02
** 
** Made by suc yannick
** Login   <yannick.suc@epitech.net>
** 
** Started on  Sat Mar  4 14:23:09 2017 suc yannick
** Last update Sat Mar  4 14:33:03 2017 suc yannick
*/


//Ici tu initialises toutes les valeurs dans la structure à zero
t_opts		set_options()
{
  t_opts	opts;

  return (opts);
}

/*Ici tu lis le str qui contient les options.
Pour chaque options rencontré met l'option dans la structure correspondant à 1
(Exemple : xcvf    --> Ici la structure Opts contiendra : int x = 1, int c = 1 int v = 1, int f = 1, int t = 0, int p = 0)
Cas d'erreurs à gerer :
	- Options qui apparait deux fois (Exemple : xcvfc    -->   Ici il y a deux fois l'option c)
	- Options qui n'existe pas (Exemple : cfxj     --> Ici l'option 'j' n'existe pas)
Pour les erreurs, fais un printf qui explique l'erreur puis un exit 84
*/

t_opts		read_options(char *str)
{
  t_opts	opts;
  
  opts = set_options();

  return (opts);
}
