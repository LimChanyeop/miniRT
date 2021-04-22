#include "utils.h"

t_plane	make_plane(t_point point1, t_point point2, t_color color)
{
	t_plane plane;

	plane.point1 = point1;
	plane.point2 = point2;
	plane.color = color;
	return (plane);
}