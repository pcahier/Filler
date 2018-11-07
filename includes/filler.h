/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcahier <pcahier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 11:03:59 by pcahier           #+#    #+#             */
/*   Updated: 2018/11/07 18:59:00 by pcahier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft.h"
# include "get_next_line.h"
# include "ft_printf.h"

typedef struct	s_fil_piec
{
	int		dim_piec[2];
}				t_fil_piec;


typedef struct	s_filler
{
	int		play;
	int		dim[2];
	int		**coord;
	char	my_piece;
	char	op_piece;
}				t_filler;

void		play_filler(char *line, struct s_filler *inf);

#endif 
