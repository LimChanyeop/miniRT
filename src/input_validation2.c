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

int		check_file_format(int argc, char **argv)
{
	int len;

	len = ft_strlen(argv[1]);
	if (len < 4)
		return (-1);
	if (!(argc == 2 || argc == 3))
		return (-1);
	if (!(argv[1][len - 3] == '.' && argv[1][len - 2] == 'r' \
		&& argv[1][len - 1] == 't' && argv[1][len] == 0))
		return (-1);
	if (argv[1][len - 4] == '/')
		return (-1);
	if (argc == 3)
	{
		if (ft_strncmp(argv[2], "--save\0", 7))
			return (-1);
	}
	return (0);
}
