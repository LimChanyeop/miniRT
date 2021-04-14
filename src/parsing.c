#include "libft.h"
#include "utils.h"
#include <stdio.h>

int				ft_isnum(char c)
{
	return(c >= '0' && c <= '9');
}

int				ft_isspace(char c)
{
	return((c >= 9 && c <= 13) || (c == 32));
}
int			stoi(char **str)
{
	int i;
	int	neg;

	i = 0;
	neg = 1;
	if (**str == '-' && *((*str)++))
		neg = -1;
	while (ft_isnum(**str))
		i = i * 10 + (*((*str)++) - '0');
	return (i * neg);
}

static void parse_resolution(t_scene *data, char **line)
{
	char *str;

	str = *line;
	while(ft_isspace(*str))
		str++;
	data->res_x = stoi(&str);
	while(ft_isspace(*str))
		str++;
	data->res_y = stoi(&str);
	printf("x = %d y = %d\n", data->res_x, data->res_y);
}

void parse(t_scene *data, char **line)
{
	char *str;

	str = *line;
	if (*str == 'R' && *(str++))
		parse_resolution(data, &str);
}
