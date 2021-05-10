#include <stdio.h>
#include "mlx.h"
#include "utils.h"
#include "libft.h"
#include <math.h>
//교점을 구해야 함 -> hit_도형 함수 리턴인자로 교점 받음 (안에서 가장 가까운 교점 판별해서 리턴)// 1. make mlx -> scene- > mlx 구조체로 // <구 2개로 > 2. 교점 구하기  3. 교점에 해당하는 색깔//
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

int	main(int argc, char *argv[])
{
	int			fd;
	t_scene		*scene;
	char		*line = 0;
	t_mlx		*mlx;

	if (!(argc == 2 || ((argc == 3) && !ft_strncmp(argv[2], "--save\0", 7))))
		report_error(6);//.rt ?
	fd = open(argv[1], O_RDONLY);
	
	/* parse RT file */
	
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
	
	/* mlx setting */

	t_camera *camera;

	camera = scene->camera->content;
	mlx = mlx_initiation(scene);
	float		focal_length = 1.0;
	float		viewport_width = 2.0 * focal_length * tan(camera->angle * 0.5 * PI / 180);
	float		viewport_height = viewport_width * scene->viewport.aspect_ratio;
	t_point		center;
	t_point		lower_left_corner;
	t_vec		vertical;
	t_vec		horizontal;
	int			i;
	int			j;

	horizontal = vcross(vec(0,1,0), camera->vec);
	printf("1\n");
	if (vector_validation(horizontal) == 0)
		vertical = vunit(vcross(camera->vec, horizontal));
	else
	{
		vertical = vunit(vcross(camera->vec, vec(1,0,0)));
		horizontal = vunit(vcross(vertical, camera->vec));
	}
	printf("2\n");
	horizontal = vmult_(horizontal, viewport_width);
	printf("3\n");
	vertical = vmult_(vertical, viewport_height);
	printf("4\n");
	center = ray_at(new_ray(camera->orig, camera->vec), focal_length);
	printf("5\n");
	lower_left_corner = vminus(vminus(vminus(center, vdivide(horizontal, 2)), vdivide(vertical, 2)), camera->orig);

	j = 0;
	while (j < scene->viewport.height)
	{
		i = 0;
		while (i < scene->viewport.width)
		{
			double u = (scene->viewport.height - 1 - (double)j) / (scene->viewport.height - 1);
			double v = (scene->viewport.width - 1 -(double)i) / (scene->viewport.width - 1);

			t_vec a = camera->orig;
			t_vec b = vplus(lower_left_corner, vplus(vmult_(horizontal, v), vmult_(vertical, u)));
			t_vec pixel_color = ray_color((new_ray(a, vunit(b))), scene);
			write_color(mlx, pixel_color);
			mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, i, j, mlx->int_color);
			++i;
		}
		++j;
	}
	mlx_loop(mlx->mlx_ptr);
}
