#include "libft.h"
#include "utils.h"
#include <stdio.h>

int		parse_resolution(t_scene *scene, char *line)
{
	int res_x;
	int res_y;
	char **contents;
	int	error;

	if (scene->viewport.check_in == 1)
		report_error(8);
	error = 0;
	contents = ft_split_space(line);
	if (get_contents_size(contents) != 2)
		return (-1);
	error += ft_atoi(contents[0], &res_x);
	error += ft_atoi(contents[1], &res_y);
	scene->viewport = make_canvas(res_x, res_y);
	free_contents(contents);
	if (error < 0)
		return (error);
	return (0);
}

int 	parse_ambient_light(t_scene *scene, char *line)
{
	double	ratio;
	t_color color;
	char 	**contents;
	int		error;

	if (scene->ambients.check_in == 1)
		report_error(8);
	error = 0;
	contents = ft_split_space(line);
	if (get_contents_size(contents) != 2)
		return (-1);
	error += ft_atod(contents[0], &ratio);
	error += (set_xyz_rgb(ft_split_comma(contents[1]), &color));
	free_contents(contents);
	if (error < 0)
		return (error);
	scene->ambients = make_ambients(ratio, color);
	scene->ambients.color = color_to_rgb(scene->ambients.color);
	return (0);
}

int 	parse_camera(t_scene *scene, char *line)//여러개 들어올 수 있음 -> 도형처럼 t_list로
{
	t_vec	 vec[2];
	double	 angle;
	char **contents;
	int		error;
	t_camera *cm;

	cm = (t_camera *)malloc(sizeof(t_camera));
	error = 0;
	contents = ft_split_space(line);
	if (get_contents_size(contents) != 3)
		return (-1);
	error += set_xyz_rgb(ft_split_comma(contents[0]), &vec[0]);
	error += set_xyz_rgb(ft_split_comma(contents[1]), &vec[1]);
	error += ft_atod(contents[2], &angle);
	free_contents(contents);
	if (error < 0)
		return (error);
	*cm = make_camera((t_vec)vec[0], vec[1], angle);
	ft_lstadd_front(&scene->camera, ft_lstnew(cm));
	return (0);
}

int		parse_sphere(t_scene *scene, char *line)
{
	t_vec vec[2];
	double	radius;
	char	**contents;
	t_sphere *sp;
	int		error;

	error = 0;
	sp = (t_sphere *)malloc(sizeof(t_sphere));
	contents = ft_split_space(line);
	if (get_contents_size(contents) != 3)
		return (-1);
	error += set_xyz_rgb(ft_split_comma(contents[0]), &vec[0]);
	error += ft_atod(contents[1], &radius);
	error += set_xyz_rgb(ft_split_comma(contents[2]), &vec[1]);
	free_contents(contents);
	if (error < 0)
		return (error);
	*sp = make_sphere((t_vec)vec[0], radius, (t_color)vec[1]);
	ft_lstadd_front(&scene->sphere, ft_lstnew(sp));
	sp->color = color_to_rgb(sp->color);
	return (0);
}

int		parse_cylinder(t_scene *scene, char *line)
{
	t_vec 	vec[3];
	double		radius;
	double		height;
	char	**contents;
	int 	error;
	t_cylinder *cy;

	error = 0;
	cy = (t_cylinder *)malloc(sizeof(t_cylinder));
	contents = ft_split_space(line);
	if (get_contents_size(contents) != 5)
		return (-1);
	error += set_xyz_rgb(ft_split_comma(contents[0]), &vec[0]);
	error += set_xyz_rgb(ft_split_comma(contents[1]), &vec[1]);
	error += ft_atod(contents[2], &radius);
	error += ft_atod(contents[3], &height);
	error += set_xyz_rgb(ft_split_comma(contents[4]), &vec[2]);
	free_contents(contents);
	if (error < 0)
		return (error);
	*cy = make_cylinder((t_vec)vec[0], (t_vec)vec[1], radius, height, (t_color)vec[2]);
	ft_lstadd_front(&scene->cylinder, ft_lstnew(cy));
	cy->color = color_to_rgb(cy->color);
	return (0);
}

int		parse_triangle(t_scene *scene, char *line)
{
	t_vec 	vec[4];
	char	**contents;
	int 	error;
	t_triangle *tr;

	error = 0;
	tr = (t_triangle *)malloc(sizeof(t_triangle));
	contents = ft_split_space(line);
	if (get_contents_size(contents) != 4)
		return (-1);
	error += set_xyz_rgb(ft_split_comma(contents[0]), &vec[0]);
	error += set_xyz_rgb(ft_split_comma(contents[1]), &vec[1]);
	error += set_xyz_rgb(ft_split_comma(contents[2]), &vec[2]);
	error += set_xyz_rgb(ft_split_comma(contents[3]), &vec[3]);
	free_contents(contents);
	if (error < 0)
		return (error);
	*tr = make_triangle((t_vec)vec[0], (t_vec)vec[1], (t_vec)vec[2], (t_color)vec[3]);
	ft_lstadd_front(&scene->triangle, ft_lstnew(tr));
	tr->color = color_to_rgb(tr->color);
	return (0);
}

