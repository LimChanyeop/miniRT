#include "utils.h"

t_cylinder make_cylinder(t_point point1, t_point point2, int radius, int height, t_color color) // - 들어오면 에러처리 / exit 사용하여  에러처리
{
	t_cylinder cylinder;

	cylinder.point1 = point1;
	cylinder.point2 = point2;
	cylinder.radius = (double)radius;
	cylinder.height = (double)height;
	cylinder.color = color; // RGB 범위에 있는지 확인 -> error -> exit
	return (cylinder);
}