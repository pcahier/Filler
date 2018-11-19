/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filheat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcahier <pcahier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 16:05:59 by pcahier           #+#    #+#             */
/*   Updated: 2018/11/19 16:43:12 by pcahier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	heat_around(struct s_filler *inf, int y, int x)
{
	if (x > 0 && inf->coord[y][x - 1] == INTMAX)
		inf->coord[y][x - 1] = inf->coord[y][x] + 1;
	if (y > 0 && inf->coord[y - 1][x] == INTMAX)
		inf->coord[y - 1][x] = inf->coord[y][x] + 1;
	if (x + 1 < inf->col && inf->coord[y][x + 1] == INTMAX)
		inf->coord[y][x + 1] = inf->coord[y][x] + 1;
	if (y + 1 < inf->lin && inf->coord[y + 1][x] == INTMAX)
		inf->coord[y + 1][x] = inf->coord[y][x] + 1;
	return (0);
}

static void	heat_it_up(struct s_filler *inf, int min_val)
{
	int		x;
	int		y;
	char	swi;

	x = -1;
	y = -1;
	swi = 0;
	while (swi == 0)
	{
		swi = 1;
		while (++y < inf->lin)
		{
			while (++x < inf->col)
			{
				if (inf->coord[y][x] == min_val)
					swi = heat_around(inf, y, x);
			}
			x = -1;
		}
		min_val++;
		y = -1;
	}
}

void		fil_heat(struct s_filler *inf)
{
	int		x;
	int		y;
	int		min_val;

	min_val = -1;
	heat_it_up(inf, min_val);
	x = 0;
	y = 0;
	while (y < inf->lin)
	{
		while (x < inf->col)
		{
			if(inf->coord[y][x] == INTMAX)
				ft_errprintf("%s", "LIB");
			else if (inf->coord[y][x] / 100)
				ft_errprintf("{cyan}%3d{eoc} ", inf->coord[y][x]);
			else if (inf->coord[y][x] / 75)
				ft_errprintf("{green}%3d{eoc} ", inf->coord[y][x]);
			else if (inf->coord[y][x] / 50)
				ft_errprintf("{yellow}%3d{eoc} ", inf->coord[y][x]);
			else if (inf->coord[y][x] > -1)
				ft_errprintf("{magenta}%3d{eoc} ", inf->coord[y][x]);
			else if (inf->coord[y][x] == -2)
				ft_errprintf("{black}%3d{eoc} ", inf->coord[y][x]);
			else
				ft_errprintf("{red}%3d{eoc} ", inf->coord[y][x]);
			x++;
		}
		ft_errprintf("\n");
		x = 0;
		y++;
	}
}
