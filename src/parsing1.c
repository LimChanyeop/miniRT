/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clim <clim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 13:46:43 by clim              #+#    #+#             */
/*   Updated: 2021/05/18 13:46:44 by clim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils.h"
#include "mlx.h"
#include <stdio.h>

int				parse_resolution(t_scene *scene, char *line)
{
	int			res_x;
	int			res_y;
	char		**contents;
	int			error;

	if (scene->viewport.check_in == 1)
		report_error(8);
	error = 0;
	contents = ft_split_space(line);
	if (get_contents_size(contents) != 2)
		return (-1);
	error += ft_atoi(contents[0], &res_x);
	error += ft_atoi(contents[1], &res_y);
	scene->viewport = make_canvas(res_x, res_y);
	check_screen_size(scene);
	free_contents(contents);
	if (error < 0)
		return (error);
	return (0);
}

int				parse_ambient_light(t_scene *scene, char *line)
{
	double		ratio;
	t_color		color;
	char		**contents;
	int			error;

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

int				parse_camera(t_scene *scene, char *line)
{
	t_vec		vec[2];
	double		angle;
	char		**contents;
	int			error;
	t_camera	*cm;

	if (!(cm = (t_camera *)malloc(sizeof(t_camera))))
		return (-1);
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

int				parse_sphere(t_scene *scene, char *line)
{
	t_vec		vec[2];
	double		radius;
	char		**contents;
	t_sphere	*sp;
	int			error;

	error = 0;
	if (!(sp = (t_sphere *)malloc(sizeof(t_sphere))))
		return (-1);
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

int				parse_cylinder(t_scene *scene, char *line)
{
	t_vec		vec[3];
	double		rad_hei[2];
	char		**contents;
	int			error;
	t_cylinder	*cy;

	error = 0;
	if (!(cy = (t_cylinder *)malloc(sizeof(t_cylinder))))
		return (-1);
	contents = ft_split_space(line);
	if (get_contents_size(contents) != 5)
		return (-1);
	error += set_xyz_rgb(ft_split_comma(contents[0]), &vec[0]);
	error += set_xyz_rgb(ft_split_comma(contents[1]), &vec[1]);
	error += ft_atod(contents[2], &rad_hei[0]);
	error += ft_atod(contents[3], &rad_hei[1]);
	error += set_xyz_rgb(ft_split_comma(contents[4]), &vec[2]);
	free_contents(contents);
	if (error < 0)
		return (error);
	*cy = make_cylinder((t_vec)vec[0], (t_vec)vec[1], rad_hei, \
					(t_color)vec[2]);
	ft_lstadd_front(&scene->cylinder, ft_lstnew(cy));
	cy->color = color_to_rgb(cy->color);
	return (0);
}
