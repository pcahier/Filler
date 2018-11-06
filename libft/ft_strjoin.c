/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcahier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 17:06:05 by pcahier           #+#    #+#             */
/*   Updated: 2017/11/22 23:08:26 by pcahier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*cop;
	unsigned int	i;
	unsigned int	j;
	unsigned int	ls1;

	if (!s1 || !s2)
		return (NULL);
	ls1 = ft_strlen(s1);
	j = 0;
	i = 0;
	if (!(cop = (char*)ft_memalloc(sizeof(char) * (ls1 + ft_strlen(s2) + 1))))
		return (NULL);
	while (s1[i] != '\0')
	{
		cop[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		cop[i + j] = s2[j];
		j++;
	}
	cop[i + j] = '\0';
	return (cop);
}
