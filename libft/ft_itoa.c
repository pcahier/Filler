/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcahier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 19:38:24 by pcahier           #+#    #+#             */
/*   Updated: 2017/11/22 23:09:05 by pcahier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_itoarev(char *str, unsigned int len, unsigned int neg)
{
	unsigned int	i;
	char			*strr;

	i = 0;
	if (!(strr = (char*)ft_memalloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (neg == 1)
	{
		strr[i] = '-';
		i++;
	}
	while (len - i > 0)
	{
		strr[i] = str[len - 1 - i + neg];
		i++;
	}
	strr[i] = '\0';
	return (strr);
}

static char		*ft_itoafill(char *str, int n, unsigned int i, unsigned int neg)
{
	if (n < 0)
	{
		neg = 1;
		i++;
	}
	else
		n = -n;
	while (n < 0)
	{
		str[i] = (-(n % 10) + 48);
		n = n / 10;
		i++;
	}
	return (ft_itoarev(str, i, neg));
}

char			*ft_itoa(int n)
{
	unsigned int	i;
	unsigned int	neg;
	char			str[11];

	i = 0;
	neg = 0;
	if (n == 0)
	{
		str[0] = '0';
		i++;
	}
	else
		return (ft_itoafill(str, n, i, neg));
	return (ft_itoarev(str, i, neg));
}
