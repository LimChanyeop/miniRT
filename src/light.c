#include "utils.h"

t_light	make_light(t_vec point, double brightness, t_color color)
{
	t_light light;

	if (light_validation(brightness) < 0)
		report_error(4);
	if (rgb_validation(color) < 0)
		report_error(2);
	light.point = point;
	light.brightness = brightness;
	light.color = color;
	return (light);
}