int		parse_square(t_scene *scene, char *line)
{
	t_vec 	vec[3];
	char	**contents;
	double		radius;
	int 	error;
	t_square *sq;

	error = 0;
	sq = (t_square *)malloc(sizeof(t_square));
	contents = ft_split_space(line);
	if (get_contents_size(contents) != 4)
		return (-1);
	error += set_xyz_rgb(ft_split_comma(contents[0]), &vec[0]);
	error += set_xyz_rgb(ft_split_comma(contents[1]), &vec[1]);
	error += ft_atod(contents[2], &radius);
	error += set_xyz_rgb(ft_split_comma(contents[3]), &vec[2]);
	free_contents(contents);
	if (error < 0)
		return (error);
	*sq = make_square((t_vec)vec[0], (t_vec)vec[1], radius, (t_color)vec[2]);
	ft_lstadd_front(&scene->square, ft_lstnew(sq));
	sq->color = color_to_rgb(sq->color);
	return (0);
}

int		parse_plane(t_scene *scene, char *line)
{
	t_vec 	vec[3];
	char	**contents;
	int 	error;
	t_plane *pl;

	error = 0;
	pl = (t_plane *)malloc(sizeof(t_plane));
	contents = ft_split_space(line);
	if (get_contents_size(contents) != 3)
		return (-1);
	error += set_xyz_rgb(ft_split_comma(contents[0]), &vec[0]);
	error += set_xyz_rgb(ft_split_comma(contents[1]), &vec[1]);
	error += set_xyz_rgb(ft_split_comma(contents[2]), &vec[2]);
	free_contents(contents);
	if (error < 0)
		return (error);
	*pl = make_plane((t_vec)vec[0], (t_vec)vec[1], (t_color)vec[2]);
	ft_lstadd_front(&scene->plane, ft_lstnew(pl));
	pl->color = color_to_rgb(pl->color);
	return (0);
}

int		parse_light(t_scene *scene, char *line)
{
	t_vec	vec[2];
	char	**contents;
	double	ratio;
	int 	error;
	t_light *li;

	error = 0;
	li = (t_light *)malloc(sizeof(t_light));
	contents = ft_split_space(line);
	if (get_contents_size(contents) != 3)
		return (-1);
	error += set_xyz_rgb(ft_split_comma(contents[0]), &vec[0]);
	error += ft_atod(contents[1], &ratio);
	error += set_xyz_rgb(ft_split_comma(contents[2]), &vec[1]);
	free_contents(contents);
	if (error < 0)
		return (error);
	*li = make_light((t_vec)vec[0], ratio, (t_color)vec[1]);
	ft_lstadd_front(&scene->light, ft_lstnew(li));
	li->color = color_to_rgb(li->color);
	return (0);
}

int			parse(t_scene *scene, char *line)
{
	if (line[0] != '\0')
	{
		if (line[0] == 'R')
			return (parse_resolution(scene, ++line));
		else if (line[0] == 'A')
			return (parse_ambient_light(scene, ++line));
		else if (line[0] == 'c' && line[1] == 'y' && ++line && ++line)
			return (parse_cylinder(scene, line));
		else if (line[0] == 'c')
			return (parse_camera(scene, ++line));
		else if (line[0] == 's' && line[1] == 'p' && ++line && ++line)
			return (parse_sphere(scene, line));
		else if (line[0] == 't' && line[1] == 'r' && ++line && ++line)
			return (parse_triangle(scene, line));
		else if (line[0] == 's' && line[1] == 'q' && ++line && ++line)
			return (parse_square(scene, line));
		else if (line[0] == 'p' && line[1] == 'l' && ++line && ++line)
			return (parse_plane(scene, ++line));
		else if (line[0] == 'l')
			return (parse_light(scene, ++line));
		else
			return (-1);
	}
	return (0);
}

t_scene 	*parse_rt(int fd)
{
	char		*line;
	t_scene		*scene;

	line = 0;
	scene = (t_scene *)malloc(sizeof(t_scene));
	init_scene(scene);
	while(get_next_line(fd, &line) > 0)
	{
		if (parse(scene, line) < 0)
		{
			printf("line Error in %s\n", line);
			report_error(8);
		}
		free(line);
	}
	if (parse(scene, line) < 0)
		report_error(8);
	free(line);
	if (have_necessary_input(scene) < 0)
		report_error(7);
	printf("rt file validation successfully finished !\n");
	return (scene);
}