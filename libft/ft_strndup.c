/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcahier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 23:11:20 by pcahier           #+#    #+#             */
/*   Updated: 2017/11/22 23:10:10 by pcahier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char	*str;

	str = NULL;
	if (ft_strlen(s1) <= n)
	{
		if (!(str = (char *)ft_memalloc(sizeof(char) * (ft_strlen(s1) + 1))))
			return (NULL);
		str = ft_strcpy(str, s1);
	}
	else
	{
		if (!(str = (char *)ft_memalloc(sizeof(char) * (n + 1))))
			return (NULL);
		str = ft_strncpy(str, s1, n);
		str[n] = '\0';
	}
	return (str);
}
