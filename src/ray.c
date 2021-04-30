#include "utils.h"

//ray 생성자
t_ray		ray(t_vec orig, t_vec dir)
{
	t_ray new;

	new.orig = orig;
	new.dir = vunit(dir);
	return (new);
}

//ray origin point 부터 방향벡터 ray dir * t 만큼 떨어진 점.
t_point		ray_at(t_ray ray, double t)
{
	t_point at;

	at = vplus(ray.orig, vmult_(ray.dir, t));
	return (at);
}

t_vec		ray_color(t_ray ray, t_scene *scene)
{
	t_sphere *sp;
	t_sphere *sp2;

	sp = scene->sphere->content;
	sp2 = scene->sphere->next->content;
	double t = hit_sphere(sp, &ray);//...
	double t1 = hit_sphere(sp2, &ray);

	if ((t > 0.0 && t < t1) || (t > 0 && t1 < 0))
	{
		t_vec N = vunit(vminus(ray_at(ray, t), sp->center));
		t_color color;
		color.x = (N.x + 1);
		color.y = (N.y + 1);
		color.z = (N.z + 1);
		return (vmult_(color, 0.5));
	}
	else if ((t1 > 0.0 && t1 < t) || (t1 > 0 && t < 0))
	{
		t_vec N = vunit(vminus(ray_at(ray, t1), sp2->center));
		t_color color;
		color.x = (N.x + 1);
		color.y = (N.y + 1);
		color.z = (N.z + 1);
		return (vmult_(color, 0.5));
	}
	else
    {
    	t = 0.5 * (ray.dir.y + 1.0);
   		return (vplus(vmult_(color(1, 1, 1), 1.0 - t), vmult_(color(0.5, 0.7, 1.0), t)));
    }
}
