/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clim <clim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 11:36:32 by clim              #+#    #+#             */
/*   Updated: 2021/01/04 15:20:10 by clim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstlast(t_list *lst)
{
	t_list		*list;

	if (!lst)
		return (0);
	while (lst)
	{
		list = lst;
		lst = lst->next;
	}
	return (list);
}
