#include "utils.h"

t_ambients	make_ambients(double ratio, t_color color)
{
	t_ambients ambients;

	if (light_validation(ratio) < 0)
		report_error(4);
	if (rgb_validation(color) < 0)
		report_error(2);
	ambients.ratio = ratio;
	ambients.r = color.x;
	ambients.g = color.y;
	ambients.b = color.z;
	ambients.check_in = 1;
	return (ambients);
}