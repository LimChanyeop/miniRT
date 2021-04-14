/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clim <clim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 13:30:19 by clim              #+#    #+#             */
/*   Updated: 2021/04/14 19:50:31 by clim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strdup(const char *s1)
{
	char			*ptr;
	size_t			i;
	size_t			len;

	len = ft_strlen((char *)s1);
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (0);
	i = 0;
	while (i < len + 1)
	{
		*(unsigned char *)(ptr + i) = *(unsigned char *)(s1 + i);
		i++;
	}
	return (ptr);
}

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

size_t				ft_strlen(const char *str)
{
	int				count;

	count = 0;
	while (*str != '\0')
	{
		str++;
		count++;
	}
	return (count);
}

char				*ft_strjoin(char *s1, char *s2)
{
	char			*ptr;
	size_t			s1_len;
	size_t			s2_len;

	if (!s1 && !s2)
		return (0);
	//else if (!s1 || !s2)
	//	return (!s1 ? ft_strdup(s2) : ft_strdup(s1));
	s1_len = ft_strlen((char *)s1);
	s2_len = ft_strlen((char *)s2);
	ptr = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!ptr)
		return (0);
	ft_strlcpy((char *)ptr, (char *)s1, s1_len + 1);
	ft_strlcat((char *)ptr, (char *)s2, s1_len + s2_len + 1);
	return (ptr);
}
