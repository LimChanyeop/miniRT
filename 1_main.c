#include <stdio.h>
#include "mlx.h"
#include "utils.h"
#include "libft.h"
//교점을 구해야 함 -> hit_도형 함수 리턴인자로 교점 받음 (안에서 가장 가까운 교점 판별해서 리턴) / 1. make mlx -> scene- > mlx 구조체로 // <구 2개로 >2. 교점 구하기  3. 교점에 해당하는 색깔 //
void	init_scene(t_scene *scene)
{
	scene->viewport.check_in = 0;
	scene->ambients.check_in = 0;
	scene->camera.check_in = 0;
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
	scene = (t_scene *)malloc(sizeof(t_scene));
	if (!(argc == 2 || ((argc == 3) && !ft_strncmp(argv[2], "--save\0", 7))))
		report_error(6);
	fd = open(argv[1], O_RDONLY);
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
	mlx = mlx_initiation(scene);

	int			i;
	int			j = 0;
	float		viewport_height = 2.0;
	float		viewport_width = scene->viewport.aspect_ratio * viewport_height;
	float		focal_length = 1.0;

	t_vec		horizontal = {viewport_height, 0, 0};
	t_vec		vertical = {0,  viewport_width, 0};
	t_vec		any = {0, 0, -focal_length};
	t_vec		lower_left_corner = vminus( vplus( vplus( vdivide(horizontal, -2), vdivide(vertical, -2)), any), scene->camera.orig);

	while (j < scene->viewport.height)
	{
		i = 0;
		while (i < scene->viewport.width)
		{
			float u = (double)i / (scene->viewport.height - 1);
			float v = (double)j / (scene->viewport.width - 1);

			t_vec a = scene->camera.orig;
			t_vec b = vplus(lower_left_corner, vplus(vmult_(horizontal, u), vmult_(vminus(vertical, scene->camera.orig), v)));
			t_vec pixel_color = ray_color(a, b);
			write_color(mlx, pixel_color);
			mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, i, j, mlx->int_color);
			++i;
		}
		++j;
	}
	mlx_loop(mlx->mlx_ptr);
	printf("rt file validation successfully finished !\n");
}
