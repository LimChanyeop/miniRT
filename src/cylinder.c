#include "utils.h"

t_cylinder make_cylinder(t_point point, t_vec vec, double radius, double height, t_color color)
{
	t_cylinder cylinder;

	if (vector_validation(vec) < 0)
		report_error(1);
	if (rgb_validation(color) < 0)
		report_error(2);
	cylinder.point = point;
	cylinder.vec = vec;
	cylinder.radius = radius;
	cylinder.height = height;
	cylinder.color = color;
	return (cylinder);
}

/*
t_bool		t_cy_validation(double t, t_intersect *inter)
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

double	hit_cylinder(t_cylinder *cy, t_ray *ray)
{
	
}

void		set_inter_cy(t_cylinder cy, t_ray ray, t_intersect *inter)
{
	
}
*/