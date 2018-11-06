/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stralnumwrdcnt.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcahier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 13:22:59 by pcahier           #+#    #+#             */
/*   Updated: 2017/11/14 13:28:39 by pcahier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_stralnumwrdcnt(char const *str)
{
	unsigned int	i;
	unsigned int	count;
	unsigned int	swi;

	i = 0;
	count = 0;
	swi = 1;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		if (ft_isalnum(str[i]))
		{
			if (swi)
				count++;
			swi = 0;
		}
		else
			swi = 1;
		i++;
	}
	return (count);
}
