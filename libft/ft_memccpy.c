/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcahier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:29:55 by pcahier           #+#    #+#             */
/*   Updated: 2017/11/13 15:28:57 by pcahier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*a;
	unsigned char	*b;
	unsigned int	i;

	a = (unsigned char*)dst;
	b = (unsigned char*)src;
	i = 0;
	while (n > i)
	{
		if (b[i] == (unsigned char)c)
		{
			a[i] = b[i];
			return (dst + i + 1);
		}
		a[i] = b[i];
		i++;
	}
	return (NULL);
}
