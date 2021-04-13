#include "utils.h"

t_sphere	sphere(t_point center, double radius)
{
	t_sphere sp;

	sp.center = center;
	sp.radius = radius;
	sp.radius2 = radius * radius;
	return (sp);
}