#include <stdio.h>
#include "mlx.h"
#include "utils.h"
#include "libft.h"

void	init_scene(t_scene *scene)
{
	printf("SDADAS\n");
	scene->viewport.width = -1;
	scene->viewport.height = -1;
	printf("SDADAS\n");
}

int	main(int argc, char *argv[])
{
	int			fd;
	t_scene		*scene;
	char		*line = 0;
	printf("fd = 1\n");
	scene = (t_scene *)malloc(sizeof(t_scene));
	if (argc != 2)
		return (-1);
	fd = open(argv[1], O_RDONLY);
	printf("fd = %d\n", fd);
	init_scene(scene);
	printf("fd = %d\n", fd);
	while(get_next_line(fd, &line) > 0)
		parse(scene, line);
	printf("fd = %d\n", fd);

}
