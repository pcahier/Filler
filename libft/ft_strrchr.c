/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcahier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 12:10:43 by pcahier           #+#    #+#             */
/*   Updated: 2017/11/13 16:10:03 by pcahier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char			*stock;
	unsigned char	d;

	d = (unsigned char)c;
	stock = NULL;
	while (*str != '\0')
	{
		if ((unsigned char)*str == d)
			stock = (char*)str;
		str++;
	}
	if (d == 0)
		return ((char*)str);
	else
		return (stock);
}
