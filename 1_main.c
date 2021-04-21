#include <stdio.h>
#include "mlx.h"
#include "utils.h"
#include "libft.h"

void	init_scene(t_scene *scene)
{
	scene->viewport.width = -1;
	scene->viewport.height = -1;
	scene->sphere = 0;
}

int	main(int argc, char *argv[])
{
	int			fd;
	t_scene		*scene;
	char		*line = 0;
	scene = (t_scene *)malloc(sizeof(t_scene));
	if (argc != 2)
		return (-1);
	fd = open(argv[1], O_RDONLY);
	init_scene(scene);
	while(get_next_line(fd, &line) > 0)
	{
		parse(scene, line);
		free(line);
	}
	//printf("main test = %f\n", scene->ambients.ratio);
}
