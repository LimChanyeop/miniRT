#include "utils.h"

double	hit_sphere(t_sphere *sp, t_ray *ray)
{
	t_vec oc;
	double a;
	double b;
	double c;
	double discriminant;
	
	oc = vminus(ray->orig, sp->center);
	a = vdot(ray->dir, ray->dir);
	b = 2.0 * vdot(oc, ray->dir);
	c = vdot(oc, oc) - sp->radius2;
	discriminant = b * b - 4 * a * c;
	if (discriminant < 0)
		return (-1.0);
	else
		return ((-b - sqrt(discriminant)) / (2.0 * a)); //가까운 t
}
