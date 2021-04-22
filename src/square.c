#include "utils.h"
// 방향벡터 0 x
t_square	make_square(t_point point1, t_point point2, int radius, t_color color)
{
	t_square square;

	square.point1 = point1;
	square.point2 = point2;
	square.radius = radius;
	square.color = color;
	return (square);
}