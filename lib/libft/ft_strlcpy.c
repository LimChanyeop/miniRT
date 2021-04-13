/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clim <clim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 14:39:03 by clim              #+#    #+#             */
/*   Updated: 2021/01/06 12:45:28 by clim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t			i;
	size_t			count;

	if (!dst || !src)
		return (0);
	i = 0;
	count = 0;
	while (src[i])
		i++;
	if (dstsize == 0)
		return (i);
	while ((count < i) && (count < dstsize - 1))
	{
		dst[count] = src[count];
		count++;
	}
	dst[count] = '\0';
	return (i);
}
