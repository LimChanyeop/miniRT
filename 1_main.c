#include <stdio.h>
#include "mlx.h"
#include "utils.h"
#include "libft.h"

void		my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char	*pixel;
	pixel = (char *)mlx->data +
			(y * mlx->size_l + x * (mlx->bpp / 8));
	*(unsigned int *)pixel = color;
}

void make_bmp_header(char **data, t_scene *scene)
{
	unsigned int size;
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

void	fill_bmp(char **data, t_scene *scene)
{
	int i;
	int j;
	int x;
	int y;

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
t_mlx 			*mlx_draw(t_scene *scene, t_camera *camera, t_vec *cn_lc_ve_ho)
{
	int i;
	int j;
	t_vec a_b[2];
	t_color pixel_color;
	double u_v[2];

	j = 0;
	while (j < scene->viewport.height)
	{
		i = 0;
		while (i < scene->viewport.width)
		{
			u_v[0] = (scene->viewport.height - 1 - (double)j) / (scene->viewport.height - 1);
			u_v[1] = (scene->viewport.width - 1 -(double)i) / (scene->viewport.width - 1);
			a_b[0] = camera->orig;
			a_b[1] = vplus(cn_lc_ve_ho[1], vplus(vmult_(cn_lc_ve_ho[3], u_v[1]), vmult_(cn_lc_ve_ho[2], u_v[0])));
			pixel_color = ray_color((new_ray(a_b[0], vunit(a_b[1]))), scene);
			write_color(scene->mlx, pixel_color);
			my_mlx_pixel_put(scene->mlx, i, j, scene->mlx->int_color);
			++i;
		}
		++j;
	}
	mlx_put_image_to_window(scene->mlx->mlx_ptr, scene->mlx->win_ptr, scene->mlx->img_ptr, 0, 0);
	return (scene->mlx);
}

int					handle_event(int key, t_scene *scene)
{
	if (key != 53)
	{
		scene->camera = scene->camera->next;
		scene->cam_selected = (t_camera *)scene->camera->content;
		start_mlx(scene);
	}
	if (key == 53)
	{
		exit(1);
		return (0);
	}
	return (0);
}

t_mlx 				*start_mlx(t_scene *scene)
{
	float		fl_wi_hi[3];
	t_vec		cn_lc_ve_ho[4];
	t_camera	*cam;

	cam = scene->cam_selected;
	fl_wi_hi[0] = 1.0;
	fl_wi_hi[1] = 2.0 * fl_wi_hi[0] * tan(cam->angle * 0.5 * PI / 180);
	fl_wi_hi[2] = fl_wi_hi[1] * scene->viewport.aspect_ratio;
	cn_lc_ve_ho[3] = vcross(vec(0,1,0), cam->vec);
	if (vector_validation(cn_lc_ve_ho[3]) == 0)
		cn_lc_ve_ho[2] = vunit(vcross(cam->vec, cn_lc_ve_ho[3]));
	else
	{
		cn_lc_ve_ho[2] = vunit(vcross(cam->vec, vec(1,0,0)));
		cn_lc_ve_ho[3] = vunit(vcross(cn_lc_ve_ho[2], cam->vec));
	}
	cn_lc_ve_ho[3] = vmult_(cn_lc_ve_ho[3], fl_wi_hi[1]);
	cn_lc_ve_ho[2] = vmult_(cn_lc_ve_ho[2], fl_wi_hi[2]);
	cn_lc_ve_ho[0] = ray_at(new_ray(cam->orig, cam->vec), fl_wi_hi[0]);
	cn_lc_ve_ho[1] = vminus(vminus(vminus(cn_lc_ve_ho[0], vdivide(cn_lc_ve_ho[3], 2)), \
						vdivide(cn_lc_ve_ho[2], 2)), cam->orig);
	return(mlx_draw(scene, cam, cn_lc_ve_ho));
}

int	main(int argc, char *argv[])
{
	int			fd;
	t_scene		*scene;
	t_list 		*cam;
	int			bmp_fd;
	char 		*data;

	if (!((argc == 2 && check_file_format(argv[1])) || ((argc == 3 && !ft_strncmp(argv[2], "--save\0", 7)))))
		report_error(6);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		report_error(9);
	scene = parse_rt(fd);
	cam = ft_lstlast(scene->camera);
	cam->next = scene->camera;
	scene->cam_selected = (t_camera *)malloc(sizeof(t_camera));
	scene->cam_selected = (t_camera *)scene->camera->content;
	scene->mlx = mlx_initiation(scene);
	start_mlx(scene);
	if (argc == 3)
	{
		data = malloc(sizeof(char) * (54 + scene->viewport.height * scene->viewport.width * 4 + 1));
		bmp_fd = open("miniRT.bmp", O_TRUNC | O_RDWR | O_CREAT);
		make_bmp_header(&data, scene);
		fill_bmp(&data, scene);
		write(bmp_fd, data, (54 + scene->viewport.height * scene->viewport.width * 4 + 1));
		exit(0);
	}
	mlx_key_hook(scene->mlx->win_ptr, handle_event, scene);
	mlx_loop(scene->mlx->mlx_ptr);
	return (0);
}

t_scene 	*parse_rt(int fd)
{
	char		*line;
	t_scene		*scene;

	line = 0;
	scene = (t_scene *)malloc(sizeof(t_scene));
	init_scene(scene);
	while(get_next_line(fd, &line) > 0)
	{
		if (parse(scene, line) < 0)
		{
			printf("line Error in %s\n", line);
			report_error(8);
		}
		free(line);
	}
	if (parse(scene, line) < 0)
		report_error(8);
	free(line);
	if (have_necessary_input(scene) < 0)
		report_error(7);
	printf("rt file validation successfully finished !\n");
	return (scene);
}

// #pragma pack(push, 1)                // 구조체를 1바이트 크기로 정렬

// typedef struct bmp_header   // BMP 비트맵 파일 헤더 구조체
// {
//     unsigned short bftype;           // BMP 파일 매직 넘버
//     unsigned int   bfsize;           // 파일 크기
//     unsigned short bfreserved1;      // 예약
//     unsigned short bfreserved2;      // 예약
//     unsigned int   bfoffbits;        // 비트맵 데이터의 시작 위치
//     unsigned int   bisize;           // 현재 구조체의 크기
//     int            biwidth;          // 비트맵 이미지의 가로 크기
//     int            biheight;         // 비트맵 이미지의 세로 크기
//     unsigned short biplanes;         // 사용하는 색상판의 수
//     unsigned short bibitCount;       // 픽셀 하나를 표현하는 비트 수
//     unsigned int   bicompression;    // 압축 방식
//     unsigned int   bisizeImage;      // 비트맵 이미지의 픽셀 데이터 크기
//     int            bixPelsPerMeter;  // 그림의 가로 해상도(미터당 픽셀)
//     int            biyPelsPerMeter;  // 그림의 세로 해상도(미터당 픽셀)
//     unsigned int   biclrUsed;        // 색상 테이블에서 실제 사용되는 색상 수
//     unsigned int   biclrImportant;   // 비트맵을 표현하기 위해 필요한 색상 인덱스 수
// } t_bmp_header;

// #pragma pack(pop)

//open O_TRUNC / **data를 파일에 write 하기/