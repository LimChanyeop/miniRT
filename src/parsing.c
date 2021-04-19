#include "libft.h"
#include "utils.h"
#include <stdio.h>

int			stoi(char **str)
{
	int i;
	int	neg;

	i = 0;
	neg = 1;
	if (**str == '-' && *((*str)++))
		neg = -1;
	while (ft_isdigit(**str))
		i = i * 10 + (*((*str)++) - '0');
	return (i * neg);
}

/*static void parse_resolution(t_scene *data, char **line)
{
	
}*/

int		parse_resolution(t_scene *scene, char *line)
{
	int i;
	int r;
	int res_x;
	int res_y;
 	printf("func\n");
	i = 1;
	if (!ft_isspace(line[i]))
		return (-1);
	while (ft_isspace(line[i]))
		i++;
	if (ft_isdigit(line[i]) || (r = ft_atoi(&line[i], &res_x)) < 0)
	{	
		printf("i = %d\n", i);
		return (-1);
	}
	if ((i += r-1) > 0 && ft_isspace(line[i]))
		return (-1);
	while (ft_isdigit(line[i]))
		i++;
	printf("res_x = %d\n", res_x);
	if (ft_isdigit(line[i]) || (r = ft_atoi(&line[i], &res_y)) < 0)
		return (-1);
	i += r;
	while (ft_isdigit(line[i]))
		if (line[++i] && ft_isspace(line[i]))
			return (-1);
	scene->viewport = make_canvas(res_x, res_y);
	return (1);
}


int			parse(t_scene *scene, char *line)
{
	
	if (line[0] != '\0')
	{
		if (line[0] == 'R')
			parse_resolution(scene, line);
		/*else if (line[0] == 'A')
			return (parse_ambient_light(scene, line));
		else if (line[0] == 'c' && line[1] == 'y')
			return (parse_cylinder(scene, line));
		else if (line[0] == 'c')
			return (parse_camera(scene, line));
		else if (line[0] == 'l')
			return (parse_point_light(scene, line));
		else if (line[0] == 's' && line[1] == 'p')
			return (parse_sphere(scene, line));
		else if (line[0] == 's' && line[1] == 'q')
			return (parse_square(scene, line));
		else if (line[0] == 'p' && line[1] == 'l')
			return (parse_plan(scene, line));
		else if (line[0] == 't' && line[1] == 'r')
			return (parse_triangle(scene, line));
		else
			return (-1);
			*/
		printf("x = %d y = %d\n", (scene)->viewport.width, (scene)->viewport.height);
	}
	return (0);
}
