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
	t_light 	*temp;

	scene = (t_scene *)malloc(sizeof(t_scene));
	if (argc != 2)
		return (-1);
	fd = open(argv[1], O_RDONLY);
	init_scene(scene);
	while(get_next_line(fd, &line) > 0)
	{
		if(parse(scene, line) < 0)
			printf("RT file LINE ERROR\n");
		free(line);
	}
	temp = scene->light->content;
	printf("sp list size = %d\n", ft_lstsize(scene->sphere));
	printf("sq list size = %d\n", ft_lstsize(scene->square));
	printf("cy list size = %d\n", ft_lstsize(scene->cylinder));
	printf("tr list size = %d\n", ft_lstsize(scene->triangle));
	printf("pl list size = %d\n", ft_lstsize(scene->plane));
	printf("li list size = %d\n", ft_lstsize(scene->light));
	printf("contents = %f\n", temp->point.z);
	//printf("main test = %f\n", scene->ambients.ratio);
}
