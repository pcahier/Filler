/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fil_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcahier <pcahier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 20:20:01 by pcahier           #+#    #+#             */
/*   Updated: 2018/11/19 18:15:07 by pcahier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		is_spot_cold(struct s_filler *inf, struct s_fil_piec *piec,
		int x, int y)
{
	int		sum;
	int		ix;
	int		why;

	sum = 0;
	ix = 0;
	why = 0;
	while (why < piec->lin)
	{
		while (ix < piec->col)
		{
			if (piec->coord[why][ix] == '*')
				sum += inf->coord[why + y][ix + x];
			ix++;
		}
		ix = 0;
		why++;
	}
	if (sum < piec->value || piec->value == -3)
	{
		piec->value = sum;
		piec->temp_x = x;
		piec->temp_y = y;
	}
}

static void		is_spot_legal(struct s_filler *inf, struct s_fil_piec *piec,
		int x, int y)
{
	int		swi;
	int		ix;
	int		why;

	why = 0;
	swi = 0;
	while (why < piec->lin)
	{
		ix = 0;
		while (ix < piec->col)
		{
			if (piec->coord[why][ix] == '*' &&
					(inf->coord[why + y][ix + x] == -1
						|| (swi && inf->coord[why + y][ix + x] == -INTMAX)))
				return ;
			if (piec->coord[why][ix] == '*' &&
					inf->coord[why + y][ix + x] == -INTMAX)
				swi = 1;
			ix++;
		}
		why++;
	}
	if (!swi)
		return ;
	is_spot_cold(inf, piec, x, y);
}

void			put_piece(struct s_filler *inf, struct s_fil_piec *piec)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (piec->lin + y <= inf->lin)
	{
		while (piec->col + x <= inf->col)
		{
			is_spot_legal(inf, piec, x, y);
			x++;
		}
		x = 0;
		y++;
	}
	if (piec->value != -3)
		ft_printf("%d %d\n", piec->temp_y, piec->temp_x);
	else
		write(1, "0 0\n", 4);
}
