#include "utils.h"

int         have_necessary_input(t_scene *scene)
{
	if (scene->viewport.check_in == 0)
		return (-1);
    else if (scene->ambients.check_in == 0)
        return (-1);
    else if (scene->camera == 0)
        return (-1);
    else
        return (0);
}

int		check_file_format(char *str)
{
	while (str)
	{
		if (*str == '.')
		{
			if (str[1] == 'r' && str[2] == 't' && !str[3])
				return (-1);
		}
		str++;
	}
	return (0);
}