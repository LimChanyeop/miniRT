/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clim <clim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 20:45:04 by clim              #+#    #+#             */
/*   Updated: 2021/05/18 20:45:22 by clim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <math.h>

int			ft_atod(char *str, double *dst)
{
	double	dec;
	int		en_sz_sn_tp[4];

	en_sz_sn_tp[2] = 1;
	if (*str == '-' && !*(str + 1))
		return (-1);
	ft_atoi(str, &en_sz_sn_tp[0]);
	if (*str == '-')
		en_sz_sn_tp[2] = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (ft_isdigit(*str))
		str++;
	if (!(*str == '\0' || *str == '.'))
		return (-1);
	if (*str == '.')
		str++;
	if (*str == '-' || (*(str - 1) == '.' && !*str) \
					|| ft_atoi(str, &en_sz_sn_tp[3]) < 0)
		return (-1);
	dec = en_sz_sn_tp[3];
	en_sz_sn_tp[1] = ft_strlen(str);
	return (ft_atod2(en_sz_sn_tp, dec, dst));
}

int			ft_atod2(int *en_sz_sn_tp, double dec, double *dst)
{
	while (en_sz_sn_tp[1]--)
		dec /= 10;
	*dst = ((abs(en_sz_sn_tp[0]) + dec) * en_sz_sn_tp[2]);
	return (0);
}
