#ifndef utils_H
# define utils_H

# include <math.h>
# include <stdlib.h>
# include "structures.h"
# include "stdio.h"

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
t_vec	vmult(t_vec vec, double t);
t_vec	vmult_(t_vec vec, t_vec vec2);
t_vec	vdivide(t_vec vec, double t);
double	vdot(t_vec vec, t_vec vec2);
t_vec	vcross(t_vec vec, t_vec vec2);
t_vec	vunit(t_vec vec);


#endif