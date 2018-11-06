/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcahier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 20:35:37 by pcahier           #+#    #+#             */
/*   Updated: 2017/11/22 20:46:42 by pcahier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddend(t_list **alst, t_list *new)
{
	t_list	*next;

	next = NULL;
	if (new)
	{
		if (*alst)
		{
			next = *alst;
			while (next->next != NULL)
			{
				next = next->next;
			}
		}
		next->next = new;
	}
}
