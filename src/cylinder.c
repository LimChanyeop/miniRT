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