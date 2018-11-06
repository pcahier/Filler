/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcahier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 00:09:15 by pcahier           #+#    #+#             */
/*   Updated: 2017/11/23 00:16:50 by pcahier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strspn(const char *s, const char *charset)
{
	size_t	i;
	size_t	j;
	int		check;

	i = 0;
	j = 0;
	check = 0;
	if (s && charset)
	{
		while (s[i] != '\0')
		{
			while (charset[j] != '\0')
			{
				if ((s[i] == charset[j]))
					check = 1;
				j++;
			}
			if (check == 0)
				return (i);
			check = 0;
			j = 0;
			i++;
		}
	}
	return (i);
}
