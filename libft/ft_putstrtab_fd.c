/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrtab_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcahier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 19:18:51 by pcahier           #+#    #+#             */
/*   Updated: 2017/11/22 19:19:16 by pcahier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstrtab_fd(char **tab, int fd)
{
	unsigned int	i;

	i = 0;
	if (tab)
	{
		if (*tab)
		{
			while (tab[i][0])
			{
				ft_putstr_fd(tab[i], fd);
				ft_putchar_fd('\n', fd);
				i++;
			}
		}
	}
}
