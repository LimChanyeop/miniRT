/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clim <clim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 13:18:03 by clim              #+#    #+#             */
/*   Updated: 2021/01/06 12:59:31 by clim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_calloc(size_t count, size_t size)
{
	void		*ptr;

	ptr = malloc(sizeof(*ptr) * (count * size));
	if (!ptr)
		return (0);
	ft_bzero(ptr, count * size);
	return (ptr);
}
