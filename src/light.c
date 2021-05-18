/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clim <clim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 13:48:38 by clim              #+#    #+#             */
/*   Updated: 2021/05/18 14:07:10 by clim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_light			make_light(t_vec point, double brightness, t_color color)
{
	t_light		light;

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
	light_color = vplus(light_color, vmult_(scene->ambients.color, \
		scene->ambients.ratio));
	return ((vmult(light_color, inter.albedo)));
}

t_color			get_diff_spec_li(t_intersect inter, t_light *light, t_ray ray)
{
	t_color		diff_spec[2];
	t_vec		li_vi_rf[3];
	double		st_sp_kn_ks[4];

	li_vi_rf[0] = vunit(vminus(light->point, inter.point));
	st_sp_kn_ks[0] = fmax(vdot(inter.normal_vec, li_vi_rf[0]), 0.0);
	diff_spec[0] = vmult_(light->color, st_sp_kn_ks[0]);
	li_vi_rf[1] = vunit(vmult_(ray.dir, -1));
	li_vi_rf[2] = get_reflect(vmult_(li_vi_rf[0], -1), inter.normal_vec);
	st_sp_kn_ks[2] = 10;
	st_sp_kn_ks[3] = 0.5;
	st_sp_kn_ks[1] = pow(fmax(vdot(li_vi_rf[1], li_vi_rf[2]), 0.0), \
		st_sp_kn_ks[2]);
	diff_spec[1] = vmult_(vmult_(light->color, st_sp_kn_ks[3]), \
		st_sp_kn_ks[1]);
	return (vmult_(vplus(diff_spec[0], diff_spec[1]), \
				light->brightness * LUMEN));
}

t_vec			get_reflect(t_vec v, t_vec n)
{
	return (vminus(v, vmult_(n, vdot(v, n) * 2)));
}
