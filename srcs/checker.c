/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malavent <malavent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 14:33:04 by achoquel          #+#    #+#             */
/*   Updated: 2019/06/13 15:30:44 by achoquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/wolf3d.h"

static int   size_shape(t_env *env)
{
  int x;
  int sizex;
  int y;

  x = 0;
  y = 0;
  sizex = -2;
  while (env->map[y])
  {
    while(env->map[y][x])
      ++x;
    ++y;
    if (sizex == -2)
      sizex = x;
    if (sizex != x)
      sizex = -1;
    x = 0;
  }
  if (sizex < 3 || sizex > 25 || y < 3 || y > 25)
    return (-1);
  return (0);
}

static int content(t_env *env)
{
  int x;
  int y;
  int player;

  x = 0;
  y = 0;
  player = 0;
	ft_putendl("CRASH1");
  while(env->map[y])
  {
    while(env->map[y][x])
    {
      if (env->map[y][x] != '1' && env->map[y][x] != '0' && env->map[y][x] != 'P')
        return (1);
      if (env->map[y][x] == 'P' && player == 0)
      {
        player = 1;
        env->player.x = x * 128 - 64;
        env->player.y = y * 128 - 64;
		env->map[y][x] = 0;
	  }
      else if (env->map[y][x] == 'P' && player == 1)
        return (-1);
      ++x;
    }
    x = 0;
    ++y;
  }
  return (0);
}

int   wolf3d_mapchecker(t_env *env)
{
  //size_shape: finds if the env->map isn't a rectangle and is >25x25, content checks env->map content, maze checks if the env->map is a well-formed maze
  if (size_shape(env) == 1 || content(env) == 1 /*|| maze(env->map) == 1*/)
    return (-1);
  return (0);
}
