#include "libft.h"
#include <stdio.h>
#include <math.h>

int			ft_atod(char *str, double* dst)
{
 	int		ent;
 	double	dec;
 	int		size;
	int		sign;
	int 	tmp;

	sign = 1;
	if (*str == '-' && !*(str + 1))
		return (-1);
 	ft_atoi(str, &ent);
	if (*str == '-')
		sign = -1;
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
	dec = tmp;
	size = ft_strlen(str);
	while (size--)
		dec /= 10;
	*dst = ((abs(ent) + dec) * sign);
	return (0);
}