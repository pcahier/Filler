/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcahier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 19:16:40 by pcahier           #+#    #+#             */
/*   Updated: 2017/11/13 14:05:25 by pcahier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strlendigit(const char *nb)
{
	size_t	i;

	i = 0;
	while (ft_isdigit(nb[i]))
		i++;
	return (i);
}

static int		ft_nbcmp(const char *nb, int i)
{
	char	lmax[20];
	size_t	j;

	j = 0;
	if (i == 1)
		ft_strcpy(lmax, "9223372036854775807");
	else
		ft_strcpy(lmax, "9223372036854775808");
	if (ft_strlendigit(nb) > 19)
		return (i > 0 ? -1 : 0);
	else if (ft_strlendigit(nb) == 18)
		while ((nb[j] != '\0' || lmax[j] != '\0') && ft_isdigit(nb[j]))
		{
			if (nb[j] > lmax[j])
				return (i > 0 ? -1 : 0);
			else if (nb[j] == lmax[j])
				j++;
			else if (nb[j] < lmax[j])
				break ;
		}
	return (1);
}

static int		ft_atoi_convert(int i, const char *str)
{
	int		res;

	res = 0;
	while (ft_isdigit(*str))
	{
		res = (res * 10) + (*str - 48);
		str++;
	}
	return (res * i);
}

int				ft_atoi(const char *str)
{
	int		i;
	int		c;

	i = 1;
	if (*str)
	{
		while (ft_isspace(*str))
			str++;
		if (*str == '-' || *str == '+')
		{
			if (*str == '-')
				i = -1;
			str++;
		}
		if (!ft_isdigit(*str))
			return (0);
		else if ((c = ft_nbcmp(str, i)) > 0)
			return (ft_atoi_convert(i, str));
		else
			return (c);
	}
	return (0);
}
