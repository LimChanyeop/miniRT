/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clim <clim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 13:47:56 by clim              #+#    #+#             */
/*   Updated: 2021/05/18 13:47:57 by clim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_canvas		make_canvas(int width, int height)
{
	t_canvas	canvas;

	if (check_positive((double)width) < 0 || width == 0)
		report_error(5);
	if (check_positive((double)height) < 0 || height == 0)
		report_error(5);
	canvas.width = width;
	canvas.height = height;
	canvas.aspect_ratio = (double)height / (double)width;
	canvas.check_in = 1;
	return (canvas);
}

void			check_screen_size(t_scene *scene)
{
	int			max_x;
	int			max_y;

	mlx_get_screen_size(scene->mlx, &max_x, &max_y);
	if (scene->viewport.width > max_x)
		scene->viewport.width = max_x;
	if (scene->viewport.height > max_y)
		scene->viewport.height = max_y;
	scene->viewport.aspect_ratio = (double)scene->viewport.height / \
		(double)scene->viewport.width;
}
