/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clim <clim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 13:49:14 by clim              #+#    #+#             */
/*   Updated: 2021/05/18 13:49:15 by clim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_triangle		make_triangle(t_point p1, t_point p2, t_point p3, t_color color)
{
	t_triangle	triangle;

	if (rgb_validation(color) < 0)
		report_error(2);
	triangle.point1 = p1;
	triangle.point2 = p2;
	triangle.point3 = p3;
	triangle.color = color;
	return (triangle);
}

t_bool			t_tr_validation(double t, t_intersect *inter)
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

t_bool			hit_inside_tr(t_vec a, t_vec b, t_vec c, t_vec hit_point)
{
	t_vec	ba;
	t_vec	ca;
	t_vec	ha;

	ba = vminus(b, a);
	ca = vminus(c, a);
	ha = vminus(hit_point, a);
	if (vdot(vcross(ba, ca), vcross(ha, ca)) < 0)
		return (FALSE);
	else
		return (TRUE);
}

double			hit_triangle(t_triangle *tr, t_ray *ray)
{
	double		denom;
	double		nom;
	double		t;
	t_vec		hit_point;

	denom = vdot(vunit(vcross(vminus(tr->point1, tr->point2), \
						vminus(tr->point1, tr->point3))), ray->dir);
	nom = vdot(vminus(ray->orig, tr->point1), vunit(vcross(vminus(tr->point1, \
						tr->point2), vminus(tr->point1, tr->point3))));
	if (denom == 0)
		return (0);
	t = -nom / denom;
	hit_point = ray_at(*ray, t);
	if (!hit_inside_tr(tr->point1, tr->point2, tr->point3, hit_point))
		return (-1);
	if (!hit_inside_tr(tr->point2, tr->point3, tr->point1, hit_point))
		return (-1);
	if (!hit_inside_tr(tr->point3, tr->point1, tr->point2, hit_point))
		return (-1);
	else
		return (t);
}

void			set_inter_tr(t_triangle tr, t_ray ray, t_intersect *inter)
{
	inter->point = vplus(ray.orig, vmult_(ray.dir, inter->t));
	inter->normal_vec = vunit(vcross(vminus(tr.point1, tr.point2), \
						vminus(tr.point1, tr.point3)));
	inter->albedo = tr.color;
	if (vdot(ray_at(ray, inter->t), inter->normal_vec) > EPSILON)
		inter->normal_vec = vmult_(inter->normal_vec, -1);
}
