#include "utils.h"

int			handle_event(int key, t_scene *scene)
{
	if (key != 53)
	{
		scene->camera = scene->camera->next;
		scene->cam_selected = (t_camera *)scene->camera->content;
		start_mlx(scene);
	}
	if (key == 53)
	{
		exit(1);
		return (0);
	}
	return (0);
}
