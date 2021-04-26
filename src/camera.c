#include "utils.h"

t_camera make_camera(t_vec point, t_vec vec, int angle)
{
	t_camera camera;

	if (vector_validation(vec) < 0)
		report_error(1);
	if (angle_validation(angle) < 0)
		report_error(3);
	camera.orig = point;
	camera.vec = vec;
	camera.angle = angle;

	return (camera);
}