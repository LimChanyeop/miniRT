#include <stdio.h>
#include "mlx.h"
#include "structures.h"
#include "utils.h"
#include "ray.h"
#include "scene.h"
#include "print.h"

int	main(void)
{
	const float aspect_ratio = 16.0 / 9.0;
	const int	image_width = 400;
	const int	image_height = image_width / aspect_ratio;

	t_mlx		*app;
	if (!(app = (t_mlx*)malloc(sizeof(t_mlx))))
		return (-1);
	
	app->mlx_ptr = mlx_init();
	app->win_ptr = mlx_new_window(app->mlx_ptr, 800, 600, "raytracer");
	app->img_ptr = mlx_new_image(app->mlx_ptr, image_width, image_height);
	app->data = (int *)mlx_get_data_addr(app->img_ptr, &app->bpp, &app->size_l, &app->endian);


	float		viewport_height = 2.0;
	float		viewport_width = aspect_ratio * viewport_height;
	float		focal_length = 1.0;

	t_vec		origin = {0,0,0};
	t_vec		horizontal = {viewport_width, 0, 0};
	t_vec		vertical = {0, viewport_height, 0};
	t_vec		any = {0, 0, focal_length};
	t_vec		lower_left_corner = vminus(origin, vplus(vplus(vdivide(horizontal, 2), vdivide(vertical, 2)), any));
	int 		jj = 0;
	int			j = image_height - 1;
	while (j >= 0 && jj < image_height)
	{
		int i = 0;
		while (i < image_width)
		{
			float u = (double)i / (image_width - 1);
			float v = (double)j / (image_height - 1);

			t_vec a = origin;
			t_vec b = vplus(lower_left_corner, vplus(vmult(horizontal, u), vmult(vminus(vertical, origin), v)));
			t_vec pixel_color = ray_color(a, b);
			write_color(app, pixel_color);
			mlx_pixel_put(app->mlx_ptr, app->win_ptr, i, jj, app->int_color);

			++i;
		}
		--j;
		++jj;
	}
	mlx_loop(app->mlx_ptr);
} 