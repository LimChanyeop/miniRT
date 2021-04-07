#ifndef RAY_H
# define RAY_H

# include "structures.h"
# include "utils.h"

t_point	    ray_at(t_ray *ray, double t);
t_ray		ray(t_point orig, t_vec dir);
t_vec	    ray_color(t_vec orig, t_vec dir);
int	        hit_sphere(t_vec center, double radius, t_vec origin, t_vec direction);

#endif
