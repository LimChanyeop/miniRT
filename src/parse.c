/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clim <clim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 13:48:43 by clim              #+#    #+#             */
/*   Updated: 2021/05/18 13:48:44 by clim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils.h"
#include "mlx.h"
#include <stdio.h>

t_scene				*parse_rt(int fd)
{
	char			*line;
	t_scene			*scene;

	line = 0;
	scene = (t_scene *)malloc(sizeof(t_scene));
	init_scene(scene);
	while (get_next_line(fd, &line) > 0)
	{
		if (parse(scene, line) < 0)
		{
			report_error(8);
		}
		free(line);
	}
	if (parse(scene, line) < 0)
		report_error(8);
	free(line);
	if (have_necessary_input(scene) < 0)
	{
		report_error(7);
	}
	return (scene);
}
