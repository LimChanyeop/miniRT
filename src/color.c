#include "utils.h"

void	write_color(t_mlx *mlx, t_vec c)
{
	int ir = 255.999 * c.x;
	int ig = 255.999 * c.y;
	int ib = 255.999 * c.z;

	mlx->color.x = ir << 16;
	mlx->color.y = ig << 8;
	mlx->color.z = ib;
	mlx->int_color = mlx->color.x + mlx->color.y + mlx->color.z;
}