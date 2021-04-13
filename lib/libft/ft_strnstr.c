/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clim <clim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 22:49:54 by clim              #+#    #+#             */
/*   Updated: 2021/01/06 12:49:54 by clim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strnstr(const char *haystack, const char *needle, \
																size_t len)
{
	size_t			i;

	if (!(*needle))
		return ((char *)haystack);
	i = 0;
	while (*(haystack + i) && i + ft_strlen((char *)needle) <= len)
	{
		if (ft_memcmp((haystack + i), needle, ft_strlen((char *)needle)) == 0)
			return ((char *)(haystack + i));
		i++;
	}
	return (0);
}
