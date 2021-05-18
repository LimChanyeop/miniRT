/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clim <clim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 13:49:01 by clim              #+#    #+#             */
/*   Updated: 2021/05/18 13:49:09 by clim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_sphere		make_sphere(t_point point, double diameter, t_color color)
{
	t_sphere	sphere;

	if (rgb_validation(color) < 0)
		report_error(2);
	if (check_positive(diameter) < 0)
		report_error(5);
	sphere.center = point;
	sphere.radius = (double)diameter;
	sphere.radius2 = sphere.radius * sphere.radius;
	sphere.color = color;
	return (sphere);
}

t_bool			t_sp_validation(double t, t_intersect *inter)
{
	if (t > inter->t_min && t < inter->t_max)
	{
		inter->t = t;
		inter->t_max = t;
		return (TRUE);
	}
	else
		return (FALSE);
}

double			hit_sphere(t_sphere *sp, t_ray *ray)
{
	t_vec		oc;
	double		a;
	double		b;
	double		c;
	double		discriminant;

	oc = vminus(ray->orig, sp->center);
	a = vdot(ray->dir, ray->dir);
	b = 2.0 * vdot(oc, ray->dir);
	c = vdot(oc, oc) - sp->radius2;
	discriminant = b * b - 4 * a * c;
	if (discriminant < 0)
		return (-1.0);
	else if ((-b - sqrt(discriminant)) / (2.0 * a) < EPSILON)
		return ((-b + sqrt(discriminant)) / (2.0 * a));
	return ((-b - sqrt(discriminant)) / (2.0 * a));
}

void			set_inter_sp(t_sphere sp, t_ray ray, t_intersect *inter)
{
	inter->point = vplus(ray.orig, vmult_(ray.dir, inter->t));
	inter->normal_vec = vunit(vminus(inter->point, sp.center));
	inter->albedo = sp.color;
	if (vdot(vunit(vminus(ray_at(ray, inter->t), ray.orig)), \
		inter->normal_vec) > EPSILON)
		inter->normal_vec = vmult_(inter->normal_vec, -1);
}
