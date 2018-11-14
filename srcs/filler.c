/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcahier <pcahier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 11:04:10 by pcahier           #+#    #+#             */
/*   Updated: 2018/11/14 16:59:41 by pcahier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		free_map(struct s_filler *inf)
{
	while (inf->lin >= 0)
	{
		free(inf->coord[inf->lin]);
		inf->lin--;
	}
	free(inf->coord);
}

static int		allocate_map(struct s_filler *inf)
{
	int		i;

	i = 0;
	if (!(inf->coord = (int**)ft_memalloc(sizeof(int *) * (inf->lin + 1))))
		return (0);
	while (i < inf->lin)
	{
		if (!(inf->coord[i] = (int*)malloc(sizeof(int) *
						(inf->col + 1))))
			return (0);
		i++;
	}
	return (1);
}

static int		init_inf(char *line, struct s_filler *inf)
{
	get_next_line(0, &line);
	inf->play = line[10];
	inf->my_piece = (inf->play == '1' ? 'O' : 'X');
	inf->op_piece = (inf->play == '1' ? 'X' : 'O');
	free(line);
	get_next_line(0, &line);
	inf->lin = ft_atoi(line + 8);
	inf->col = ft_atoi(line + 8 + ft_decnumlen(inf->lin));
	free(line);
	if (!(allocate_map(inf)))
		return (0);
	return (1);
}

int				main(void)
{
	char				*line;
	struct s_filler		inf;

	line = NULL;
	if (!(init_inf(line, &inf)))
		return (-1);
	while (get_next_line(0, &line))
	{
		free(line);
		if (!(play_filler(line, &inf)))
		{
			free_map(&inf);
			return (-2);
		}
	}
	free_map(&inf);
	return (0);
}
