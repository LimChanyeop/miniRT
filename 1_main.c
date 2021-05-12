#include <stdio.h>
#include "mlx.h"
#include "utils.h"
#include "libft.h"


void	init_scene(t_scene *scene)
{
	scene->viewport.check_in = 0;
	scene->ambients.check_in = 0;
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
	t_mlx *mlx;
	double u_v[2];

	mlx = mlx_initiation(scene);
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
			write_color(mlx, pixel_color);
			mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, i, j, mlx->int_color);
			++i;
		}
		++j;
	}
	return (mlx);
}

t_mlx 				*start_mlx(t_scene *scene, t_camera *camera)
{
	float		fl_wi_hi[3];
	t_vec		cn_lc_ve_ho[4];

	fl_wi_hi[0] = 1.0;
	fl_wi_hi[1] = 2.0 * fl_wi_hi[0] * tan(camera->angle * 0.5 * PI / 180);
	fl_wi_hi[2] = fl_wi_hi[1] * scene->viewport.aspect_ratio;
	cn_lc_ve_ho[3] = vcross(vec(0,1,0), camera->vec);
	if (vector_validation(cn_lc_ve_ho[3]) == 0)
		cn_lc_ve_ho[2] = vunit(vcross(camera->vec, cn_lc_ve_ho[3]));
	else
	{
		cn_lc_ve_ho[2] = vunit(vcross(camera->vec, vec(1,0,0)));
		cn_lc_ve_ho[3] = vunit(vcross(cn_lc_ve_ho[2], camera->vec));
	}
	cn_lc_ve_ho[3] = vmult_(cn_lc_ve_ho[3], fl_wi_hi[1]);
	cn_lc_ve_ho[2] = vmult_(cn_lc_ve_ho[2], fl_wi_hi[2]);
	cn_lc_ve_ho[0] = ray_at(new_ray(camera->orig, camera->vec), fl_wi_hi[0]);
	cn_lc_ve_ho[1] = vminus(vminus(vminus(cn_lc_ve_ho[0], vdivide(cn_lc_ve_ho[3], 2)), \
					vdivide(cn_lc_ve_ho[2], 2)), camera->orig);
	return(mlx_draw(scene, camera, cn_lc_ve_ho));
}

int	main(int argc, char *argv[])
{
	int			fd;
	t_scene		*scene;
	t_camera	*cam;
	t_mlx		*mlx;
	if (!(argc == 2 && check_file_format(argv[1])) \
			|| ((argc == 3) && !ft_strncmp(argv[2], "--save\0", 7)))
		report_error(6);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		report_error(6);
	scene = parse_rt(fd);
	cam = scene->camera->content;
	mlx = start_mlx(scene, cam);
	mlx_key_hook(mlx->win_ptr, exit_program, 0);
	mlx_hook(mlx->win_ptr, 17, 1L << 17, exit_program, 0);
	mlx_loop(mlx->mlx_ptr);
	return (0);
}

int		exit_program(void)
{
	exit(0);
	return (0);
}