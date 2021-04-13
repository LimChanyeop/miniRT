/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clim <clim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 12:59:19 by clim              #+#    #+#             */
/*   Updated: 2021/01/06 13:01:45 by clim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strdup(const char *s1)
{
	char		*ptr;

	ptr = (char *)malloc(sizeof(char) * ft_strlen((char *)s1) + 1);
	if (!ptr)
		return (0);
	ft_memcpy((char *)ptr, (char *)s1, ft_strlen((char *)s1) + 1);
	return (ptr);
}
