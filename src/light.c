#include "utils.h"
//도형 * 4 더 X , 내 외부 구분 X, bmp, camera 전환 X, 해상도 get_screen_size X
t_light	make_light(t_vec point, double brightness, t_color color)
{
	t_light light;

	if (light_validation(brightness) < 0)
		report_error(4);
	if (rgb_validation(color) < 0)
		report_error(2);
	light.point = point;
	light.brightness = brightness;
	light.color = color;
	return (light);
}

t_color			phong_lighting(t_scene *scene, t_intersect inter, t_ray ray)
{
	t_color		light_color;
	t_list		*lights;
	t_light		*li;
	t_ray		to_light_ray;
	t_intersect light_inter;

	light_color = color(0, 0, 0);
	lights = scene->light;
	while (lights)
	{
		li = lights->content;
		init_intersect(&light_inter, vlength(vminus(li->point, inter.point)));
		to_light_ray = new_ray(inter.point, vminus(li->point, inter.point));
		hit_obj(scene, to_light_ray, &light_inter);
		if (light_inter.t < 0)
			light_color = vplus(light_color, get_diff_spec_li(inter, li, ray));
		lights = lights->next;
	}
	light_color = vplus(light_color, vmult_(scene->ambients.color, scene->ambients.ratio));
	return ((vmult(light_color, inter.albedo)));
}

t_color		get_diff_spec_li(t_intersect inter, t_light *light, t_ray ray)
{
	t_color diffuse;
	t_color specular;
	t_vec 	light_dir;
	t_vec	view_dir;
	t_vec	reflect_dir;
	double	strength;
	double	spec;
	double	ksn;
	double	ks;

	light_dir = vunit(vminus(light->point, inter.point));
	strength = fmax(vdot(inter.normal_vec, light_dir), 0.0);
	diffuse = vmult_(light->color, strength);
	view_dir = vunit(vmult_(ray.dir, -1));
	reflect_dir = get_reflect(vmult_(light_dir, -1), inter.normal_vec);
	ksn = 10;
	ks = 0.5;
	spec = pow(fmax(vdot(view_dir, reflect_dir), 0.0), ksn);
	specular = vmult_(vmult_(light->color, ks), spec);
	return (vmult_(vplus(diffuse, specular), light->brightness * LUMEN));
}

t_vec			get_reflect(t_vec v, t_vec n)
{
	return (vminus(v, vmult_(n, vdot(v, n) * 2)));
}
