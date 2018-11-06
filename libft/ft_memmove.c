/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcahier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:42:14 by pcahier           #+#    #+#             */
/*   Updated: 2017/11/13 11:26:01 by pcahier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*a;
	unsigned char	*b;
	int				i;

	i = 0;
	a = (unsigned char*)dst;
	b = (unsigned char*)src;
	if ((unsigned int)dst > (unsigned int)src)
	{
		i = len - 1;
		while (i >= 0)
		{
			a[i] = b[i];
			i--;
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
