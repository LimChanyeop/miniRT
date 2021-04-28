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