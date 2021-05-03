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

void init_intersect(t_intersect *inter)
{
	inter->t_min = EPSILON;
	inter->t_max = 1000000000;
	inter->t = -1;
}

t_color		ray_color(t_ray ray, t_scene *scene)
{
	t_list *object;
	t_intersect inter;
	t_intersect_object inter_obj;

	inter_obj.selected_type = -1;
	init_intersect(&inter);
	object = scene->sphere;
	while(object != 0)
	{
		if (t_sp_validation(hit_sphere(object->content, &ray), &inter) == TRUE)
		{
			inter_obj.sp = object->content;
			inter_obj.selected_type = SP;
		}
		object = object->next;
	}

	if (inter.t > 0)
	{
		t_vec N = vunit(vminus(ray_at(ray, inter.t), inter_obj.sp->center));
		t_color color;
		color.x = (N.x + 1);
		color.y = (N.y + 1);
		color.z = (N.z + 1);
		return (inter_obj.sp->color);
	}
	else
    {
    	inter.t = 0.5 * (ray.dir.y + 1.0);
   		return (vplus(vmult_(color(1, 1, 1), 1.0 - inter.t), vmult_(color(0.5, 0.7, 1.0), inter.t)));
    }
}
