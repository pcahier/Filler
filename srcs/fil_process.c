/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fil_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcahier <pcahier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 18:02:42 by pcahier           #+#    #+#             */
/*   Updated: 2018/11/19 16:08:12 by pcahier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		free_piece(struct s_fil_piec *piec)
{
	while (piec->lin >= 0)
	{
		free(piec->coord[piec->lin]);
		piec->lin--;
	}
	free(piec->coord);
}

static void		take_piece(char *line, struct s_fil_piec *piec)
{
	int			x;
	int			y;

	x = 0;
	y = 0;
	while (y < piec->lin)
	{
		get_next_line(0, &line);
		while (x < piec->col)
		{
			piec->coord[y][x] = line[x];
			x++;
		}
		x = 0;
		y++;
		free(line);
	}
}

static int		init_piece(char *line, struct s_fil_piec *piec)
{
	int		i;

	i = 0;
	get_next_line(0, &line);
	piec->lin = ft_atoi(line + 6);
	piec->col = ft_atoi(line + 6 + ft_decnumlen(piec->lin));
	free(line);
	if (!(piec->coord = (char**)ft_memalloc(sizeof(char *) * (piec->lin + 1))))
		return (0);
	while (i < piec->lin)
	{
		if (!(piec->coord[i] = (char*)ft_memalloc(sizeof(char) *
						(piec->col + 1))))
			return (0);
		i++;
	}
	take_piece(line, piec);
	return (1);
}

static void		take_map(char *line, struct s_filler *inf)
{
	int			x;
	int			y;
	static int	swi = 0;

	x = -1;
	y = -1;
	if (swi)
		skip_next_line(0, line);
	else
		swi = 1;
	while (++y < inf->lin)
	{
		get_next_line(0, &line);
		while (++x < inf->col)
		{
			if (line[x + 4] == inf->op_piece)
				inf->coord[y][x] = -1;
			else if (line[x + 4] == inf->my_piece)
				inf->coord[y][x] = -2;
			else
				inf->coord[y][x] = INTMAX;
		}
		x = -1;
		free(line);
	}
}

int				play_filler(char *line, struct s_filler *inf)
{
	struct s_fil_piec	piec;

	piec.value = -3;
	take_map(line, inf);
	if (!(init_piece(line, &piec)))
		return (0);
	fil_heat(inf);
	put_piece(inf, &piec);
	free_piece(&piec);
	return (1);
}
