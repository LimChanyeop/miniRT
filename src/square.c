#include "utils.h"
// 방향벡터 0 x
t_square	make_square(t_point center, t_vec vec, double radius, t_color color)
{
	t_square square;

	if (vector_validation(vec) < 0)
		report_error(1);
	if (rgb_validation(color) < 0)
		report_error(2);
	if (check_positive(radius) < 0)
		report_error(5);
	square.center = center;
	square.vec = vec;
	square.radius = radius;
	square.color = color;
	return (square);
}

t_bool		t_sq_validation(double t, t_intersect *inter)
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

double	hit_square(t_square *sq, t_ray *ray)
{
	double	denominator;
	t_vec	r0_p0; // ray origin to plane point p
	double	root;
	t_point point;

	denominator = vdot(sq->vec, ray->dir);
	if (fabs(denominator) < EPSILON) // 분모가 거의 0이면! = 평면과 직선은 평행
		return (-1);
	r0_p0 = vminus(sq->center, ray->orig);
	root = vdot(r0_p0, sq->vec) / denominator;
	point = vminus(vplus(ray->orig, vmult_(ray->dir, root)), sq->center);
	if (fabs(point.x) < sq->radius/2 && fabs(point.y) < sq->radius/2 && fabs(point.z) < sq->radius/2)
		return (root);
	else
		return (-1);
}

void		set_inter_sq(t_square sq, t_ray ray, t_intersect *inter)
{
	inter->point = vplus(ray.orig, vmult_(ray.dir, inter->t));
	inter->normal_vec = sq.vec;
	inter->albedo = sq.color;
}
