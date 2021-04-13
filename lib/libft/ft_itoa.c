/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clim <clim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 10:36:45 by clim              #+#    #+#             */
/*   Updated: 2021/01/06 13:08:53 by clim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		allocate(char *arr, char *a, int idx)
{
	int			i;

	i = 0;
	while (idx >= 0)
		a[i++] = arr[idx--];
	a[i] = 0;
}

char			*ft_itoa(int n)
{
	char		*a;
	char		arr[12];
	int			idx;
	int			neg;

	ft_bzero(arr, 12);
	neg = n < 0 ? -1 : +1;
	if ((int)n == (int)-2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	if (neg == -1)
		n *= -1;
	idx = 0;
	while (n > 0)
	{
		arr[idx++] = n % 10 + '0';
		n = n / 10;
	}
	if (neg == -1)
		arr[idx++] = '-';
	if (!(a = (char *)malloc(sizeof(char) * (ft_strlen((char *)arr) + 1))))
		return (0);
	allocate((char *)arr, a, idx - 1);
	return (a);
}
