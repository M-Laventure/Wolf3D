/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malavent <malavent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 10:45:55 by achoquel          #+#    #+#             */
/*   Updated: 2019/06/12 11:07:57 by malavent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include "includes/wolf3d.h"

SDL_Texture *loadimage(const char path[], SDL_Renderer *renderer)
{
    SDL_Surface *tmp = NULL;
    SDL_Texture *texture = NULL;
    tmp = SDL_LoadBMP(path);
    if( NULL == tmp)
        return NULL;
    texture = SDL_CreateTextureFromSurface(renderer, tmp);
    SDL_FreeSurface(tmp);
    if(NULL == texture)
        return NULL;
    return (texture);
}

int sdl_errors(int code)
{
  if (code == 0)
  {
    ft_putendl("Erreur durant l'initialisation de la SDL");
    SDL_Quit();
  }
  if (code == 1)
  {
    ft_putendl("Erreur durant la création de la fenêtre");
    SDL_Quit();
  }
  if (code == 2)
  {
    ft_putendl("Erreur durant la création du renderer");
    SDL_Quit();
  }
  if (code == 3)
  {
    ft_putendl("Erreur durant la création d'une image");
    SDL_Quit();
  }
  return (1);
}

/*void    init_posplayer(t_wolf3d *wolf3d, int mod)
{
    wolf3d->player->pos_x = wolf3d->mapx * wolf3d->scale;
    wolf3d->player->pos_y = wolf3d->mapy * wolf3d->scale;
}*/
