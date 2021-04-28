#include "utils.h"
#include "libft.h"

int 		set_xyz_rgb(char** input, t_vec *vec)
{
	int		error;

	error = 0;
	if (!input || get_contents_size(input) != 3)
		return (-1);
	error += ft_atod(input[0], &vec->x);
	error += ft_atod(input[1], &vec->y);
	error += ft_atod(input[2], &vec->z);
	return (error);
}

int		get_contents_size(char **contents)
{
	int i;

	i = 0;
	while (contents[i])
		i++;
	return (i);
}

void		free_contents(char **contents)
{
	int	i;

	i = 0;
	while(contents[i])
		free(contents[i++]);
	free(contents);
}