#include "libft.h"

int			ft_atof(char *str, float* dst) // double
 {
 	float	ent;
 	float	dec;
 	int		size;
	int		tmp;

 	ft_atoi(str, &tmp);
	ent = (float)tmp;
 	while (*str && *str != '.')
 		str++;
 	if (*str == '.')
 		str++;
 	ft_atoi(str, &tmp);
	dec = (float)tmp;
 	size = ft_strlen(str);
 	while (size--)
 		dec /= 10;
 	*dst = ((ent + dec) * 1);
	return (1);
 }