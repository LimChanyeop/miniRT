#include "utils.h"

void		my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char		*pixel;

	pixel = (char *)mlx->data +
			(y * mlx->size_l + x * (mlx->bpp / 8));
	*(unsigned int *)pixel = color;
}

void		mlx_draw(t_scene *scene, t_camera *camera, t_vec *cn_lc_ve_ho)
{
	int			i;
	int			j;
	t_vec		a_b[2];
	double		u_v[2];
	t_color		pixel_color;

	j = -1;
	while (++j < scene->viewport.height)
	{
		i = -1;
		while (++i < scene->viewport.width)
		{
			u_v[0] = (scene->viewport.height - 1 - (double)j) / \
							(scene->viewport.height - 1);
			u_v[1] = (scene->viewport.width - 1 - (double)i) / \
							(scene->viewport.width - 1);
			a_b[0] = camera->orig;
			a_b[1] = vplus(cn_lc_ve_ho[1], vplus(vmult_(cn_lc_ve_ho[3], \
							u_v[1]), vmult_(cn_lc_ve_ho[2], u_v[0])));
			pixel_color = ray_color((new_ray(a_b[0], vunit(a_b[1]))), scene);
			write_color(scene->mlx, pixel_color);
			my_mlx_pixel_put(scene->mlx, i, j, scene->mlx->int_color);
		}
	}
	make_img_to_window(scene);
}

void		make_img_to_window(t_scene *scene)
{
	mlx_put_image_to_window(scene->mlx->mlx_ptr, scene->mlx->win_ptr, \
								scene->mlx->img_ptr, 0, 0);
}

void		start_mlx(t_scene *scene)
{
	float		fl_wi_hi[3];
	t_vec		cn_lc_ve_ho[4];
	t_camera	*cam;

	cam = scene->cam_selected;
	fl_wi_hi[0] = 1.0;
	fl_wi_hi[1] = 2.0 * fl_wi_hi[0] * tan(cam->angle * 0.5 * PI / 180);
	fl_wi_hi[2] = fl_wi_hi[1] * scene->viewport.aspect_ratio;
	cn_lc_ve_ho[3] = vcross(vec(0, 1, 0), cam->vec);
	if (vector_validation(cn_lc_ve_ho[3]) == 0)
		cn_lc_ve_ho[2] = vunit(vcross(cam->vec, cn_lc_ve_ho[3]));
	else
	{
		cn_lc_ve_ho[2] = vunit(vcross(cam->vec, vec(1, 0, 0)));
		cn_lc_ve_ho[3] = vunit(vcross(cn_lc_ve_ho[2], cam->vec));
	}
	cn_lc_ve_ho[3] = vmult_(cn_lc_ve_ho[3], fl_wi_hi[1]);
	cn_lc_ve_ho[2] = vmult_(cn_lc_ve_ho[2], fl_wi_hi[2]);
	cn_lc_ve_ho[0] = ray_at(new_ray(cam->orig, cam->vec), fl_wi_hi[0]);
	cn_lc_ve_ho[1] = vminus(vminus(vminus(cn_lc_ve_ho[0], \
		vdivide(cn_lc_ve_ho[3], 2)), vdivide(cn_lc_ve_ho[2], 2)), cam->orig);
	mlx_draw(scene, cam, cn_lc_ve_ho);
}
