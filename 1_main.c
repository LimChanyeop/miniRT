#include <stdio.h>
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

	if (!((argc == 2 && check_file_format(argv[1])) || \
			((argc == 3 && !ft_strncmp(argv[2], "--save\0", 7)))))
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
	mlx_loop(scene->mlx->mlx_ptr);
	return (0);
}

void		make_bmp(t_scene *scene)
{
	int			bmp_fd;
	char		*data;
	
	data = malloc(sizeof(char) * (54 + scene->viewport.height * \
				scene->viewport.width * 4 + 1));
	bmp_fd = open("miniRT.bmp", O_TRUNC | O_RDWR | O_CREAT);
	make_bmp_header(&data, scene);
	fill_bmp(&data, scene);
	write(bmp_fd, data, (54 + scene->viewport.height * \
				scene->viewport.width * 4 + 1));
	exit(0);
}