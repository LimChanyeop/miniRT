#ifndef UTILS_H
# define UTILS_H

# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft.h"
# include "mlx.h"

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
typedef struct  s_scene t_scene;
typedef struct 	s_ambients t_ambients;
typedef struct	s_intersect t_intersect;
typedef int		t_bool;

# define FALSE 0
# define TRUE 1
# define PI 3.14159265
# define EPSILON 0.0001
# define SP 0
# define CY 1
# define PL 2
# define SQ 3
# define TR 4
# define LUMEN 1

struct s_vec
{
	double			x;
	double			y;
	double			z;
};

struct s_ambients
{
	float			ratio;
	t_color			color;
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
	t_bool			in;
};

struct	s_cylinder
{
	t_point			center;
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
	t_camera		*cam_selected;
	t_list			*camera;
	t_list			*cylinder;
	t_list			*sphere;
	t_list			*triangle;
	t_list			*square;
	t_list			*plane;
	t_list			*light;
	t_bool			res_in;
	t_bool			amb_in;
	t_bool			cam_in;
	t_mlx			*mlx;
};

struct		s_intersect
{
	t_point			point;
	t_vec			normal_vec;
	double			t_max;
	double			t_min;
	double			t;
	char			type;
	t_bool			in_out;
	t_color			albedo;
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
t_vec		vmin(t_vec vec1, t_vec vec2);
int 		parse(t_scene *scene, char *line);

t_ray		new_ray(t_vec orig, t_vec dir);
t_vec		ray_at(t_ray ray, double t);
t_vec		ray_color(t_ray ray, t_scene *scene);
double		hit_sphere(t_sphere *sp, t_ray *ray);

t_canvas	make_canvas(int width, int height);
t_camera 	make_camera(t_point point, t_vec vec, double angle);
t_ambients	make_ambients(double ratio, t_color color);
t_plane		make_plane(t_point point, t_point vec, t_color color);
t_square	make_square(t_point center, t_point vec, double radius, t_color color);
t_triangle	make_triangle(t_point point1, t_point point2, t_point point3, t_color color);
t_cylinder 	make_cylinder(t_point center, t_point vec, double radius, double height, t_color color);
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
t_color 	color_to_rgb(t_color color);
t_bool		t_sp_validation(double t, t_intersect *inter);

t_color		phong_lighting(t_scene *scene, t_intersect inter, t_ray ray);
t_color		get_diff_spec_li(t_intersect inter, t_light *light, t_ray ray);
t_vec		get_reflect(t_vec v, t_vec n);

void		set_inter_sp(t_sphere sp, t_ray ray, t_intersect *inter);

void 		hit_obj(t_scene *scene, t_ray ray, t_intersect *inter);
t_intersect *hit_obj_2(t_scene *scene, t_ray ray, t_intersect *inter);
void 		init_intersect(t_intersect *inter, int max);

t_bool		t_pl_validation(double t, t_intersect *inter);
double		hit_plane(t_plane *pl, t_ray *ray);
void		set_inter_pl(t_plane pl, t_ray ray, t_intersect *inter);

void		set_inter_sq(t_square sq, t_ray ray, t_intersect *inter);
double		hit_square(t_square *sq, t_ray *ray);
t_bool		t_sq_validation(double t, t_intersect *inter);
int			exit_program(void);
int			check_file_format(char *str);
t_scene 	*parse_rt(int fd);
void	init_scene(t_scene *scene);
t_intersect *hit_obj_2(t_scene *scene, t_ray ray, t_intersect *inter);
void		set_inter_cy(t_cylinder cy, t_ray ray, t_intersect *inter, t_bool in);
double		hit_cylinder(t_cylinder *cy, t_ray *ray, t_bool *in);
t_bool		t_cy_validation(double t, t_intersect *inter);

t_bool		t_tr_validation(double t, t_intersect *inter);
t_bool	hit_inside_tr(t_vec a, t_vec b, t_vec c, t_vec hit_point);
double	hit_triangle(t_triangle *tr, t_ray *ray);
void		set_inter_tr(t_triangle tr, t_ray ray, t_intersect *inter);
t_mlx 				*start_mlx(t_scene *scene);
int					handle_event(int key, t_scene *scene);
void 	check_screen_size(t_scene *scene);

int		parse_resolution(t_scene *scene, char *line);
int 	parse_ambient_light(t_scene *scene, char *line);
int 	parse_camera(t_scene *scene, char *line);
int		parse_sphere(t_scene *scene, char *line);
int		parse_cylinder(t_scene *scene, char *line);
int		parse_square(t_scene *scene, char *line);
int		parse_plane(t_scene *scene, char *line);
int		parse_light(t_scene *scene, char *line);
int			parse(t_scene *scene, char *line);
int		parse_triangle(t_scene *scene, char *line);
void		my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color);

#endif
