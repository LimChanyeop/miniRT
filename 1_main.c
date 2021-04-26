#include <stdio.h>
#include "mlx.h"
#include "utils.h"
#include "libft.h"

void	init_scene(t_scene *scene)
{
	scene->viewport.width = -1;
	scene->viewport.height = -1;
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
	t_sphere  *cy;

	scene = (t_scene *)malloc(sizeof(t_scene));
	if (!(argc == 2 || ((argc == 3) && !ft_strncmp(argv[2], "--save\0", 7))))
		report_error(6);
	fd = open(argv[1], O_RDONLY);
	init_scene(scene);
	while(get_next_line(fd, &line) > 0)
	{
		if(parse(scene, line) < 0)
			printf("RT file LINE ERROR in %s\n ", line);
		free(line);
	}
	if(parse(scene, line) < 0)
		printf("RT file LINE ERROR in %s\n ", line);
	free(line);
	cy = scene->sphere->content;
	printf("sp radius  contents -> %f %f\n", cy->radius, cy->radius2);

	// R, A, c 적절하게 들어왓는지 확인
}
