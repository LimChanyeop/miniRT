#include "utils.h"

t_canvas		make_canvas(int width, int height)
{
	t_canvas	canvas;

	if (check_positive((double)width) < 0)
		report_error(5);
	if (check_positive((double)height) < 0)
		report_error(5);
	canvas.width = width;
	canvas.height = height;
	canvas.aspect_ratio = (double)height / (double)width;
	canvas.check_in = 1;
	return (canvas);
}