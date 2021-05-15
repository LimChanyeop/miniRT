#include <stdio.h>
#include "mlx.h"
#include "utils.h"
#include "libft.h"

t_mlx 			*mlx_draw(t_scene *scene, t_camera *camera, t_vec *cn_lc_ve_ho)
{
	int i;
	int j;
	t_vec a_b[2];
	t_color pixel_color;
	double u_v[2];

	j = 0;
	while (j < scene->viewport.height)
	{
		i = 0;
		while (i < scene->viewport.width)
		{
			u_v[0] = (scene->viewport.height - 1 - (double)j) / (scene->viewport.height - 1);
			u_v[1] = (scene->viewport.width - 1 -(double)i) / (scene->viewport.width - 1);
			a_b[0] = camera->orig;
			a_b[1] = vplus(cn_lc_ve_ho[1], vplus(vmult_(cn_lc_ve_ho[3], u_v[1]), vmult_(cn_lc_ve_ho[2], u_v[0])));
			pixel_color = ray_color((new_ray(a_b[0], vunit(a_b[1]))), scene);
			write_color(scene->mlx, pixel_color);
			mlx_pixel_put(scene->mlx->mlx_ptr, scene->mlx->win_ptr, i, j, scene->mlx->int_color);
			++i;
		}
		++j;
	}
	return (scene->mlx);
}

int					handle_event(int key, t_scene *scene)
{
	if (key != 53)
	{
		scene->camera = scene->camera->next;
		scene->cam_selected = (t_camera *)scene->camera->content;
		start_mlx(scene);
	}
	if (key == 53)
	{
		exit(1);
		return (0);
	}
	return (0);
}

t_mlx 				*start_mlx(t_scene *scene)
{
	float		fl_wi_hi[3];
	t_vec		cn_lc_ve_ho[4];
	t_camera	*cam;

	cam = scene->cam_selected;
	fl_wi_hi[0] = 1.0;
	fl_wi_hi[1] = 2.0 * fl_wi_hi[0] * tan(cam->angle * 0.5 * PI / 180);
	fl_wi_hi[2] = fl_wi_hi[1] * scene->viewport.aspect_ratio;
	cn_lc_ve_ho[3] = vcross(vec(0,1,0), cam->vec);
	if (vector_validation(cn_lc_ve_ho[3]) == 0)
		cn_lc_ve_ho[2] = vunit(vcross(cam->vec, cn_lc_ve_ho[3]));
	else
	{
		cn_lc_ve_ho[2] = vunit(vcross(cam->vec, vec(1,0,0)));
		cn_lc_ve_ho[3] = vunit(vcross(cn_lc_ve_ho[2], cam->vec));
	}
	cn_lc_ve_ho[3] = vmult_(cn_lc_ve_ho[3], fl_wi_hi[1]);
	cn_lc_ve_ho[2] = vmult_(cn_lc_ve_ho[2], fl_wi_hi[2]);
	cn_lc_ve_ho[0] = ray_at(new_ray(cam->orig, cam->vec), fl_wi_hi[0]);
	cn_lc_ve_ho[1] = vminus(vminus(vminus(cn_lc_ve_ho[0], vdivide(cn_lc_ve_ho[3], 2)), \
						vdivide(cn_lc_ve_ho[2], 2)), cam->orig);
	return(mlx_draw(scene, cam, cn_lc_ve_ho));
}

int	main(int argc, char *argv[])
{
	int			fd;
	t_scene		*scene;
	t_list 		*cam;

	if (!(argc == 2 && check_file_format(argv[1])) \
			|| ((argc == 3) && !ft_strncmp(argv[2], "--save\0", 7)))
		report_error(6);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		report_error(6);
	scene = parse_rt(fd);
	cam = ft_lstlast(scene->camera);
	cam->next = scene->camera;
	scene->cam_selected = (t_camera *)malloc(sizeof(t_camera));
	scene->cam_selected = (t_camera *)scene->camera->content;
	scene->mlx = mlx_initiation(scene);
	start_mlx(scene);
	mlx_key_hook(scene->mlx->win_ptr, handle_event, scene);
	mlx_loop(scene->mlx->mlx_ptr);
	return (0);
}

t_scene 	*parse_rt(int fd)
{
	char		*line;
	t_scene		*scene;

	line = 0;
	scene = (t_scene *)malloc(sizeof(t_scene));
	init_scene(scene);
	while(get_next_line(fd, &line) > 0)
	{
		if (parse(scene, line) < 0)
		{
			printf("line Error in %s\n", line);
			report_error(8);
		}
		free(line);
	}
	if (parse(scene, line) < 0)
		report_error(8);
	free(line);
	if (have_necessary_input(scene) < 0)
		report_error(7);
	printf("rt file validation successfully finished !\n");
	return (scene);
}