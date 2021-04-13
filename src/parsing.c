static void		parse(t_minilibx *mlx, t_scene *data, t_lstobject **lst, char **line)
{
    char *str;

    str = *line;
    if (*str == 'R')
		parse_resoultion(data, &str);
	else if (*str == 'A')
		parse_ambient_light(data, &str);
	else if (*str == 'c')
		parse_camera(mlx, data, &str);
    else if (*str == 'l')
		parse_light(&data, &str);
    else if (*str == 'p' && *(str + 1) == 'l')
		parse_plane(lst, &str);
    else if (*str == 's' && *(str + 1) == 'p')
		parse_sphere(lst, &str); 
    else if (*str == 's' && *(str + 1) == 'q')
		parse_square(lst, &str);
	else if (*str == 'c' && *(str + 1) == 'y')
		parse_cylinder(lst, &str);
	else if (*str == 't' && *(str + 1) == 'r')
		parse_triangle(lst, &str);
}

void parse_resolution(t_scene *data, char **str)
{
    
}