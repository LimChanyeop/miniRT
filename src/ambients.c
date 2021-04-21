#include "utils.h"

t_ambients	make_ambients(float ratio, t_color color)
{
	t_ambients ambients;

	ambients.ratio = ratio;
	ambients.r = color.x;
	ambients.g = color.y;
	ambients.b = color.z;
	return (ambients);
}