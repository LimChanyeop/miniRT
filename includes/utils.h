#ifndef UTILS_H
# define UTILS_H

# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft.h"

typedef struct  s_vec t_vec;
typedef struct  s_vec t_point;
typedef struct  s_vec t_color;
typedef struct  s_ray t_ray;
typedef struct  s_camera t_camera;
typedef struct  s_canvas t_canvas;
typedef struct  s_sphere t_sphere;
typedef struct  s_triangle t_triangle;
typedef struct	s_cylinder t_cylinder;
typedef struct	s_square t_square;
typedef struct	s_plane t_plane;
typedef struct	s_light	t_light;
typedef struct  s_mlx t_mlx;
typedef struct  s_rgb t_rgb;
typedef struct  s_scene t_scene;
typedef struct  s_lstobjects t_lstobjects;
typedef struct 	s_ambients t_ambients;

typedef int	t_bool;

# define FALSE 0
# define TRUE 1
# define PIE 3.14159265

struct s_vec
{
	double			x;
	double			y;
	double			z;
};

struct s_ambients
{
	float			ratio;
	int				r;
	int				g;
	int				b;
	t_bool			check_in;
};

struct s_mlx
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	int 			*data;
	int 			bpp;
	int				size_l;
	int 			endian;

	t_vec 			color;
	int				int_color;
};

struct	s_ray
{
	t_point			orig;
	t_vec			dir;
};

struct	s_camera
{
	t_point			orig;	// origin
	t_vec			vec;	// dir vector
	int 			angle;
	t_bool			check_in;
};

struct	s_canvas
{
	int				width;	//canvas width
	int				height;	//canvas height
	double			aspect_ratio;
	t_bool			check_in;
};

struct	s_sphere
{
	t_point			center;
	double			radius;
	double			radius2;
	t_color			color;
};

struct	s_cylinder
{
	t_point			point;
	t_vec			vec;
	double			radius;
	double			height;
	t_color			color;
};

struct	s_triangle
{
	t_point			point1;
	t_point			point2;
	t_point			point3;
	t_color			color;
};

struct	s_square
{
	t_point			center;
	t_vec			vec;
	double			radius;
	t_color			color;
};

struct	s_plane
{
	t_point			point;
	t_vec			vec;
	t_color			color;
};

struct	s_light
{
	t_point			point;
	double			brightness;
	t_color			color;
};

struct		s_scene
{
	t_canvas		viewport;
	t_ambients		ambients;
	t_camera		camera;
	t_list			*cylinder;
	t_list			*sphere;
	t_list			*triangle;
	t_list			*square;
	t_list			*plane;
	t_list			*light;
};

struct		s_lstobjects
{
	int				type;
	void			*object;
	float			reflective;
	void			*prev;
	void			*next;
};

struct		s_intersect
{
	double			sol_t;
	char			type;
	t_bool			in_out;
};


t_vec		vec(double x, double y, double z);
t_point 	point(double x, double y, double z);
t_color 	color(double r, double g, double b);
void		vset(t_vec *vec, double x, double y, double z);
double		vlength2(t_vec vec);
double		vlength(t_vec vec);
t_vec		vplus(t_vec vec, t_vec vec2);
t_vec		vplus_(t_vec vec, double x, double y, double z);
t_vec		vminus(t_vec vec, t_vec vec2);
t_vec		vminus_(t_vec vec, double x, double y, double z);
t_vec		vmult_(t_vec vec, double t);
t_vec		vmult(t_vec vec, t_vec vec2);
t_vec		vdivide(t_vec vec, double t);
double		vdot(t_vec vec, t_vec vec2);
t_vec		vcross(t_vec vec, t_vec vec2);
t_vec		vunit(t_vec vec);
int 		parse(t_scene *scene, char *line);

t_ray		ray(t_point orig, t_vec dir);
t_vec		ray_at(t_ray ray, double t);
t_vec		ray_color(t_ray ray, t_scene *scene);
double		hit_sphere(t_sphere *sp, t_ray *ray);

t_canvas	make_canvas(int width, int height);
t_camera 	make_camera(t_point point, t_vec vec, double angle);
t_ambients	make_ambients(double ratio, t_color color);
t_plane		make_plane(t_point point, t_point vec, t_color color);
t_square	make_square(t_point center, t_point vec, double radius, t_color color);
t_triangle	make_triangle(t_point point1, t_point point2, t_point point3, t_color color);
t_cylinder 	make_cylinder(t_point point, t_point vec, double radius, double height, t_color color);
t_sphere	make_sphere(t_point point,  double diameter, t_color color);
t_light		make_light(t_point point, double brightness, t_color color);

int 		set_xyz_rgb(char** input, t_vec *vec);
int			get_contents_size(char **contents);
void		free_contents(char **contents);

int         rgb_validation(t_color color);
int         vector_validation(t_vec vec);
int         angle_validation(double angle);
int         light_validation(double brightness);
int         check_positive(double num);
int         have_necessary_input(t_scene *scene);

void        report_error(int err_num);
void		write_color(t_mlx *mlx, t_vec pixel_color);

t_mlx       *mlx_initiation(t_scene *scene);
#endif
