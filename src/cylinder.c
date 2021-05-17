#include "utils.h"

t_cylinder 		make_cylinder(t_point center, t_vec vec, double radius, double height, t_color color)
{
	t_cylinder	cylinder;

	if (vector_validation(vec) < 0)
		report_error(1);
	if (rgb_validation(color) < 0)
		report_error(2);
	cylinder.center = center;
	cylinder.vec = vec;
	cylinder.radius = radius;
	cylinder.height = height;
	cylinder.color = color;
	return (cylinder);
}

t_bool			t_cy_validation(double t, t_intersect *inter)
{
	if (t > inter->t_min && t < inter->t_max)
	{
		inter->t = t;
		inter->t_max = t;
		return (TRUE);
	}
	else
		return (FALSE);
}

double			hit_cylinder(t_cylinder *cy, t_ray *ray, t_bool *in)
{
	double a_b_c[3];
	double det;
	double root[2];

	*in = FALSE;
	a_b_c[0] = vlength2(vunit(ray->dir)) - pow(vdot(vunit(ray->dir), vunit(cy->vec)), 2);
	a_b_c[1] = 2 * (vdot(vunit(ray->dir), vminus(ray->orig, cy->center)) - (vdot(vunit(ray->dir),vunit(cy->vec)) * vdot(vminus(ray->orig, cy->center), vunit(cy->vec))));
	a_b_c[2] = vlength2(vminus(ray->orig, cy->center)) - pow(vdot(vminus(ray->orig, cy->center),vunit(cy->vec)),2) - pow(cy->radius, 2);
	det = pow(a_b_c[1],2) - 4 * a_b_c[0] * a_b_c[2];
	root[0] = (-a_b_c[1] - sqrt(det)) / (2.0 * a_b_c[0]);
	root[1] = (-a_b_c[1] + sqrt(det)) / (2.0 * a_b_c[0]);
	if (det < 0)
		return (-1.0);
	else
		return (hit_cylinder2(cy, ray, in, root));
}

double		hit_cylinder2(t_cylinder *cy, t_ray *ray, t_bool *in, double *root)
{
	if (fabs(vdot(vunit(cy->vec), vminus(vplus(ray->orig, vmult_(ray->dir, \
			root[0])), cy->center))) > cy->height / 2)//가까운 근이 범위 초과
	{	
		if (fabs(vdot(vunit(cy->vec), vminus(vplus(ray->orig, vmult_(ray->dir, \
				root[1])), cy->center))) > cy->height / 2)//먼 근이 범위 초과
			return (-1);
		else
		{
			*in = TRUE;
			return (root[1]);
		}
	}
	else
	{
		if (root[0] < EPSILON)
		{
			if (fabs(vdot(vunit(cy->vec), vminus(vplus(ray->orig, \
				vmult_(ray->dir, root[1])), cy->center))) > cy->height / 2)
				return (-1);
			*in = TRUE;
			return (root[1]);
		}
		else
			return (root[0]);
	}
}

void		set_inter_cy(t_cylinder cy, t_ray ray, t_intersect *inter, t_bool in)
{
	inter->point = vplus(ray.orig, vmult_(ray.dir, inter->t));
	inter->normal_vec = vunit(vminus(vminus(inter->point, cy.center), vmult_(vunit(cy.vec), vdot(vminus(inter->point, cy.center), vunit(cy.vec)))));
	inter->albedo = cy.color;
	if (in)
		inter->normal_vec = vmult_(inter->normal_vec, -1);
}
