/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcahier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 17:54:52 by pcahier           #+#    #+#             */
/*   Updated: 2017/11/13 13:53:12 by pcahier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
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
		s2[i] = f(s2[i]);
		i++;
	}
	return (s2);
}
