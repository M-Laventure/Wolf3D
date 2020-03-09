#include "includes/wolf3d.h"

/*
Dimension of the Projection Plane = 640 x 400 units
Center of the Projection Plane = (320,200)
Distance to the Projection Plane = 554 units
Angle between subsequent rays = 60/640 degrees
*/

double degtorad(double radians)
{
    return (radians * 0.0174533);
}
/*
int wallfinder(t_wolf3d *env)
{
    int hit;
    int x;

    double  inter_x;
    double  inter_y;
    double  angle;

    double  ya;
    double  xa;

    double  xb;
    double  yb;

    hit = 0;
    x = 0;
    angle = 0;

    while (x < 640)
    {
      if (rayon est vers le haut)
      {
        inter_y = env->player.y/128 * 128 - 1;
        ya = -128;
      }
      else
      {
        inter_y = env->player.y/128 * 128 + 128;
        ya = 128;
      }
      inter_x = env->player.x + (env->player.y - inter_y)/tan(angle);
      xa = 128/tan(angle);
      while (hit == 0)
      {
        if ()
          hit = 1;
        else
        {
          inter_x += xa;
          inter_y += ya;
        }
      }
      ++x;
      angle += 60/640;
      hit = 0;
    }

    x = 0;
    angle = 0;
    while (x < 640)
    {
        if (rayon est vers la droite)
        {
          bx = env->player.x/128 * 128 + 128;
          xa = 128;
        }
        else
        {
          bx = env->player.x/128 * 128 - 1;
          xa = 128;
        }
        by = env->player.y + (env->player.x + x) * tan(fov);
        ya = 128 * tan(fov);
        while (hit == 0)
        {
          if ()
            hit = 1;
          else
          {
            inter_x += xa;
            inter_y += ya;
          }
        }
        ++x;
        angle += 60/640;
        hit = 0;
      }
}
*/

t_point vertical_finder(t_env *env, int x, double angle)
{
  t_point collision;
  double  xa;
  double  ya;
  int     hit;

  hit = 0;
  if (angle >= 0 && angle <= 180)
  {
    collision.x = floor(env->player.x/128) * 128 + 128;
    xa = 128;
  }
  else
  {
    collision.x = floor(env->player.x/128) * 128 - 1;
    xa = -128;
  }
  collision.y = env->player.y + (env->player.x - collision.x) * tan(degtorad(angle));
  ya = 128 * tan(degtorad(angle));
  while (hit == 0)
  {
    printf("Vertical: x: %d    y: %d      pixel: %d\n", (int)floor(collision.x / 128), (int)floor(collision.y / 128), x);
    if (env->map[(int)floor(collision.y / 128)][(int)floor(collision.x / 128)] == '1')
    {
      printf("Vertical hit: x: %d    y: %d\n", (int)floor(collision.x / 128), (int)floor(collision.y / 128));
      hit = 1;
    }
    else
    {
      collision.x += xa;
      collision.y += ya;
    }
    SDL_Delay(500);
  }
  return (collision);
}

t_point horizontal_finder(t_env *env, int x, double angle)
{
  t_point collision;
  double  ya;
  double  xa;
  int     hit;

  hit = 0;
  if (angle <= 90 && angle >= 270)
  {
    collision.y = floor(env->player.y / 128) * 128 - 1;
    ya = -128;
  }
  else
  {
    collision.y = floor(env->player.y / 128) * 128 + 128;
    ya = 128;
  }
  collision.x = env->player.x + (env->player.y - collision.y) / tan(degtorad(angle));
  xa = 73;
  while (hit == 0)
  {
    //printf("Horizontal: x: %d    y: %d pixel: %d\n", (int)floor(collision.x / 128), (int)floor(collision.y / 128), x);
    if (env->map[(int)floor(collision.y / 128)][(int)floor(collision.x / 128)] == '1')
    {
      hit = 1;
    //  printf("Horizontal hit: x: %d    y: %d\n", (int)floor(collision.x / 128), (int)floor(collision.y / 128));
    }
    else
    {
      collision.x += xa;
      collision.y += ya;
    }
  }
  return (collision);
}


double  getangle(double angle, int add)
{
  if (add == 1)
  {
    if (angle + 0.03125 > 360)
      return (0 + (360 - angle + 0.03125));
    return (angle + 0.03125);
  }
  else
  {
    if (angle >= 30)
      return (angle - 30);
    else
      return (360 + angle - 30);
  }
}

int raycasting(t_env *env)
{
  t_point  vert_collision;
  t_point  hor_collision;
  double   vert_dist;
  double   hor_dist;
  double   dist;
  int   wall_height;
  double   angle;
  int      x;
  int      y = 0;

  x = 0;
  env->player.viewangle = 180;
  angle = getangle(env->player.viewangle, 0);
  SDL_SetRenderDrawColor(env->renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
  SDL_RenderClear(env->renderer);
  SDL_SetRenderDrawColor(env->renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
  while(env->map[y])
  {
    ft_putendl(env->map[y]);
    ++y;
  }
  while (x < 1920)
  {
    vert_collision = vertical_finder(env, x, angle);
    hor_collision = horizontal_finder(env, x, angle);
    vert_dist = fabs(env->player.x - vert_collision.x / 0.5);
    hor_dist = fabs(env->player.x - hor_collision.x / 0.5);
   if (vert_dist < hor_dist)
    {
      if (angle > 180 && angle < 360)
        dist = vert_dist * cos(degtorad(30));
      else
        dist = vert_dist * cos(degtorad(-30));
    }
    else
    {
      if (angle > 180 && angle < 360)
        dist = hor_dist * cos(degtorad(30));
      else
        dist = hor_dist * cos(degtorad(-30));
    }
    wall_height = (int)((128 / dist) * 1660);
    /*draw_collumn(wall_height, x);*/
    SDL_RenderDrawLine(env->renderer, x, 540 - abs(wall_height/2), x, 540 + abs(wall_height / 2));
    //printf("Line drawn with %d height\n", wall_height);
    ++x;
    angle = getangle(angle, 1);
  }
  SDL_RenderPresent(env->renderer);
  SDL_Delay(10000);
  return (0);
}
