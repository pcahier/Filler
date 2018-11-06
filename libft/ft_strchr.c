/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcahier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 12:01:51 by pcahier           #+#    #+#             */
/*   Updated: 2017/11/09 18:07:40 by pcahier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	unsigned char	d;

	d = c;
	while (*str != '\0')
	{
		if (*str == d)
			return ((char*)str);
		str++;
	}
	if (d == 0)
		return ((char*)str);
	else
		return (NULL);
}
