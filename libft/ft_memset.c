/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcahier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 14:22:23 by pcahier           #+#    #+#             */
/*   Updated: 2017/11/13 15:20:06 by pcahier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*str;
	unsigned char	a;
	unsigned int	i;

	a = c;
	i = 0;
	str = (unsigned char*)b;
	while (len > i)
	{
		str[i] = a;
		i++;
	}
	return (b);
}
