/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_caesarcrypt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcahier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 23:36:26 by pcahier           #+#    #+#             */
/*   Updated: 2017/11/22 23:43:52 by pcahier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_caesarcrypt(char *str, int nb)
{
	unsigned int	i;

	i = 0;
	if (str)
		while (str[i])
		{
			if (ft_islower(str[i]))
			{
				str[i] += nb;
				while (str[i] > 'z')
					str[i] -= 26;
				while (str[i] < 'a')
					str[i] += 26;
			}
			if (ft_isupper(str[i]))
			{
				str[i] += nb;
				while (str[i] > 'Z')
					str[i] -= 26;
				while (str[i] < 'A')
					str[i] += 26;
			}
			i++;
		}
	return (str);
}
