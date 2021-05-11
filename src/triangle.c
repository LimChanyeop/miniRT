#include "utils.h"

t_triangle	make_triangle(t_point point1, t_point point2, t_point point3, t_color color)
{
	t_triangle triangle;

	if (rgb_validation(color) < 0)
		report_error(2);
	triangle.point1 = point1;
	triangle.point2 = point2;
	triangle.point3 = point3;
	triangle.color = color;
	return (triangle);
}
/*
t_bool		t_tr_validation(double t, t_intersect *inter)
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

double	hit_triangle(t_triangle *tr, t_ray *ray)
{
	float			denom;
	float			b;
	float			t;

	t = 0;
	denom = -(vdot(tr->normal, *object->a));
	object->calcul_a = vdot(ray->orig, *object->normal) + denom;
	object->prev_origin = cpy_vector(ray->orig);
	b = product_vectors(ray->dir, *object->normal);
	t = -(object->calcul_a / b);
	if (t <= 0)
		return (0);
	return (intersect_triangle2(t, ray, object));
}

void		set_inter_tr(t_triangle tr, t_ray ray, t_intersect *inter)
{
	
}

float		intersect_triangle2(float t, t_ray *ray, t_triangle *object)
{
	t_vec		*temp;
	t_vec		*point;
	float			dot_wv_wu[2];
	t_vec		*w;
	float			r[2];

	temp = multiply_vectors(t, direction);
	point = add_vectors(origin, *temp);
	free(temp);
	w = subtract_vectors(*point, *object->a);
	dot_wv_wu[0] = product_vectors(*w, *object->u);
	dot_wv_wu[1] = product_vectors(*w, *object->v);
	r[0] = (object->dot_uv * dot_wv_wu[1] - object->dot_vv *
dot_wv_wu[0]) / object->calcul_d;
	free(w);
	if (r[0] < 0 || r[0] > 1)
		return (0);
	r[1] = (object->dot_uv * dot_wv_wu[0] - object->dot_uu *
dot_wv_wu[1]) / object->calcul_d;
	if (r[1] < 0 || (r[0] + r[1] > 1))
		return (0);
	return (t);
}

float		intersect_triangle(t_vec origin, t_vector direction,
t_triangle *object)
{
	float			denom;
	float			b;
	float			t;

	t = 0;
	if (!object->prev_origin || !is_equal(object->prev_origin, &origin))
	{
		if (object->prev_origin)
			free(object->prev_origin);
		denom = -(product_vectors(*object->normal, *object->a));
		object->calcul_a = product_vectors(origin, *object->normal) + denom;
		object->prev_origin = cpy_vector(&origin);
	}
	b = product_vectors(direction, *object->normal);
	t = -(object->calcul_a / b);
	if (t <= 0)
		return (0);
	return (intersect_triangle2(t, origin, direction, object));
}
*/