/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcahier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 21:43:49 by pcahier           #+#    #+#             */
/*   Updated: 2017/11/13 22:32:07 by pcahier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*newl;

	newl = NULL;
	if (lst && f)
	{
		if (!(newl = (t_list*)malloc(sizeof(t_list))))
			return (NULL);
		newl = f(lst);
		if (lst->next)
			if (!(newl->next = ft_lstmap(lst->next, f)))
				return (NULL);
	}
	return (newl);
}
