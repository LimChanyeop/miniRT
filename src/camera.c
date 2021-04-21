#include "utils.h"

t_camera make_camera(t_point point, t_vec vec, int angle)
{
	t_camera camera;

	camera.orig = point;
	camera.vec = vec;
	camera.angle = angle;
	return (camera);
}