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