/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcahier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 01:56:58 by pcahier           #+#    #+#             */
/*   Updated: 2018/01/18 20:20:39 by pcahier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_itoa_print_form(char *str, size_t len,
					t_stru *stru)
{
	char			*strr;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (!(strr = (char*)ft_memalloc(sizeof(char) * (len + stru->wid_min + 2))))
		return (NULL);
	while ((!stru->zero || stru->pre != -1) && stru->wid_min > 0)
	{
		strr[i++] = ' ';
		stru->wid_min--;
	}
	while (str[j] != '\0')
	{
		strr[i++] = str[j++];
	}
	strr[i] = '\0';
	free(str);
	return (strr);
}

static char		*ft_itoa_print_forml(char *str, size_t len,
					t_stru *stru)
{
	char			*strr;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (!(strr = (char*)ft_memalloc(sizeof(char) * (len + stru->wid_min + 2))))
		return (NULL);
	while (str[j] != '\0')
		strr[i++] = str[j++];
	while (!stru->zero && stru->wid_min)
	{
		strr[i++] = ' ';
		stru->wid_min--;
	}
	strr[i] = '\0';
	free(str);
	return (strr);
}

static char		*ft_itoarev(char *str, unsigned int len, t_stru *stru,
						int check)
{
	size_t		i;
	char		*strr;

	i = 0;
	if ((stru->pound == 1 && (stru->base == 8 || (check &&
				(stru->base == 16 || stru->base == 2)))) || stru->conv == 5)
		str[len++] = '0';
	if (!(strr = (char*)ft_memalloc(sizeof(char) * (len + 2))))
		return (NULL);
	while (len - i > 0)
	{
		strr[i] = str[(len - 1 - i)];
		i++;
	}
	strr[i] = '\0';
	free(str);
	stru->len = ft_strlen(strr);
	if (stru->len < stru->wid_min)
		stru->wid_min -= stru->len;
	else
		stru->wid_min = 0;
	if (stru->l_just)
		return (ft_itoa_print_forml(strr, i, stru));
	else
		return (ft_itoa_print_form(strr, i, stru));
}

static char		*ft_itoafill(char *str, uintmax_t n,
					unsigned int i, t_stru *stru)
{
	int	check;

	check = n ? 1 : 0;
	while (n > 0)
	{
		str[i] = (n % stru->base) + ((n % stru->base) > 9 ? 87 : 48);
		n = n / stru->base;
		i++;
	}
	while (stru->pre > (stru->len - (stru->conv == 5 ? 2 : 0)))
	{
		str[i++] = '0';
		stru->pre--;
	}
	while (stru->zero && (stru->wid_min > (int)i) && !stru->l_just)
		str[i++] = '0';
	if ((stru->pound == 1 && check) || stru->conv == 5)
	{
		if (stru->base == 16)
			str[i++] = 'x';
		else if (stru->base == 2)
			str[i++] = 'b';
	}
	return (ft_itoarev(str, i, stru, check));
}

char			*ft_uitoa_print(uintmax_t n, t_stru *stru, int base)
{
	uintmax_t		i;
	char			*str;
	unsigned int	neg;

	neg = 0;
	stru->base = base;
	if (!(str = (char*)ft_memalloc(sizeof(char) *
					(stru->len + stru->pre + stru->wid_min + 4))))
		return (NULL);
	i = 0;
	if (n == 0 && stru->pre && !(stru->pre == -1 && base == 8 && stru->pound))
		str[i++] = '0';
	if ((stru->zero || base == 8) && stru->pound)
	{
		if (base == 16 || base == 2)
			stru->wid_min -= 2;
		if (base == 8)
			stru->pre -= 1;
	}
	return (ft_itoafill(str, n, i, stru));
}
