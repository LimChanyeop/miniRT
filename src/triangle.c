#include "utils.h"

t_triangle	make_triangle(t_point point1, t_point point2, t_point point3, t_color color)
{
	t_triangle triangle;

	if (rgb_validation(color) < 0)
		report_error(2);
	triangle.point1 = point1;
	triangle.point2 = point2;
	triangle.point3 = point3;
	triangle.color = color;
	return (triangle);
}
/*
t_bool		t_tr_validation(double t, t_intersect *inter)
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

double	hit_triangle(t_triangle *tr, t_ray *ray)
{
	
}

void		set_inter_tr(t_triangle tr, t_ray ray, t_intersect *inter)
{
	
}
*/