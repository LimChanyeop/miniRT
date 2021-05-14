#include <stdio.h>
#include "mlx.h"
#include "utils.h"
#include "libft.h"


void	init_scene(t_scene *scene)
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
	printf("%p\n",(t_camera *)scene->camera->next->content);
	if (key != 53)
	{
		scene->camera = scene->camera->next;
		scene->cam_selected = (t_camera *)scene->camera->content;
		printf("%p\n", scene->cam_selected);
		start_mlx(scene);
	}
	if (key == 53)
		exit_program();
	return (0);
}

t_mlx 				*start_mlx(t_scene *scene)
{
	float		fl_wi_hi[3];
	t_vec		cn_lc_ve_ho[4];
	
	printf("12\n");
	fl_wi_hi[0] = 1.0;
	printf("%d\n", scene->cam_selected->angle);
	fl_wi_hi[1] = 2.0 * fl_wi_hi[0] * tan(scene->cam_selected->angle * 0.5 * PI / 180);
	printf("56\n");
	fl_wi_hi[2] = fl_wi_hi[1] * scene->viewport.aspect_ratio;
	cn_lc_ve_ho[3] = vcross(vec(0,1,0), scene->cam_selected->vec);
	if (vector_validation(cn_lc_ve_ho[3]) == 0)
		cn_lc_ve_ho[2] = vunit(vcross(scene->cam_selected->vec, cn_lc_ve_ho[3]));
	else
	{
		cn_lc_ve_ho[2] = vunit(vcross(scene->cam_selected->vec, vec(1,0,0)));
		cn_lc_ve_ho[3] = vunit(vcross(cn_lc_ve_ho[2], scene->cam_selected->vec));
	}
	printf("78\n");
	cn_lc_ve_ho[3] = vmult_(cn_lc_ve_ho[3], fl_wi_hi[1]);
	cn_lc_ve_ho[2] = vmult_(cn_lc_ve_ho[2], fl_wi_hi[2]);
	cn_lc_ve_ho[0] = ray_at(new_ray(scene->cam_selected->orig, scene->cam_selected->vec), fl_wi_hi[0]);
	cn_lc_ve_ho[1] = vminus(vminus(vminus(cn_lc_ve_ho[0], vdivide(cn_lc_ve_ho[3], 2)), \
						vdivide(cn_lc_ve_ho[2], 2)), scene->cam_selected->orig);
	return(mlx_draw(scene, scene->cam_selected, cn_lc_ve_ho));
}

int	main(int argc, char *argv[])
{
	int			fd;
	t_scene		*scene;
	t_list *cam;

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

int		exit_program(void)
{
	exit(0);
	return (0);
}