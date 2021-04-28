#include "utils.h"
#include "mlx.h"

t_mlx       *mlx_initiation(t_scene *scene)
{
    t_mlx		*mlx;

	if (!(mlx = (t_mlx*)malloc(sizeof(t_mlx))))
		return (0);
    mlx->mlx_ptr = mlx_init();
    mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, scene->viewport.width, scene->viewport.height, "miniRT");
    mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, scene->viewport.width, scene->viewport.height);
    mlx->data = (int *)mlx_get_data_addr(mlx->img_ptr, &mlx->bpp, &mlx->size_l, &mlx->endian);
    return (mlx);
}