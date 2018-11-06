/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcahier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 16:04:22 by pcahier           #+#    #+#             */
/*   Updated: 2017/11/14 16:18:09 by pcahier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strpbrk(const char *s, const char *charset)
{
	char			*ret;
	unsigned int	i;

	ret = NULL;
	i = 0;
	if (s && charset)
	{
		while (*s != '\0')
		{
			while (charset[i] != '\0')
			{
				if ((unsigned char)*s == (unsigned char)charset[i])
				{
					ret = (char*)s;
					return (ret);
				}
				i++;
			}
			i = 0;
			s++;
		}
	}
	return (ret);
}
