#include "libft.h"
#include "utils.h"
#include <stdio.h>


void		set_xyz_rgb(char *xr, char *yg, char *zb, t_vec *vec)
{
	int xyz[3];

	ft_atoi(xr, &xyz[0]);
	ft_atoi(yg, &xyz[1]);
	ft_atoi(zb, &xyz[2]);
	vec->x = (double)xyz[0];
	vec->y = (double)xyz[1];
	vec->z = (double)xyz[2];
}

int		get_contents_size(char **contents)
{
	int i;

	i = 0;
	while (contents[i])
		i++;
	return (i);
}

void		free_contents(char **contents)
{
	int	i;

	i = 0;
	while(contents[i])
		free(contents[i++]);
	free(contents);
}

int		parse_resolution(t_scene *scene, char *line)
{
	int res_x;
	int res_y;
	char **contents;

	contents = ft_split_space(line);
	if (get_contents_size(contents) != 2)
		return (-1);
	ft_atoi(contents[0], &res_x);
	ft_atoi(contents[1], &res_y);
	scene->viewport = make_canvas(res_x, res_y);
	free_contents(contents);
	return (1);
}

int 	parse_ambient_light(t_scene *scene, char *line)
{
	float	ratio;
	t_color color;
	char 	**contents;
	char	**rgb;

	contents = ft_split_space(line);
	if (get_contents_size(contents) != 2)
		return (-1);
	ft_atof(contents[0], &ratio);
	rgb = ft_split_comma(contents[1]);
	if (get_contents_size(rgb) != 3)
		return (-1);
	set_xyz_rgb(rgb[0], rgb[1], rgb[2], &color);
	free_contents(rgb);
	free_contents(contents);
	scene->ambients = make_ambients(ratio, color);
	return (0);
}

t_sphere	make_sphere(t_point point, int diameter, t_color color)
{
	t_sphere sphere;
	
	sphere.center = point;
	sphere.radius = (double)diameter;
	sphere.color = color;
	return (sphere);
}

int 	parse_camera(t_scene *scene, char *line)
{
	t_vec	 vec[2];
	int	 angle;
	char **contents;
	char **xyz;

	contents = ft_split_space(line);
	if (get_contents_size(contents) != 3)
		return (-1);
	xyz = ft_split_comma(contents[0]);
	if (get_contents_size(xyz) != 3)
		return (-1);
	set_xyz_rgb(xyz[0], xyz[1], xyz[2], &vec[0]);
	free_contents(xyz);
	xyz = ft_split_comma(contents[1]);
	if (get_contents_size(xyz) != 3)
		return (-1);
	set_xyz_rgb(xyz[0], xyz[1], xyz[2], &vec[1]);
	free_contents(xyz);
	ft_atoi(contents[2], &angle);
	free_contents(contents);
	scene->camera = make_camera((t_point)vec[0], vec[1], angle);
	return (0);
}

int		parse_sphere(t_scene *scene, char *line)
{
	t_vec vec[2];
	int		diameter;
	char	**contents;
	char	**xyz;

	contents = ft_split_space(line);
	if (get_contents_size(contents) != 3)
		return (-1);
	xyz = ft_split_comma(contents[0]);
	if (get_contents_size(xyz) != 3)
		return (-1);
	set_xyz_rgb(xyz[0], xyz[1], xyz[2], &vec[0]);
	free_contents(xyz);
	ft_atoi(contents[1], &diameter);
	xyz = ft_split_comma(contents[2]);
	if (get_contents_size(xyz) != 3)
		return (-1);
	set_xyz_rgb(xyz[0], xyz[1], xyz[2], &vec[1]);
	free_contents(xyz);
	free_contents(contents);
	scene->sphere = make_sphere((t_point)vec[0], diameter, (t_color)vec[1]);
	return (0);
}

int			parse(t_scene *scene, char *line)
{
	if (line[0] != '\0')
	{
		if (line[0] == 'R')
			parse_resolution(scene, ++line);
		else if (line[0] == 'A')
			return (parse_ambient_light(scene, ++line));
		else if (line[0] == 'c')
			return (parse_camera(scene, ++line));
		else if (line[0] == 's' && line[1] == 'p' && ++line && ++line)
			return (parse_sphere(scene, line));
		/*else if (line[0] == 'c' && line[1] == 'y')
			return (parse_cylinder(scene, line));
		else if (line[0] == 'l')
			return (parse_point_light(scene, line));
		else if (line[0] == 's' && line[1] == 'q')
			return (parse_square(scene, line));
		else if (line[0] == 'p' && line[1] == 'l')
			return (parse_plan(scene, line));
		else if (line[0] == 't' && line[1] == 'r')
			return (parse_triangle(scene, line));
		else
			return (-1);
		*/
		printf("ratio  = %f r = %d g = %d b = %d\n", (scene)->ambients.ratio, (scene)->ambients.r, (scene)->ambients.g, (scene)->ambients.b);
		printf("cam.x  = %f y = %f z = %f angle = %d\n", (scene)->camera.vec.x, (scene)->camera.vec.y, (scene)->camera.vec.z, (scene)->camera.angle);
	}
	return (0);
}
