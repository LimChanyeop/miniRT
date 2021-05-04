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
	t_color ret_color;
	
	inter_obj.selected_type = -1;
	init_intersect(&inter);
	object = scene->sphere;
	while(object != 0)
	{
		if (t_sp_validation(hit_sphere(object->content, &ray), &inter) == TRUE)
		{
			inter_obj.sp = object->content;
			inter_obj.selected_type = SP;
			inter.point = vplus(ray.orig, vmult_(ray.dir, inter.t));
			inter.normal_vec = vunit(vminus(inter.point, inter_obj.sp->center));
		}
		object = object->next;
	}
	if (inter.t > 0)
	{
		t_color ret_color;
		ret_color = vmult_(scene->ambients.color, scene->ambients.ratio);
		ret_color = vplus(ret_color, coloring_sp(&scene, inter));
		// ambients -> 색깔 * 강도 -> ambients color -> 0~1 -> 0~1 사이가 된 obj color 와 곱하기
		// diffuse -> 색깔 * 강도 * 내적(vunit 법선, uvnit light dir)
		// 위 두개 더하고 -> 0~1 사이가 된 obj color 와 곱하기 
		// <reflective -> 색깔 * 강도 * 내적(vunit 법선, uvnit light dir) * (교점에서 카메라 ray(dir) 과 반사광의 각도(검색)>) ~ 제곱 -> color (0 ~ 1)
		// -> 0~ 1 가 되도록 만들기
		return (color_to_rgb(color));
	}
	else
    {
    	inter.t = 0.5 * (ray.dir.y + 1.0);
   		return (vplus(vmult_(color(1, 1, 1), 1.0 - inter.t), vmult_(color(0.5, 0.7, 1.0), inter.t)));
    }
}

t_vec			get_reflect(t_vec v, t_vec n)
{
	//v - 2 * dot(v, n) * n;
	return (vminus(v, vmult_(n, vdot(v, n) * 2)));
}

t_color		get_diff_spec_li(t_scene *scene, t_intersect inter, t_light *light)
{
	t_color spec;
	t_color diff;
	t_vec 	light_dir;
	t_vec	view_dir;
	t_vec	reflect_dir;
	double	strength;
	double		spec;
	double		ksn;
	double		ks;
	
	light_dir = vunit(vminus(light->point, inter.point));
	strength = fmax(vdot(inter.normal_vec, light_dir), 0.0);
	diff = vmult_(light->color, strength);
	view_dir = vunit(vmult());
	return (ret_color);
}

t_color			phong_lighting(t_scene *scene, t_intersect inter)
{
	t_color		light_color;
	t_list		*lights;
	t_light		*li;
	light_color = color(0, 0, 0);
	lights = scene->light;

	while (lights)
	{
		li = lights->content;
		light_color = vplus(light_color, li->color);
		lights = lights->next;
	}
	light_color = vplus(light_color, scene->ambients.color);
	return ((vmult(light_color, inter.albedo)));
}