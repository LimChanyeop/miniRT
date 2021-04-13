/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clim <clim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 17:48:23 by clim              #+#    #+#             */
/*   Updated: 2021/01/07 10:13:38 by clim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		match_test(char const c1, char const *set)
{
	size_t		i;

	i = 0;
	while (set[i])
	{
		if (c1 == set[i])
			return (1);
		i++;
	}
	return (0);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	int			len;
	char		*ptr;

	if (!s1 || !set)
		return (0);
	if (!(*set))
		return ((char *)s1);
	while (match_test(*s1, set))
		s1++;
	len = ft_strlen((char *)s1) - 1;
	while (len >= 0 && match_test(s1[len], set))
		len--;
	ptr = malloc(sizeof(char) * (len + 2));
	ft_strlcpy(ptr, (char *)s1, (len + 2));
	return (ptr);
}
