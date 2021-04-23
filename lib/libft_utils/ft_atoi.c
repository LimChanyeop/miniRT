/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clim <clim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 13:43:31 by clim              #+#    #+#             */
/*   Updated: 2021/01/06 16:17:43 by clim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

/*static int		input_test(int sign, char *str)
{
	int			i;
	char		max[20];

	ft_strlcpy((char *)max, "9223372036854775808", 20);
	if (sign == 1)
		max[19] = '7';
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		i++;
	}
	if ((i == 19 && ft_strncmp(max, str, 19) < 0) || i > 19)
	{
		if (sign == -1)
			return (0);
		if (sign == 1)
			return (-1);
	}
	return (1);
}*/

int				ft_atoi(char *str, int *dst) // only - 
{
	int			sign;
	int			ret_num;
	int			i;
	int			error;

	error = 0;
	i = 0;
	ret_num = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	//if (input_test(sign, (char *)str) != 1)
	//	return (input_test(sign, (char *)str));
	while (ft_isdigit(*str))
		ret_num = ret_num * 10 + (*str++ - '0');
	if ((*str))
	 	error = -1;
	*dst = ret_num * sign;
	return (error);
}
