/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcahier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 18:57:14 by pcahier           #+#    #+#             */
/*   Updated: 2017/11/13 13:54:57 by pcahier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*s2;
	unsigned int	i;

	if (!s)
		return (NULL);
	if (!(s2 = ft_strdup(s)))
		return (NULL);
	i = 0;
	while (s2[i])
	{
		s2[i] = f(i, s2[i]);
		i++;
	}
	return (s2);
}
