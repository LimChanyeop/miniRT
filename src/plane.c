#include "utils.h"

t_plane	make_plane(t_vec point, t_vec vec, t_color color)
{
	t_plane plane;
	if (vector_validation(vec) < 0)
		report_error(1);
	if (rgb_validation(color) < 0)
		report_error(2);
	plane.point = point;
	plane.vec = vec;
	plane.color = color;
	return (plane);
}
/*
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

double	hit_plane(t_plane *pl, t_ray *ray)
{
	
}

void		set_inter_pl(t_plane pl, t_ray ray, t_intersect *inter)
{
	
}
*/