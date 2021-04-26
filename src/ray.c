#include "utils.h"

//ray 생성자
t_ray	ray(t_vec orig, t_vec dir)
{
	t_ray new;

	new.orig = orig;
	new.dir = dir;
	return (new);
}

//ray origin point 부터 방향벡터 ray dir * t 만큼 떨어진점.
t_vec ray_at(t_vec orig, t_vec dir, double t)
{
	t_vec at;

	at = vplus(orig, vmult_(dir, t));
	return (at);
}

t_vec	ray_color(t_vec orig, t_vec dir)
{
	t_vec sphere = {0, 0, -2};
	float t = hit_sphere(sphere, 0.5, orig, dir);
	if (t > 0.0)
	{
		t_vec N = vunit(vminus(ray_at(orig, dir, t), sphere));
		t_vec color;
		color.x = (N.x + 1);
		color.y = (N.y + 1);
		color.z = (N.z + 1);
		return (vmult_(color, 0.5));
	}
	t_vec unit_direction = vunit(dir);
	t = 0.5 * (unit_direction.y + 1.0);
	t_vec a = vec(1.0, 1.0, 1.0);
	t_vec b; b.x = 0.5; b.y = 0.7; b.z = 1.0;
	return (vplus(vmult_(a, 1.0 - t), vmult_(b, t)));
}
