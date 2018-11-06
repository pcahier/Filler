/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcahier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 18:15:53 by pcahier           #+#    #+#             */
/*   Updated: 2017/11/22 16:37:07 by pcahier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	l;
	unsigned int	j;
	int				s;

	s = 0;
	l = ft_strlen(dst);
	j = 0;
	while (src[j] && size > (l + j + 1))
	{
		dst[l + j] = src[j];
		j++;
	}
	if (l < size)
	{
		dst[l + j] = '\0';
		return (l + ft_strlen(src));
	}
	return (size + ft_strlen(src));
}
