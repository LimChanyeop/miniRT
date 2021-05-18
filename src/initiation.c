/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clim <clim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 13:46:06 by clim              #+#    #+#             */
/*   Updated: 2021/05/18 13:46:08 by clim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "mlx.h"

t_mlx			*mlx_initiation(t_scene *scene)
{
	t_mlx		*mlx;

	if (!(mlx = (t_mlx *)malloc(sizeof(t_mlx))))
		return (0);
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, \
		scene->viewport.width, scene->viewport.height, "miniRT");
	mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, \
		scene->viewport.width, scene->viewport.height);
	mlx->data = (int *)mlx_get_data_addr(mlx->img_ptr, \
		&mlx->bpp, &mlx->size_l, &mlx->endian);
	return (mlx);
}

void			init_scene(t_scene *scene)
{
	scene->res_in = 0;
	scene->amb_in = 0;
	scene->cam_in = 0;
	scene->cam_selected = 0;
	scene->camera = 0;
	scene->sphere = 0;
	scene->square = 0;
	scene->cylinder = 0;
	scene->plane = 0;
	scene->triangle = 0;
	scene->light = 0;
}
