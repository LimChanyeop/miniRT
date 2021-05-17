#include "utils.h"

t_ambients		make_ambients(double ratio, t_color rgb)
{
	t_ambients	ambients;

	if (light_validation(ratio) < 0)
		report_error(4);
	if (rgb_validation(rgb) < 0)
		report_error(2);
	ambients.ratio = ratio;
	ambients.color = color(rgb.x, rgb.y, rgb.z);
	ambients.check_in = 1;
	return (ambients);
}
