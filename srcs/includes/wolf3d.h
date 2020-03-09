/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malavent <malavent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 14:47:22 by achoquel          #+#    #+#             */
/*   Updated: 2019/06/13 15:16:12 by achoquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

#include <SDL2/SDL.h>
#include "../libft/includes/libft.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <SDL2/SDL.h>
#   ifndef M_PI
#     define M_PI 3.1415926535
#   endif

typedef struct  s_menu
{
    SDL_Texture *texture[4];
}               t_menu;

typedef struct  s_texture
{
    SDL_Texture *texture[12];
}               t_texture;

typedef struct  s_ennemie
{
    SDL_Texture *ennemie[6];
}               t_ennemie;

typedef struct  s_sprite
{
    SDL_Texture *sprite[6];
}               t_sprite;

typedef struct  s_loading
{
    SDL_Texture *texture[3];
}               t_loading;

typedef struct  s_weapons
{
    SDL_Texture *knife[4];
    SDL_Texture *pistol[4];
    SDL_Texture *minigun[4];
    SDL_Texture *flamethrower[4];

}               t_weapons;

typedef struct  s_player
{
  int     mapx;
  int     mapy;
  double  x;
  double  y;
  double  viewangle;
  double  fov;
  double  height;
}               t_player;

typedef struct  s_point
{
    double  x;
    double  y;
}               t_point;

typedef struct  s_env
{
    SDL_Window    *win;
    SDL_Renderer  *renderer;
    SDL_Event     events;
    SDL_Texture   *sdl_menu;
    int           end;
    t_menu         menu;
    t_texture textures;
    t_ennemie ennemie;
    t_sprite  sprite;
    t_loading loading;
    t_weapons weapons;
    t_player  player;
    int     startx;
    int     starty;
    double  winx;
    double  winy;
    char      **map;
}               t_env;

int sdl_errors(int code);
int   wolf3d_mapchecker(t_env *env);
int  wolf3d_parser(t_env * env, int fd);
int main_menu(SDL_Window *win, SDL_Renderer *renderer, SDL_Event events, t_env *env);
SDL_Texture *loadimage(const char path[], SDL_Renderer *renderer);

int load_textures(t_texture *texture, SDL_Renderer  *renderer);
int load_ennemies(t_ennemie *ennemie, SDL_Renderer  *renderer);
int load_sprites(t_sprite *sprite, SDL_Renderer  *renderer);
int load_menu(t_menu *menu, SDL_Renderer  *renderer);
int load_loading(t_loading *load, SDL_Renderer  *renderer);
int raycasting(t_env *env);
int weapon_master(SDL_Window *win, SDL_Renderer *renderer, int weapon);

#endif
