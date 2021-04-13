/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clim <clim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 17:52:50 by clim              #+#    #+#             */
/*   Updated: 2021/01/05 10:40:56 by clim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dst, const void *src, size_t n)
{
	char	*dst_ptr;
	char	*src_ptr;
	size_t	i;

	if (n == 0 || dst == src)
		return (dst);
	dst_ptr = (char *)dst;
	src_ptr = (char *)src;
	i = 0;
	if (src_ptr < dst_ptr)
		while (n--)
			*(dst_ptr + n) = *(src_ptr + n);
	else
		while (i < n)
		{
			*(dst_ptr + i) = *(src_ptr + i);
			i++;
		}
	return (dst);
}
