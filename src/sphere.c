#include "utils.h"

t_sphere	sphere(t_point center, double radius)
{
	t_sphere sp;

	sp.center = center;
	sp.radius = radius;
	sp.radius2 = radius * radius;
	return (sp);
}

t_sphere	make_sphere(t_point point, int diameter, t_color color)
{
	t_sphere sphere;

	sphere.center = point;
	sphere.radius = (double)diameter;
	sphere.color = color;
	return (sphere);
}