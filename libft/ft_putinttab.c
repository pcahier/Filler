/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putinttab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcahier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 19:07:34 by pcahier           #+#    #+#             */
/*   Updated: 2017/11/22 19:07:37 by pcahier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putinttab(int *tab, size_t size)
{
	unsigned int	i;

	i = 0;
	if (tab)
	{
		while (i < size)
		{
			ft_putnbr(tab[i]);
			if (i + 1 < size)
				write(1, ", ", 2);
			i++;
		}
		ft_putchar('\n');
	}
}
