#include "utils.h"

void	write_color(t_mlx *app, t_vec c)
{
	int ir = 255.999 * c.x;
	int ig = 255.999 * c.y;
	int ib = 255.999 * c.z;

	app->color.x = ir * 256 * 256;
	app->color.y = ig * 256;
	app->color.z = ib;
	app->int_color = app->color.x + app->color.y + app->color.z;
}