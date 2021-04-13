/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clim <clim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 14:56:28 by clim              #+#    #+#             */
/*   Updated: 2021/01/06 12:47:04 by clim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t				ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	char			*dest_ptr;
	char			*src_ptr;
	size_t			dest_len;
	size_t			i;

	src_ptr = (char *)src;
	dest_ptr = dest;
	i = dstsize;
	while (*dest && (i-- != 0))
		dest++;
	dest_len = dest - dest_ptr;
	i = dstsize - dest_len;
	if (i == 0)
		return (dest_len + ft_strlen(src_ptr));
	while (*src != '\0')
	{
		if (i > 1)
		{
			*dest++ = *src;
			i--;
		}
		src++;
	}
	*dest = '\0';
	return (dest_len + ft_strlen(src_ptr));
}
