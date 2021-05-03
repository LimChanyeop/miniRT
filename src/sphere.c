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

t_bool		t_sp_validation(double t, t_intersect *inter)
{
	if (t > inter->t_min && t < inter->t_max)
	{
		inter->t = t;
		inter->t_max = t;
		return (TRUE);
	}
	else
	{
		return (FALSE);
	}
	
}

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
		return ((-b - sqrt(discriminant)) / (2.0 * a));
}
