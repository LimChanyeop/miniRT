#include "ray.h"

//ray 생성자
t_ray	ray(t_point orig, t_vec dir)
{
	t_ray new;

	new.orig = orig;
	new.dir = dir;
	return (new);
}

//ray origin point 부터 방향벡터 ray dir * t 만큼 떨어진점.
t_point ray_at(t_ray *ray, double t)
{
	t_point at;

	at = vplus(ray->orig, vmult(ray->dir, t));
	return (at);
}

t_vec	ray_color(t_vec orig, t_vec dir)
{
	t_vec sphere = {0, 0, -1};
	t_vec sphere_color = {1, 0, 0};
	if (hit_sphere(sphere, 0.5, orig, dir))
		return (sphere_color);
	t_vec unit_direction = vunit(dir);
	float t = 0.5 * (unit_direction.y + 1.0);
	t_vec a = vec(1.0, 1.0, 1.0);
	t_vec b; b.x = 0.5; b.y = 0.7; b.z = 1.0;
	return (vplus(vmult(a, 1.0 - t), vmult(b, t)));
}