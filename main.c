/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clim <clim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 13:53:48 by clim              #+#    #+#             */
/*   Updated: 2021/05/18 13:54:34 by clim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "utils.h"
#include "libft.h"

void		set_camera(t_scene *scene)
{
	t_list	*cam;

	cam = ft_lstlast(scene->camera);
	cam->next = scene->camera;
	scene->cam_selected = (t_camera *)malloc(sizeof(t_camera));
	scene->cam_selected = (t_camera *)scene->camera->content;
}

int			main(int argc, char *argv[])
{
	int			fd;
	t_scene		*scene;

	if (check_file_format(argc, argv) == -1)
		report_error(6);
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		report_error(9);
	scene = parse_rt(fd);
	set_camera(scene);
	scene->mlx = mlx_initiation(scene);
	start_mlx(scene);
	if (argc == 3)
		make_bmp(scene);
	mlx_key_hook(scene->mlx->win_ptr, handle_event, scene);
	mlx_hook(scene->mlx->win_ptr, 17, 1L << 17, exit_program, 0);
	mlx_loop(scene->mlx->mlx_ptr);
	return (0);
}
