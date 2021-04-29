#include "utils.h"

//ray 생성자
t_ray	ray(t_vec orig, t_vec dir)
{
	t_ray new;

	new.orig = orig;
	new.dir = dir;
	return (new);
}

//ray origin point 부터 방향벡터 ray dir * t 만큼 떨어진 점.
t_vec ray_at(t_vec orig, t_vec dir, double t)
{
	t_vec at;

	at = vplus(orig, vmult_(dir, t));
	return (at);
}

t_vec	ray_color(t_ray *ray, t_scene *scene)
{
	t_sphere *sp;

	sp = scene->sphere;
	double t = hit_sphere(sp, ray);//...
	if (t > 0.0)
	{
		t_vec N = vunit(vminus(ray_at(ray->orig, ray->dir, t), sp->center));
		t_vec color;
		color.x = (N.x + 1);
		color.y = (N.y + 1);
		color.z = (N.z + 1);
		return (vmult_(color, 0.5));
	}
	else
    	{
    		//ray의 방향벡터의 y 값을 기준으로 그라데이션을 주기 위한 계수.
    		t = 0.5 * (ray->dir.y + 1.0);
    		// (1-t) * 흰색 + t * 하늘색
    		return (vplus(vmult(color(1, 1, 1), 1.0 - t), vmult(color(0.5, 0.7, 1.0),     t)));
    	}
    // 추가 끝
    }
