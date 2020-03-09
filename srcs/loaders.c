/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loaders.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoquel <achoquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 13:34:32 by achoquel          #+#    #+#             */
/*   Updated: 2019/06/11 14:44:47 by malavent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include "includes/wolf3d.h"

int load_textures(t_texture *texture, SDL_Renderer  *renderer)
{
  if ((texture->texture[0] = loadimage("img/textures/rock.bmp", renderer)) == NULL)
    return (1);
  if ((texture->texture[1] = loadimage("img/textures/rockflag.bmp", renderer)) == NULL)
    return (1);
  if ((texture->texture[2] = loadimage("img/textures/rockdeco.bmp", renderer)) == NULL)
    return (1);
  if ((texture->texture[3] = loadimage("img/textures/rockframe.bmp", renderer)) == NULL)
    return (1);
  if ((texture->texture[4] = loadimage("img/textures/rockyellow.bmp", renderer)) == NULL)
    return (1);
  if ((texture->texture[5] = loadimage("img/textures/rock2.bmp", renderer)) == NULL)
    return (1);
  if ((texture->texture[6] = loadimage("img/textures/rock2deco.bmp", renderer)) == NULL)
    return (1);
  if ((texture->texture[7] = loadimage("img/textures/wood.bmp", renderer)) == NULL)
    return (1);
  if ((texture->texture[8] = loadimage("img/textures/woodframe.bmp", renderer)) == NULL)
    return (1);
  if ((texture->texture[9] = loadimage("img/textures/bluerock.bmp", renderer)) == NULL)
    return (1);
  if ((texture->texture[10] = loadimage("img/textures/bluerockdeco.bmp", renderer)) == NULL)
    return (1);
  if ((texture->texture[11] = loadimage("img/textures/metaldoor.bmp", renderer)) == NULL)
    return (1);
  return (0);
}

int load_ennemies(t_ennemie *ennemie, SDL_Renderer  *renderer)
{
  if ((ennemie->ennemie[0] = loadimage("img/ennemies/nazi1.bmp", renderer)) == NULL)
    return (1);
  if ((ennemie->ennemie[1] = loadimage("img/ennemies/nazi2.bmp", renderer)) == NULL)
    return (1);
  if ((ennemie->ennemie[2] = loadimage("img/ennemies/dog.bmp", renderer)) == NULL)
    return (1);
  if ((ennemie->ennemie[3] = loadimage("img/ennemies/boss1.bmp", renderer)) == NULL)
    return (1);
  if ((ennemie->ennemie[4] = loadimage("img/ennemies/boss2.bmp", renderer)) == NULL)
    return (1);
  if ((ennemie->ennemie[5] = loadimage("img/ennemies/boss3.bmp", renderer)) == NULL)
    return (1);
  return (0);
}

int load_sprites(t_sprite *sprite, SDL_Renderer  *renderer)
{
  if ((sprite->sprite[0] = loadimage("img/sprites/armor.bmp", renderer)) == NULL)
    return (1);
  if ((sprite->sprite[1] = loadimage("img/sprites/barrel.bmp", renderer)) == NULL)
    return (1);
  if ((sprite->sprite[2] = loadimage("img/sprites/bones.bmp", renderer)) == NULL)
    return (1);
  if ((sprite->sprite[3] = loadimage("img/sprites/chest.bmp", renderer)) == NULL)
    return (1);
  if ((sprite->sprite[4] = loadimage("img/sprites/crown.bmp", renderer)) == NULL)
    return (1);
  if ((sprite->sprite[5] = loadimage("img/sprites/key.bmp", renderer)) == NULL)
    return (1);
  return (0);
}

int load_menu(t_menu *menu, SDL_Renderer  *renderer)
{
  if ((menu->texture[0] = loadimage("img/menu/menuvoid.bmp", renderer)) == NULL)
    return (1);
  if ((menu->texture[1] = loadimage("img/menu/menusolo.bmp", renderer)) == NULL)
    return (1);
  if ((menu->texture[2] = loadimage("img/menu/menuoption.bmp", renderer)) == NULL)
    return (1);
  if ((menu->texture[3] = loadimage("img/menu/menuexit.bmp", renderer)) == NULL)
    return (1);
  return (0);
}

int load_loading(t_loading *load, SDL_Renderer  *renderer)
{
  if ((load->texture[0] = loadimage("img/loading/loading1.bmp", renderer)) == NULL)
    return (1);
  if ((load->texture[1] = loadimage("img/loading/loading2.bmp", renderer)) == NULL)
    return (1);
  if ((load->texture[2] = loadimage("img/loading/loading3.bmp", renderer)) == NULL)
    return (1);
  return (0);
}
