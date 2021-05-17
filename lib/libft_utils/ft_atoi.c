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

int				ft_atoi(char *str, int *dst)
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
	if ((*str == '-' || *str == '+') && !*(str + 1))
		error += -1;
	if (*str == '-' || *str == '+')
		str++;
	while (ft_isdigit(*str))
		ret_num = ret_num * 10 + (*str++ - '0');
	if ((*str))
		error += -1;
	*dst = ret_num * sign;
	return (error);
}
