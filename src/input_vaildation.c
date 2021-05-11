#include "utils.h"

int         vector_validation(t_vec vec)
{
    if (vec.x == 0 && vec.y == 0 && vec.z == 0)
        return (-1);
    else
        return (0);
}

int         rgb_validation(t_color color)
{
    if (color.x > 255 || color.y > 255 || color.z > 255)
        return (-1);
    else if (color .x < 0 || color.y < 0 || color.z < 0)
        return (-1);
    else
        return (0);
}

int         angle_validation(double angle)
{
    if (angle >= 180 || angle <= 0)
        return (-1);
    else
        return (0);
}

int         light_validation(double brightness)
{
    if (brightness < 0 || brightness > 1)
        return (-1);
    else
        return (0);
}

int         check_positive(double num)
{
    if (num < 0)
        return (-1);
    else
        return (0);
}

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
	while(str)
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