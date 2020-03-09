/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malavent <malavent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 10:25:52 by achoquel          #+#    #+#             */
/*   Updated: 2019/06/13 14:41:30 by achoquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include "includes/wolf3d.h"

void event_renderer(t_menu menu, SDL_Renderer *renderer, int frame)
{
  if (frame == 0)
  {
    SDL_RenderCopy(renderer, menu.texture[0], NULL, NULL);
    SDL_RenderPresent(renderer);
  }
  else if (frame == 1)
  {
    SDL_RenderCopy(renderer, menu.texture[1], NULL, NULL);
    SDL_RenderPresent(renderer);
  }
  else if (frame == 2)
  {
    SDL_RenderCopy(renderer, menu.texture[2], NULL, NULL);
    SDL_RenderPresent(renderer);
  }
  else if (frame == 3)
  {
    SDL_RenderCopy(renderer, menu.texture[3], NULL, NULL);
    SDL_RenderPresent(renderer);
  }
}

int loading_screen(t_loading *load, SDL_Window *win, SDL_Renderer *renderer, int ran, t_env *env)
{
  if (load_loading(load, renderer) == 1)
    return (1);
  if (ran == 0)
  {
    SDL_RenderCopy(renderer, load->texture[0], NULL, NULL);
    SDL_RenderPresent(renderer);
  }
  else if (ran == 1)
  {
    SDL_RenderCopy(renderer, load->texture[1], NULL, NULL);
    SDL_RenderPresent(renderer);
  }
  else if (ran == 2)
  {
    SDL_RenderCopy(renderer, load->texture[2], NULL, NULL);
    SDL_RenderPresent(renderer);
  }
  SDL_Delay(5000);
  return (raycasting(env));
}

int main_menu(SDL_Window *win, SDL_Renderer *renderer, SDL_Event events, t_env *env)
{
  t_menu        menu;
  t_loading     load;
  if (load_menu(&menu, renderer) == 1)
    return (1);
  SDL_RenderCopy(renderer, menu.texture[0], NULL, NULL);
  while(1)
  {
    SDL_WaitEvent(&events);
    if (events.type == SDL_MOUSEBUTTONDOWN)
    {
      if (events.button.button == SDL_BUTTON_LEFT && events.button.clicks == 1 && events.button.x >= 24 && events.button.x <= 511 && events.button.y >= 825 && events.button.y <= 892)
        return (1);
      if (events.button.button == SDL_BUTTON_LEFT && events.button.clicks == 1 && events.button.x >= 24 && events.button.x <= 511 && events.button.y >= 473 && events.button.y <= 540)
        return (loading_screen(&load, win, renderer, rand() % 3, env));
    }
    if (events.type == SDL_MOUSEMOTION)
    {
      if (events.motion.x >= 24 && events.motion.x <= 511 && events.motion.y >= 473 && events.motion.y <= 540)
        event_renderer(menu, renderer, 1);
      else if (events.motion.x >= 24 && events.motion.x <= 511 && events.motion.y >= 649 && events.motion.y <= 716)
        event_renderer(menu, renderer, 2);
      else if (events.motion.x >= 24 && events.motion.x <= 511 && events.motion.y >= 825 && events.motion.y <= 892)
        event_renderer(menu, renderer, 3);
      else
        event_renderer(menu, renderer, 0);
    }
    if (events.window.event == SDL_WINDOWEVENT_CLOSE)
      return (1);
  }
  return (0);
}
