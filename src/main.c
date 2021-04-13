#include <stdio.h>
#include "mlx.h"
#include "utils.h"
#include "libft.h"

int	main(void)
{
	const float aspect_ratio = 8.0 / 6.0;
	const int	image_width = 800;
	const int	image_height = image_width / aspect_ratio;

	t_mlx		*app;
	if (!(app = (t_mlx*)malloc(sizeof(t_mlx))))
		return (-1);
	
	app->mlx_ptr = mlx_init();
	app->win_ptr = mlx_new_window(app->mlx_ptr, 800, 600, "raytracer");
	app->img_ptr = mlx_new_image(app->mlx_ptr, image_width, image_height);
	app->data = (int *)mlx_get_data_addr(app->img_ptr, &app->bpp, &app->size_l, &app->endian);
	ft_putstr_fd("test", 1);
	float		viewport_height = 2.0;
	float		viewport_width = aspect_ratio * viewport_height;
	float		focal_length = 1.0;

	t_vec		origin = {0,0,0};
	t_vec		horizontal = {viewport_width, 0, 0};
	t_vec		vertical = {0, viewport_height, 0};
	t_vec		any = {0, 0, -focal_length};
	t_vec		lower_left_corner = vminus(vplus(vplus(vdivide(horizontal, -2), vdivide(vertical, -2)), any), origin);
	int			j = 0;
	while (j < image_height)
	{
		int i = 0;
		while (i < image_width)
		{
			float u = (double)i / (image_width - 1);
			float v = (double)j / (image_height - 1);

			t_vec a = origin;
			t_vec b = vplus(lower_left_corner, vplus(vmult_(horizontal, u), vmult_(vminus(vertical, origin), v)));
			t_vec pixel_color = ray_color(a, b);
			write_color(app, pixel_color);
			mlx_pixel_put(app->mlx_ptr, app->win_ptr, i, j, app->int_color);
			++i;
		}
		++j;
	}
	mlx_loop(app->mlx_ptr);
}
