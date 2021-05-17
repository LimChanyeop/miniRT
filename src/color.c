#include "utils.h"

void		write_color(t_mlx *mlx, t_vec c)
{
	int 	ir;
	int 	ig;
	int 	ib;

	ir = c.x * 255.999;
	ig= c.y * 255.999;
	ib = c.z * 255.999;
	mlx->color.x = ir << 16;
	mlx->color.y = ig << 8;
	mlx->color.z = ib;
	mlx->int_color = mlx->color.x + mlx->color.y + mlx->color.z;
}

t_color		color_to_rgb(t_color color)
{
	t_color ret_color;
	double 	ir;
	double 	ig;
	double 	ib;

	ir = color.x;
	ig= color.y;
	ib = color.z;
	ret_color.x =  ir / 255.999;
	ret_color.y  = ig / 255.999;
	ret_color.z  = ib / 255.999;
	if (ret_color.x > 1)
		ret_color.x = 1;
	if (ret_color.y > 1)
		ret_color.x = 1;
	if (ret_color.z > 1)
		ret_color.x = 1;
	return (ret_color);
}