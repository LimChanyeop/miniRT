/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clim <clim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 13:48:57 by clim              #+#    #+#             */
/*   Updated: 2021/05/18 13:48:57 by clim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_plane		make_plane(t_vec point, t_vec vec, t_color color)
{
	t_plane plane;

	if (vector_validation(vec) < 0)
		report_error(1);
	if (rgb_validation(color) < 0)
		report_error(2);
	plane.point = point;
	plane.vec = vunit(vec);
	plane.color = color;
	return (plane);
}

t_bool		t_pl_validation(double t, t_intersect *inter)
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

double		hit_plane(t_plane *pl, t_ray *ray)
{
	double	denominator;
	t_vec	r0_p0;
	double	root;

	denominator = vdot(pl->vec, ray->dir);
	if (fabs(denominator) < EPSILON)
		return (-1);
	r0_p0 = vminus(pl->point, ray->orig);
	root = vdot(r0_p0, pl->vec) / denominator;
	return (root);
}

void		set_inter_pl(t_plane pl, t_ray ray, t_intersect *inter)
{
	inter->point = vplus(ray.orig, vmult_(ray.dir, inter->t));
	inter->normal_vec = vunit(pl.vec);
	inter->albedo = pl.color;
	if (vdot(vunit(vminus(inter->point, ray.orig)), inter->normal_vec) > 0)
		inter->normal_vec = vmult_(inter->normal_vec, -1);
}
