/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_event.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clim <clim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 13:48:10 by clim              #+#    #+#             */
/*   Updated: 2021/05/18 13:48:11 by clim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int			handle_event(int key, t_scene *scene)
{
	if (key == 8)
	{
		scene->camera = scene->camera->next;
		scene->cam_selected = (t_camera *)scene->camera->content;
		start_mlx(scene);
	}
	if (key == 53)
	{
		exit_program();
		return (0);
	}
	return (0);
}

int			exit_program(void)
{
	exit(0);
}
