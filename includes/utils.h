#ifndef utils_H
# define utils_H

# include <math.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct  s_vec t_vec;
typedef struct  s_vec t_point;
typedef struct  s_vec t_color;
typedef struct  s_ray t_ray;
typedef struct  s_camera t_camera;
typedef struct  s_canvas t_canvas;
typedef struct  s_sphere t_sphere;
typedef struct  s_mlx t_mlx;
typedef struct  s_ambient t_ambient;
typedef struct  s_rgb t_rgb;
typedef struct  s_scene t_scene;
typedef struct  s_lstobjects t_lstobjects;

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

struct s_ambient
{
    int ratio;
};

struct s_rgb
{
    int r;
    int g;
    int b;
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

struct		s_scene
{
	t_vec			*origin;
	t_canvas		*viewport;
	t_canvas		*viewplane;
	t_lstobjects	*cameras;
	t_lstobjects	*objects;
	t_lstobjects	*lights;
	float			total_intensity;
	int				nb_camera;
	int				background_color;
	int				depth;
	float			t_min;
	float			t_max;
};

struct		s_lstobjects
{
	int				type;
	void			*object;
	float			reflective;
	void			*prev;
	void			*next;
};

t_vec	vec(double x, double y, double z);
t_point point(double x, double y, double z);
t_point color(double r, double g, double b);
void	vset(t_vec *vec, double x, double y, double z);
double	vlength2(t_vec vec);
double	vlength(t_vec vec);
t_vec	vplus(t_vec vec, t_vec vec2);
t_vec	vplus_(t_vec vec, double x, double y, double z);
t_vec	vminus(t_vec vec, t_vec vec2);
t_vec	vminus_(t_vec vec, double x, double y, double z);
t_vec	vmult_(t_vec vec, double t);
t_vec	vmult(t_vec vec, t_vec vec2);
t_vec	vdivide(t_vec vec, double t);
double	vdot(t_vec vec, t_vec vec2);
t_vec	vcross(t_vec vec, t_vec vec2);
t_vec	vunit(t_vec vec);

t_ray		ray(t_point orig, t_vec dir);
t_point	    ray_at(t_point orig, t_vec dir, double t);
t_vec	    ray_color(t_vec orig, t_vec dir);
int	        hit_sphere(t_vec center, double radius, t_vec origin, t_vec direction);

void	write_color(t_mlx *app, t_vec pixel_color);

#endif