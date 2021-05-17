#include "utils.h"

t_ray			new_ray(t_vec orig, t_vec dir)
{
	t_ray 		new;

	new.orig = orig;
	new.dir = vunit(dir);
	return (new);
}

t_point			ray_at(t_ray ray, double t)
{
	t_point 	at;

	at = vplus(ray.orig, vmult_(ray.dir, t));
	return (at);
}

void 			init_intersect(t_intersect *inter, int max)
{
	inter->t_min = EPSILON;
	inter->t_max = max;
	inter->t = -1;
}

t_color			ray_color(t_ray ray, t_scene *scene)
{
	t_intersect	inter;
	t_color 	ret_color;

	init_intersect(&inter, 10000000);
	hit_obj(scene, ray, &inter);
	if (inter.t > 0)
	{
		ret_color = phong_lighting(scene, inter, ray);
		ret_color = vmin(ret_color, color(1, 1, 1));
		return (ret_color);
	}
	else
    {
    	inter.t = 0.5 * (ray.dir.y + 1.0);
   		return (vplus(vmult_(color(1, 1, 1), 1.0 - inter.t), vmult_(color(0.5, 0.7, 1.0), inter.t)));
    }
}
