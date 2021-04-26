#include "libft.h"
#include <stdio.h>

int			ft_atod(char *str, double* dst)
{
 	double	ent;
 	double	dec;
 	int		size;
	int		tmp;
	int		error;
	int		sign = 1;

	error = 0;
	if (*str == '-' && !*(str + 1))
		error = -1;
	if (*str == '-')
		sign = -1;
 	ft_atoi(str, &tmp);
	ent = (double)tmp;
	while (*str && *str != '.')
		str++;
	if (*str == '.')
		str++;
	if (*str == '-')
		error = -1;
	error = ft_atoi(str, &tmp);
	dec = (double)tmp;
	size = ft_strlen(str);
	while (size--)
		dec /= 10;
	*dst = (ent + dec) * sign;
	return (error);
}