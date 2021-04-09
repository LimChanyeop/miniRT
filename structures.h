#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct s_vec t_vec;
typedef struct s_vec t_point;
typedef struct s_vec t_color;
typedef struct s_ray t_ray;
typedef struct s_camera t_camera;
typedef struct s_canvas t_canvas;
typedef struct s_sphere t_sphere;
typedef struct s_mlx t_mlx;

typedef int	t_bool;

# define FALSE 0
# define TRUE 1

struct s_vec
{
	double x;
	double y;
	double z;
};

struct s_mlx
{
	void *mlx_ptr;
	void *win_ptr;
	void *img_ptr;
	int  *data;
	int  bpp;
	int	 size_l;
	int  endian;

	t_vec color;
	int int_color;
};

struct	s_ray
{
	t_point	orig;
	t_vec		dir;
};

struct	s_camera
{
	t_point	orig;  // origin
	double		view_h; // viewport height;
	double		view_w; // viewport width;
	t_vec		horizontal; // 수평방향 벡터
	t_vec		vertical; // 수직방향 벡터
	double		focal_len; // focal length;
	t_point	left_bottom; // lower left corner;
};

struct	s_canvas
{
	int		width; //canvas width
	int		height; //canvas height;
	double	aspect_ratio; 
};

struct	s_sphere
{
	t_point	center;
	double		radius;
	double		radius2;
};

#endif