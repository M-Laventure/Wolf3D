#include "includes/wolf3d.h"

/*
Dimension of the Projection Plane = 1920 x 1080 units
Center of the Projection Plane = (960,540)
Distance to the Projection Plane = 1662 units
Angle between subsequent rays = 60/1920 degrees
*/

typedef struct  s_vector
{
    double  x;
    double  y;
}       t_vector;

double radians (double angle)
{
  return (angle * (double)M_PI / (double)180.0);
}

int raycasting(t_env *env)
{
  int       w;
  int       h;
  t_vector  pos;
  t_vector  dir;
  t_vector  plane;
  int       x = 0;

  pos.x = 4;
  pos.y = 19;
  dir.x = 1;
  dir.y = 0;
  plane.x = 0;
  plane.y = -1;
  w = 1920;
  h = 1080;
  SDL_SetRenderDrawColor(env->renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
  SDL_RenderClear(env->renderer);
  SDL_SetRenderDrawColor(env->renderer, 255, 0, 255, SDL_ALPHA_OPAQUE);
  while (x <= w)
  {
    double  cameraX = (2*x/w)-1;
    t_vector rayPos = {pos.x, pos.y};
    t_vector rayDir = {dir.x+plane.x*cameraX, dir.y+plane.y*cameraX};
    t_vector map = {(int)rayPos.x, (int)rayPos.y};
    t_vector sideDist;
    t_vector deltaDist = {sqrt(1+(rayDir.y*rayDir.y)/(rayDir.x*rayDir.x)), sqrt(1+(rayDir.x*rayDir.x)/(rayDir.y*rayDir.y))};
    t_vector step;
    int      hit = 0;
    int      side;
    double  perpWallDist;

    if (rayDir.x < 0)
    {
      step.x = -1;
      sideDist.x = (rayPos.x - map.x) * deltaDist.x;
    }
    else
    {
      step.x = 1;
      sideDist.x = (map.x + 1.0 - rayPos.x) * deltaDist.x;
    }
    if (rayDir.y < 0)
    {
      step.y = -1;
      sideDist.y = (rayPos.y - map.y) * deltaDist.y;
    }
    else
    {
      step.y = 1;
      sideDist.y = (map.y + 1.0 - rayPos.y) * deltaDist.y;
    }
    while (hit == 0)
    {
      if (sideDist.x < sideDist.y)
      {
        sideDist.x += deltaDist.x;
        map.x += step.x;
        side = 0;
      }
      else
      {
        sideDist.y += deltaDist.y;
        map.y += step.y;
        side = 1;
      }
      if (env->map[(int)map.y][(int)map.x] > '0')
        hit = 1;
    }
    if (side == 0)
      perpWallDist = fabs((map.x-rayPos.x + (1-step.x)/2)/rayDir.x);
    else
      perpWallDist = fabs((map.y-rayPos.y + (1-step.y)/2)/rayDir.y);
    int  hauteurLigne = fabs(h / perpWallDist);
    int  drawStart = -hauteurLigne/2+h/2;
    int  drawEnd = hauteurLigne/2+h/2;
    if (drawStart < 0)
	     drawStart = 0;
    if (drawEnd >= h)
	     drawEnd = h-1;
    SDL_SetRenderDrawColor(env->renderer, 255, 0, 255, SDL_ALPHA_OPAQUE);
    SDL_RenderDrawLine(env->renderer, x, 0, x, drawStart);
    SDL_SetRenderDrawColor(env->renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
    SDL_RenderDrawLine(env->renderer, x, drawStart, x, drawEnd);
    SDL_SetRenderDrawColor(env->renderer, 0, 0, 255, SDL_ALPHA_OPAQUE);
    SDL_RenderDrawLine(env->renderer, x, drawEnd, x, 1080);
    ++x;
  }
  SDL_RenderPresent(env->renderer);
  SDL_Delay(10000);
  return (1);
}
