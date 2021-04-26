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