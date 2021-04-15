/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_space.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clim <clim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 12:09:33 by clim              #+#    #+#             */
/*   Updated: 2021/04/15 20:54:23 by clim             ###   ########.fr       */
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

static void		allocate(char **ptr, int size, char *str)
{
	int			i;
	int			j;
	int			len;

	j = 0;
	i = 0;
	while (--size >= 0 && str[i])
	{
		len = 0;
		while (ft_isspace(str[i]))
			i++;
		while (!(ft_isspace(str[i])) && str[i])
		{
			len++;
			i++;
		}
		ptr[j] = (char *)malloc(sizeof(char) * (len + 1));
		if (allocation_test(ptr, j) == -1)
			return ;
		ft_strlcpy(ptr[j], (char *)(str + i - len), len + 1);
		while (ft_isspace(str[i]))
			i++;
	j++;
	}
	ptr[j] = 0;
}

static int		get_size(char *s)
{
	char		*str;
	int			size;
	int			i;

	i = 0;
	str = (char *)s;
	size = 0;
	while (str[i])
	{
		while (ft_isspace(str[i]))
			i++;
		if (!(ft_isspace(str[i])) && str[i])
			size++;
		while (str[i] && !(ft_isspace(str[i])))
			i++;
	}
	return (size);
}

char			**ft_split_space(char const *s)
{
	char		**ptr;
	int			size;

	size = get_size((char *)s);
	ptr = (char **)malloc(sizeof(char *) * (size + 1));
	if (!ptr)
		return (0);
	allocate(ptr, size, (char *)s);
	return (ptr);
}
