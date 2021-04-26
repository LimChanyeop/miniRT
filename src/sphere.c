#include "utils.h"

t_sphere	sphere(t_point center, double radius)
{
	t_sphere sp;

	sp.center = center;
	sp.radius = radius;
	sp.radius2 = radius * radius;
	return (sp);
}

t_sphere	make_sphere(t_point point, double diameter, t_color color)
{
	t_sphere sphere;

	if (rgb_validation(color) < 0)
		report_error(2);
	if (check_positive(diameter) < 0)
		report_error(5);
	sphere.center = point;
	sphere.radius = (double)diameter;
	sphere.radius2 = sphere.radius * sphere.radius; 
	sphere.color = color;
	return (sphere);
}