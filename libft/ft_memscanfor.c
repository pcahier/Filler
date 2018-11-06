/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memscanfor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcahier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 16:36:08 by pcahier           #+#    #+#             */
/*   Updated: 2017/11/24 16:43:26 by pcahier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memscanfor(const void *s, int c, size_t len)
{
	unsigned char	d;
	unsigned char	*a;

	d = (unsigned char)c;
	a = (unsigned char*)s;
	while (len > 0)
	{
		if (*a == d)
			return ((void*)a);
		a++;
	}
	return (NULL);
}
