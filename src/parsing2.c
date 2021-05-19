/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clim <clim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 13:48:50 by clim              #+#    #+#             */
/*   Updated: 2021/05/18 13:48:51 by clim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int				parse_square(t_scene *scene, char *line)
{
	t_vec		vec[3];
	char		**contents;
	double		radius;
	int			error;
	t_square	*sq;

	error = 0;
	if (!(sq = (t_square *)malloc(sizeof(t_square))))
		report_error(10);
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

int				parse_plane(t_scene *scene, char *line)
{
	t_vec		vec[3];
	char		**contents;
	int			error;
	t_plane		*pl;

	error = 0;
	if (!(pl = (t_plane *)malloc(sizeof(t_plane))))
		report_error(10);
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

int				parse_light(t_scene *scene, char *line)
{
	t_vec		vec[2];
	char		**contents;
	double		ratio;
	int			error;
	t_light		*li;

	error = 0;
	if (!(li = (t_light *)malloc(sizeof(t_light))))
		report_error(10);
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

int				parse_triangle(t_scene *scene, char *line)
{
	t_vec		vec[4];
	char		**contents;
	int			error;
	t_triangle	*tr;

	error = 0;
	if (!(tr = (t_triangle *)malloc(sizeof(t_triangle))))
		report_error(10);
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
	*tr = make_triangle((t_vec)vec[0], (t_vec)vec[1], \
					(t_vec)vec[2], (t_color)vec[3]);
	ft_lstadd_front(&scene->triangle, ft_lstnew(tr));
	tr->color = color_to_rgb(tr->color);
	return (0);
}

int				parse(t_scene *scene, char *line)
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
