/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapons.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoquel <achoquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 13:52:21 by achoquel          #+#    #+#             */
/*   Updated: 2019/06/11 14:55:01 by malavent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include "includes/wolf3d.h"

int load_weapons2(t_weapons *weapons, SDL_Renderer  *renderer)
{
  if ((weapons->flamethrower[0] = loadimage("img/weapons/flamethrower1.bmp", renderer)) == NULL)
    return (1);
  if ((weapons->flamethrower[1] = loadimage("img/weapons/flamethrower2.bmp", renderer)) == NULL)
    return (1);
  if ((weapons->flamethrower[2] = loadimage("img/weapons/flamethrower3.bmp", renderer)) == NULL)
    return (1);
  if ((weapons->flamethrower[3] = loadimage("img/weapons/flamethrower4.bmp", renderer)) == NULL)
    return (1);
  return (0);
}

int load_weapons(t_weapons *weapons, SDL_Renderer  *renderer)
{
  if ((weapons->pistol[0] = loadimage("img/weapons/pistol1.bmp", renderer)) == NULL)
    return (1);
  if ((weapons->pistol[1] = loadimage("img/weapons/pistol2.bmp", renderer)) == NULL)
    return (1);
  if ((weapons->pistol[2] = loadimage("img/weapons/pistol3.bmp", renderer)) == NULL)
    return (1);
  if ((weapons->pistol[3] = loadimage("img/weapons/pistol4.bmp", renderer)) == NULL)
    return (1);
  if ((weapons->knife[0] = loadimage("img/weapons/knife1.bmp", renderer)) == NULL)
    return (1);
  if ((weapons->knife[1] = loadimage("img/weapons/knife2.bmp", renderer)) == NULL)
    return (1);
  if ((weapons->knife[2] = loadimage("img/weapons/knife3.bmp", renderer)) == NULL)
    return (1);
  if ((weapons->knife[3] = loadimage("img/weapons/knife4.bmp", renderer)) == NULL)
    return (1);
  if ((weapons->minigun[0] = loadimage("img/weapons/minigun1.bmp", renderer)) == NULL)
    return (1);
  if ((weapons->minigun[1] = loadimage("img/weapons/minigun2.bmp", renderer)) == NULL)
    return (1);
  if ((weapons->minigun[2] = loadimage("img/weapons/minigun3.bmp", renderer)) == NULL)
    return (1);
  if ((weapons->minigun[3] = loadimage("img/weapons/minigun4.bmp", renderer)) == NULL)
    return (1);
  return (load_weapons2(weapons, renderer));
}

void pistol_loop(SDL_Renderer *renderer, t_weapons weapons)
{
  SDL_RenderClear(renderer);
  SDL_RenderCopy(renderer, weapons.pistol[0], NULL, NULL);
  SDL_RenderPresent(renderer);
  SDL_Delay(100);
  SDL_RenderClear(renderer);
  SDL_RenderCopy(renderer, weapons.pistol[1], NULL, NULL);
  SDL_RenderPresent(renderer);
  SDL_Delay(100);
  SDL_RenderClear(renderer);
  SDL_RenderCopy(renderer, weapons.pistol[2], NULL, NULL);
  SDL_RenderPresent(renderer);
  SDL_Delay(100);
  SDL_RenderClear(renderer);
  SDL_RenderCopy(renderer, weapons.pistol[3], NULL, NULL);
  SDL_RenderPresent(renderer);
  SDL_Delay(300);
  SDL_RenderCopy(renderer, weapons.pistol[1], NULL, NULL);
  SDL_RenderPresent(renderer);
  SDL_Delay(200);
  SDL_RenderClear(renderer);
  SDL_RenderCopy(renderer, weapons.pistol[0], NULL, NULL);
  SDL_RenderPresent(renderer);
  SDL_Delay(100);
  SDL_RenderClear(renderer);
}

void minigun_loop(SDL_Renderer *renderer, t_weapons weapons, SDL_Event events)
{
  int end;

  end = 0;
  SDL_RenderClear(renderer);
  SDL_RenderCopy(renderer, weapons.minigun[0], NULL, NULL);
  SDL_RenderPresent(renderer);
  SDL_Delay(100);
  SDL_RenderClear(renderer);
  SDL_RenderCopy(renderer, weapons.minigun[1], NULL, NULL);
  SDL_RenderPresent(renderer);
  SDL_Delay(200);
  while (!end)
  {
    SDL_PollEvent(&events);
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, weapons.minigun[2], NULL, NULL);
    SDL_RenderPresent(renderer);
    SDL_Delay(100);
    SDL_RenderCopy(renderer, weapons.minigun[3], NULL, NULL);
    SDL_RenderPresent(renderer);
    SDL_Delay(100);
    if (events.type == SDL_MOUSEBUTTONUP && events.button.button == SDL_BUTTON_LEFT)
      end = 1;
  }
  SDL_RenderClear(renderer);
  SDL_RenderCopy(renderer, weapons.minigun[1], NULL, NULL);
  SDL_RenderPresent(renderer);
  SDL_Delay(100);
  SDL_RenderClear(renderer);
  SDL_RenderCopy(renderer, weapons.minigun[0], NULL, NULL);
  SDL_RenderPresent(renderer);
}

void flamethrower_loop(SDL_Renderer *renderer, t_weapons weapons, SDL_Event events)
{
  int end;

  end = 0;
  SDL_RenderClear(renderer);
  SDL_RenderCopy(renderer, weapons.flamethrower[0], NULL, NULL);
  SDL_RenderPresent(renderer);
  SDL_Delay(100);
  SDL_RenderClear(renderer);
  SDL_RenderCopy(renderer, weapons.flamethrower[1], NULL, NULL);
  SDL_RenderPresent(renderer);
  SDL_Delay(200);
  while (!end)
  {
    SDL_PollEvent(&events);
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, weapons.flamethrower[2], NULL, NULL);
    SDL_RenderPresent(renderer);
    SDL_Delay(100);
    SDL_RenderCopy(renderer, weapons.flamethrower[3], NULL, NULL);
    SDL_RenderPresent(renderer);
    SDL_Delay(100);
    if (events.type == SDL_MOUSEBUTTONUP && events.button.button == SDL_BUTTON_LEFT)
      end = 1;
  }
  SDL_RenderClear(renderer);
  SDL_RenderCopy(renderer, weapons.flamethrower[1], NULL, NULL);
  SDL_RenderPresent(renderer);
  SDL_Delay(100);
  SDL_RenderClear(renderer);
  SDL_RenderCopy(renderer, weapons.flamethrower[0], NULL, NULL);
  SDL_RenderPresent(renderer);
}

void knife_loop(SDL_Renderer *renderer, t_weapons weapons)
{
  SDL_RenderClear(renderer);
  SDL_RenderCopy(renderer, weapons.knife[0], NULL, NULL);
  SDL_RenderPresent(renderer);
  SDL_Delay(70);
  SDL_RenderClear(renderer);
  SDL_RenderCopy(renderer, weapons.knife[1], NULL, NULL);
  SDL_RenderPresent(renderer);
  SDL_Delay(100);
  SDL_RenderClear(renderer);
  SDL_RenderCopy(renderer, weapons.knife[2], NULL, NULL);
  SDL_RenderPresent(renderer);
  SDL_Delay(70);
  SDL_RenderClear(renderer);
  SDL_RenderCopy(renderer, weapons.knife[3], NULL, NULL);
  SDL_RenderPresent(renderer);
  SDL_Delay(100);
  SDL_RenderCopy(renderer, weapons.knife[1], NULL, NULL);
  SDL_RenderPresent(renderer);
  SDL_Delay(100);
  SDL_RenderClear(renderer);
  SDL_RenderCopy(renderer, weapons.knife[0], NULL, NULL);
  SDL_RenderPresent(renderer);
  SDL_Delay(50);
  SDL_RenderClear(renderer);
}

int weapon_master(SDL_Window *win, SDL_Renderer *renderer, int weapon)
{
  t_weapons weapons;
  SDL_Event events;

  if (load_weapons(&weapons, renderer))
    return (1);
  while (1)
  {
    SDL_WaitEvent(&events);
    if (events.type == SDL_MOUSEBUTTONDOWN)
    {
      if (events.button.button == SDL_BUTTON_LEFT && events.button.clicks == 1)
      {
        if (weapon == 1)
          pistol_loop(renderer, weapons);
        else if (weapon == 3)
          minigun_loop(renderer, weapons, events);
      }
      if (events.button.button == SDL_BUTTON_MIDDLE && events.button.clicks == 1)
          return (1);
    }
  }
}
