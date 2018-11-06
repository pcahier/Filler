/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcahier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 11:22:44 by pcahier           #+#    #+#             */
/*   Updated: 2017/11/14 11:33:07 by pcahier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcapitalize(char *str)
{
	unsigned int	i;
	unsigned int	swi;

	i = 0;
	swi = 1;
	if (!str)
		return (NULL);
	ft_strlowcase(str);
	while (str[i] != '\0')
	{
		if (ft_isalnum(str[i]))
		{
			if (ft_islower(str[i]) && swi)
				str[i] -= 32;
			swi = 0;
		}
		else if (!(ft_isalnum(str[i])))
			swi = 1;
		i++;
	}
	return (str);
}
