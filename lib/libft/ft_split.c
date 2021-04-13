/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clim <clim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 12:09:33 by clim              #+#    #+#             */
/*   Updated: 2021/01/06 10:55:21 by clim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		allocation_test(char **ptr, int i)
{
	if (!ptr[i])
	{
		while (i >= 0)
			free(ptr[--i]);
		free(ptr);
		return (-1);
	}
	return (0);
}

static void		allocate(char **ptr, int size, char *str, char c)
{
	int			i;
	int			j;
	int			len;

	j = 0;
	i = 0;
	while (--size >= 0 && str[i])
	{
		len = 0;
		while (str[i] == c)
			i++;
		while (str[i] != c && str[i])
		{
			len++;
			i++;
		}
		ptr[j] = (char *)malloc(sizeof(char) * (len + 1));
		if (allocation_test(ptr, j) == -1)
			return ;
		ft_strlcpy(ptr[j], (char *)(str + i - len), len + 1);
		while (str[i] == c)
			i++;
		j++;
	}
	ptr[j] = 0;
}

static int		get_size(char *s, char c)
{
	char		*str;
	int			size;
	int			i;

	i = 0;
	str = (char *)s;
	size = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i] != c && str[i])
			size++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (size);
}

char			**ft_split(char const *s, char c)
{
	char		**ptr;
	int			size;

	if (!s)
		return (0);
	size = get_size((char *)s, c);
	ptr = (char **)malloc(sizeof(char *) * (size + 1));
	if (!ptr)
		return (0);
	allocate(ptr, size, (char *)s, c);
	return (ptr);
}
