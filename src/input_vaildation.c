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
