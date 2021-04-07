#include "structures.h"
#include "utils.h"

int	hit_sphere(t_vec center, double radius, t_vec origin, t_vec direction)
{
	t_vec oc = vminus(origin, center);
	float a = vdot(direction, direction);
	float b = 2.0 * vdot(oc, direction);
	float c = vdot(oc, oc) - radius * radius;
	float discriminant = b * b - 4 * a * c;
	return (discriminant > 0 ? 1 : 0);
}