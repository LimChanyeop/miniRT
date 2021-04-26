#include "utils.h"

t_cylinder make_cylinder(t_point point, t_vec vec, int radius, int height, t_color color) // - 들어오면 에러처리 / exit 사용하여  에러처리
{
	t_cylinder cylinder;

	if (vector_validation(vec) < 0)
		report_error(1);
	if (rgb_validation(color) < 0)
		report_error(2);
	cylinder.point = point;
	cylinder.vec = vec;
	cylinder.radius = (double)radius;
	cylinder.height = (double)height;
	cylinder.color = color; // RGB 범위에 있는지 확인 -> error -> exit
	return (cylinder);
}