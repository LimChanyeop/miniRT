/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_bmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clim <clim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 13:46:34 by clim              #+#    #+#             */
/*   Updated: 2021/05/18 13:46:35 by clim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void				make_bmp_header(char **data, t_scene *scene)
{
	unsigned int	size;

	size = scene->viewport.height * scene->viewport.width * 4;
	*(unsigned char *)*data = 'B';
	*(unsigned char *)(*data + 1) = 'M';
	*(unsigned int *)(*data + 2) = (size + 54);
	*(unsigned int *)(*data + 6) = (unsigned int)0;
	*(unsigned int *)(*data + 10) = 54;
	*(unsigned int *)(*data + 14) = 54 - 14;
	*(int *)(*data + 18) = scene->viewport.width;
	*(int *)(*data + 22) = scene->viewport.height;
	*(unsigned short *)(*data + 26) = 1;
	*(unsigned short *)(*data + 28) = 32;
	*(unsigned int *)(*data + 30) = 0;
	*(unsigned int *)(*data + 34) = size;
	*(int *)(*data + 38) = scene->viewport.width;
	*(int *)(*data + 42) = scene->viewport.height;
	*(unsigned int *)(*data + 46) = 0x00ffffff;
	*(unsigned int *)(*data + 50) = 0;
}

void				make_bmp(t_scene *scene)
{
	int				bmp_fd;
	char			*data;

	data = malloc(sizeof(char) * (54 + scene->viewport.height * \
				scene->viewport.width * 4 + 1));
	bmp_fd = open("miniRT.bmp", O_RDWR | O_TRUNC | O_CREAT, 0644);
	make_bmp_header(&data, scene);
	fill_bmp(&data, scene);
	write(bmp_fd, data, (54 + scene->viewport.height * \
				scene->viewport.width * 4 + 1));
	exit(0);
}

void				fill_bmp(char **data, t_scene *scene)
{
	int				i;
	int				j;
	int				x;
	int				y;

	i = 54;
	y = scene->viewport.height;
	while (y--)
	{
		x = -1;
		while (++x < scene->viewport.width)
		{
			j = (x + (y * (scene->mlx->size_l) / 4));
			*(int *)(*data + i) = *(scene->mlx->data + j);
			i += 4;
		}
	}
}
