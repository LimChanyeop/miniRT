#include "utils.h"

void 			hit_obj(t_scene *scene, t_ray ray, t_intersect *inter)
{
    t_list 		*object;

    object = scene->sphere;
	while(object != 0)
	{
		if (t_sp_validation(hit_sphere(object->content, &ray), inter) == TRUE)
			set_inter_sp(*(t_sphere *)object->content, ray, inter);
		object = object->next;
	}
    object = scene->square;
    while(object != 0)
	{
		if (t_sq_validation(hit_square(object->content, &ray), inter) == TRUE)
			set_inter_sq(*(t_square *)object->content, ray, inter);
		object = object->next;
	}
	object = scene->triangle;
    while(object != 0)
	{
		if (t_tr_validation(hit_triangle(object->content, &ray), inter) == TRUE)
			set_inter_tr(*(t_triangle *)object->content, ray, inter);
		object = object->next;
	}
    inter = hit_obj_2(scene, ray, inter);
}

t_intersect 	*hit_obj_2(t_scene *scene, t_ray ray, t_intersect *inter)
{   
	t_list 		*object;
	t_bool 		in;

	object = scene->plane;
    while(object != 0)
	{
		if (t_pl_validation(hit_plane(object->content, &ray), inter) == TRUE)
			set_inter_pl(*(t_plane *)object->content, ray, inter);
		object = object->next;
	}
    object = scene->cylinder;
    while(object != 0)
	{
		in = FALSE;
		if (t_cy_validation(hit_cylinder(object->content, &ray, &in), inter) == TRUE)
			set_inter_cy(*(t_cylinder *)object->content, ray, inter, in);
		object = object->next;
	}
    return (inter);
}
