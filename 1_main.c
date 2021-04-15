#include <stdio.h>
#include "mlx.h"
#include "./includes/utils.h"
#include "./includes/libft.h"

int	main(int argc, char *argv[])
{
	int			fd;
	t_scene		scene;

	fd = open(argv[1], O_RDONLY);
	while(get_next_line(fd, &line) > 0)
		parse(&scene, &line);

}
