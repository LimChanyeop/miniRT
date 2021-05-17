#include "utils.h"

void				make_bmp_header(char **data, t_scene *scene)
{
	unsigned int 	size;
	
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

void				fill_bmp(char **data, t_scene *scene)
{
	int 			i;
	int 			j;
	int 			x;
	int 			y;

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