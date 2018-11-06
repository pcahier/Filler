/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putinttab_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcahier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 19:07:44 by pcahier           #+#    #+#             */
/*   Updated: 2017/11/22 19:09:13 by pcahier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putinttab_fd(int *tab, size_t size, int fd)
{
	unsigned int	i;

	i = 0;
	if (tab)
	{
		while (i < size)
		{
			ft_putnbr_fd(tab[i], fd);
			if (i + 1 < size)
				write(fd, ", ", 2);
			i++;
		}
		ft_putchar_fd('\n', fd);
	}
}
