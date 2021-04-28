#include "libft.h"
#include <stdio.h>

int			ft_atod(char *str, double* dst)
{
 	double	ent;
 	double	dec;
 	int		size;
	int		tmp;

	if (*str == '-' && !*(str + 1))
		return (-1);
 	ft_atoi(str, &tmp);
	ent = (double)tmp;
	if (*str == '-' || *str == '+')
		str++;
	while (ft_isdigit(*str))
		str++;
	if (!(*str == '\0' || *str == '.'))
		return (-1);
	if (*str == '.')
		str++;
	if (*str == '-' || (*(str - 1) == '.' && !*str) \
									|| ft_atoi(str, &tmp) < 0)
		return (-1);
	dec = (double)tmp;
	size = ft_strlen(str);
	while (size--)
		dec /= 10;
	*dst = (ent + dec);
	return (0);
}