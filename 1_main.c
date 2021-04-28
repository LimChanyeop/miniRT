#include <stdio.h>
#include "mlx.h"
#include "utils.h"
#include "libft.h"

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
	mlx_loop(mlx->mlx_ptr);
	printf("rt file validation successfully finished !\n");
}
