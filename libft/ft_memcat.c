/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcahier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 16:51:47 by pcahier           #+#    #+#             */
/*   Updated: 2017/11/22 18:46:05 by pcahier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcat(const void *src, const void *src2, size_t sizo,
		size_t sizt)
{
	unsigned char	*dst;
	unsigned int	i;
	unsigned int	j;
	unsigned char	*a;
	unsigned char	*b;

	i = 0;
	j = 0;
	a = (unsigned char*)src;
	b = (unsigned char*)src2;
	if (!(dst = (unsigned char *)ft_memalloc(sizt)))
		return (NULL);
	while (i < sizo)
	{
		dst[i] = a[i];
		i++;
	}
	while (i + j < sizt)
	{
		dst[i + j] = b[j];
		j++;
	}
	return (dst);
}
