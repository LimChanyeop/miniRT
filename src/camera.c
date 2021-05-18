/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clim <clim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 13:45:21 by clim              #+#    #+#             */
/*   Updated: 2021/05/18 13:45:22 by clim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_camera		make_camera(t_vec point, t_vec vec, double angle)
{
	t_camera	camera;

	if (vector_validation(vec) < 0)
		report_error(1);
	if (angle_validation(angle) < 0)
		report_error(3);
	camera.orig = point;
	camera.vec = vec;
	camera.angle = angle;
	camera.check_in = 1;
	return (camera);
}
