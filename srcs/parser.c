/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malavent <malavent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 13:25:38 by achoquel          #+#    #+#             */
/*   Updated: 2019/06/13 15:22:58 by achoquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/wolf3d.h"

void	joiner(char **map, char **line)
{
	char	*tmp;

	tmp = *map;
	*map = ft_strjoin(tmp, *line);
	free(tmp);
	tmp = *map;
	*map = ft_strjoin(tmp, "\n");
	ft_strdel(&tmp);
}

char **set_walls(char **map)
{
	char **new;
	int height;
	int width;
	int i;
	int j;

	height = 0;
	i = -1;
	width = ft_strlen(map[0]) + 2;
	while (map[height])
		height++;
	height += 2;
	printf("%d\n", height);
	new = (char **)malloc(sizeof(char *) * height + 1);
	while (++i < height)
		new[i] = ft_strnew(width);
	ft_memset(new[0], '1', width);
	new[0][width] = '\0';
	i = -1;
	while (++i < height - 2)
	{
		j = -1;
		new[i + 1][j + 1] = '1';
		while (++j < width - 2)
			new[i + 1][j + 1] = map[i][j];
		new[i + 1][j + 1] = '1';
		new[i + 1][j + 2] = '\0';
	}
	ft_memset(new[i + 1], '1', width);
	new[height] = 0;
	return (new);
}

int wolf3d_parser(t_env *env, int fd)
{
  char	*line;
  char	*strmap;
  int   y;

  if (!(strmap = ft_strnew(0)))
    return (-1);
  ft_putendl("ICI6");
  
  while (get_next_line(fd, &line))
  {
	ft_putendl("ICI7");
    joiner(&strmap, &line);
    free(line);
  }
  ft_putendl("ICI8");
  env->map = ft_strsplit(strmap, '\n');
  free(strmap);
  env->map = set_walls(env->map);
  ft_putendl("ICI9");
  if (wolf3d_mapchecker(env) == 1)
  {
    y = 0;
    while(env->map[y])
    {
      free(env->map[y]);
      ++y;
    }
    free(env->map);
    return (-1);
  }
  return (0);
}
/*
int   main(int argc, char const *argv[])
{
  int   fd;
  int   y;

  if (argc != 2)
    return (1);
  if ((fd = open(argv[1], O_RDONLY)) < 2)
    return (1);
  map = NULL;
  if (wolf3d_parser(env, fd) == -1)
  {
    while(1);
    return (1);
  }
  // Avoid Leaks and print map
  y = 0;
  while(map[y])
  {
    ft_putendl(map[y]);
    free(map[y]);
    ++y;
  }
  free(map);
  return 0;
}
*/
// Parser qui convertit la map en char** pour pouvoir se servir de x et y.
// Pas de leaks
// Reste a faire : fonction qui check si la map est bien formée (si le labyrithe existes et si il est bien fermé, si le joueur est bien dedans etc)
