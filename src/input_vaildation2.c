/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_vaildation2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clim <clim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 13:46:24 by clim              #+#    #+#             */
/*   Updated: 2021/05/18 13:46:25 by clim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int		have_necessary_input(t_scene *scene)
{
	if (scene->viewport.check_in == 0)
		return (-1);
	else if (scene->ambients.check_in == 0)
		return (-1);
	else if (scene->camera == 0)
		return (-1);
	else
		return (0);
}

int		check_file_format(char *str)
{
	while (str)
	{
		if (*str == '.')
		{
			if (str[1] == 'r' && str[2] == 't' && !str[3])
				return (-1);
		}
		str++;
	}
	return (0);
}
