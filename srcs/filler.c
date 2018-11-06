/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcahier <pcahier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 11:04:10 by pcahier           #+#    #+#             */
/*   Updated: 2018/11/06 14:44:56 by pcahier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		main(void)
{
	char			*line;
	static int		i = -1;

	while (1)
	{
		if (i == -1)
		{
			get_next_line(0, &line);
			i = line[10] - '0';
		}
		if (i == 1)
			ft_putendl("1 2");
		else
			ft_putendl("5 13");
	}
	return (0);
}	
