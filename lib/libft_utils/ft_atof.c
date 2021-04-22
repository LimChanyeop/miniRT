#include "libft.h"
#include <stdio.h>

int			ft_atod(char *str, double* dst)
 {
 	double	ent;
 	double	dec;
 	int		size;
	int		tmp;
	int		error;

	error = 0;
	-  || -  -> error
 	ft_atoi(str, &tmp);
	ent = (double)tmp;
	printf("ent = %f\n", ent);
	while (*str && *str != '.')
		str++;
	if (*str == '.')
		str++;
	// - + 부호
	error = ft_atoi(str, &tmp);
	dec = (double)tmp;
	size = ft_strlen(str);
	while (size--)
		dec /= 10;
	*dst = (ent + dec);
	printf("dst = %f\n", *dst);
		return (error);
}