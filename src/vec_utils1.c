#include "utils.h"

t_vec	vec(double x, double y, double z)
{
	t_vec vec;

	vec.x = x;
	vec.y = y;
	vec.z = z;
	return (vec);
}

t_point point(double x, double y, double z)
{
	t_vec point;

	point.x = x;
	point.y = y;
	point.z = z;
	return (point);
}

t_color color(double r, double g, double b)
{
	t_color color;

	color.x = r;
	color.y = g;
	color.z = b;
	return (color);
}

double	vlength2(t_vec vec)
{
	return (vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
}

double	vlength(t_vec vec)
{
	return (sqrt(vlength2(vec)));
}
