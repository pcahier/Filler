/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcahier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 17:50:31 by pcahier           #+#    #+#             */
/*   Updated: 2017/11/22 23:08:47 by pcahier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char				**ft_split(char *cop, unsigned int *tab, int count)
{
	unsigned int	i;
	char			**slice;

	if (!(slice = (char**)ft_memalloc(sizeof(char*) * (count + 1))))
		return (NULL);
	i = 0;
	while (count > 0)
	{
		slice[i] = ft_strdup(cop + tab[i]);
		i++;
		count--;
	}
	slice[i] = 0;
	free(cop);
	free(tab);
	return (slice);
}

static unsigned int		*ft_refsplit(unsigned int *tab, char *cop, char c,
	unsigned int count)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	swi;

	i = 0;
	j = 0;
	swi = 1;
	if (!(tab = (unsigned int*)ft_memalloc(sizeof(int) * count + 1)))
		return (NULL);
	while (cop[i] != '\0')
	{
		if (cop[i] != c && swi == 1)
		{
			tab[j] = i;
			swi = 0;
			j++;
		}
		else if (cop[i] == c)
		{
			cop[i] = '\0';
			swi = 1;
		}
		i++;
	}
	return (tab);
}

static unsigned int		ft_refchainnb(char const *s, char c)
{
	unsigned int		i;
	unsigned int		swi;

	i = 0;
	swi = 1;
	while (*s != '\0')
	{
		if (*s != c && swi == 1)
		{
			i++;
			swi = 0;
		}
		else if (*s == c)
			swi = 1;
		s++;
	}
	return (i);
}

char					**ft_strsplit(char const *s, char c)
{
	unsigned int	len;
	unsigned int	count;
	unsigned int	*tab;
	char			*cop;

	if (!s)
		return (NULL);
	tab = NULL;
	len = ft_strlen(s);
	count = ft_refchainnb(s, c);
	cop = ft_strdup(s);
	tab = ft_refsplit(tab, cop, c, count);
	return (ft_split(cop, tab, count));
}
