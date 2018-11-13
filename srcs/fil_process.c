/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fil_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcahier <pcahier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 18:02:42 by pcahier           #+#    #+#             */
/*   Updated: 2018/11/13 18:46:17 by pcahier          ###   ########.fr       */
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
		ft_printf("\np_lin : %d y : %d\n", piec->lin, y);
		get_next_line(0, &line);
		while (x < piec->col)
		{
			piec->coord[y][x] = line[x];
			ft_printf("%c", piec->coord[y][x]);
			x++;
		}
		x = 0;
		y++;
	}
	ft_printf("\n");
}

static int		init_piece(char *line, struct s_fil_piec *piec)
{
	int		i;

	i = 0;
	get_next_line(0, &line);
	piec->lin = ft_atoi(line + 6);
	piec->col = ft_atoi(line + 6 + ft_decnumlen(piec->lin));
	ft_printf("piece x = %d piece y = %d\n", piec->col, piec->lin);
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

	x = 0;
	y = 0;
	if (swi)
		get_next_line(0, &line);
	else
		swi = 1;
	while (y < inf->lin)
	{
		ft_printf("\nlin : %d y : %d\n", inf->lin, y);
		get_next_line(0, &line);
		while (x < inf->col)
		{
			ft_printf("%c", line[x + 4]);
			if (line[x + 4] == inf->op_piece)
				inf->coord[y][x] = -1;
			else if (line[x + 4] == inf->my_piece)
				inf->coord[y][x] = -2;
			else
				inf->coord[y][x] = -3;
			x++;
		}
		x = 0;
		y++;
	}
	ft_printf("\n");
}

int				play_filler(char *line, struct s_filler *inf)
{
	struct s_fil_piec	piec;

	take_map(line, inf);
	if (!(init_piece(line, &piec)))
		return (0);
	fil_heat(inf, &piec);
	free_piece(&piec);
	write(1, "1 2\n", 4);
	return (1);
}
