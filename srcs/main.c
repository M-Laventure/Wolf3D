#include <stdio.h>
#include <stdlib.h>
#include "includes/wolf3d.h"

int init_wolf(t_env *env, char *file)
{
	int fd;
	int	y = 0;

	if ((fd = open(file, O_RDONLY)) < 2)
		return (-1);
	printf("%d\n", fd);
	env->map = NULL;
	if (wolf3d_parser(env, fd) == -1)
    	return (-1);
	return (0);
}

int init_menu(t_env *env)
{
  env->end = 0;
  if (SDL_Init(SDL_INIT_VIDEO) != 0)
    return (sdl_errors(0));
  env->win = SDL_CreateWindow("Wolf3D", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1920, 1080, SDL_WINDOW_SHOWN);
  if (env->win == NULL)
    return (sdl_errors(1));
  env->renderer = SDL_CreateRenderer(env->win, -1, SDL_RENDERER_SOFTWARE);
  if (env->renderer == NULL)
  {
    if (env->win != NULL)
      SDL_DestroyWindow(env->win);
    return (sdl_errors(2));
  }
  return (0);
}


int main(int argc, char *argv[])
{
	t_env *env;

	if (!(env = (t_env *)ft_memalloc(sizeof(t_env))))
		return (-1);
	if (init_wolf(env, argv[1]) == -1)
		return (1);
	if (init_menu(env) == 1)
		return (1);
	env->sdl_menu = loadimage("img/menuvoid.bmp", env->renderer);
  SDL_RenderCopy(env->renderer, env->sdl_menu, NULL, NULL);
	SDL_DestroyTexture(env->sdl_menu);
 	SDL_RenderPresent(env->renderer);
	while (!env->end)
  	{
		SDL_WaitEvent(&env->events);
		env->end = main_menu(env->win, env->renderer, env->events, env);
		if (env->events.window.event == SDL_WINDOWEVENT_CLOSE)
			env->end = 1;
 	}
	return (0);
}
