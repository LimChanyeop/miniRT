#include "utils.h"

t_light	make_light(t_point point, double ratio, t_color color)
{
	t_light light;

	light.point = point;
	light.ratio = ratio;
	light.color = color;
	return (light);
}