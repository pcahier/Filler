/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstru.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcahier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 18:40:47 by pcahier           #+#    #+#             */
/*   Updated: 2018/10/30 11:02:27 by pcahier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTSTRU_H
# define FT_PRINTSTRU_H

typedef struct	s_print
{
	char	operat;
	int		(*ft)(const char *, va_list *, int);
}				t_print;

typedef struct	s_color
{
	char	*chain;
	char	*code;
}				t_color;

t_print			g_print[16] = {
	{'d', ft_int_dec},
	{'D', ft_int_dec},
	{'i', ft_int_dec},
	{'o', ft_uns_oct},
	{'O', ft_uns_oct},
	{'u', ft_uns_dec},
	{'U', ft_uns_dec},
	{'x', ft_uns_hex},
	{'X', ft_uns_hexmaj},
	{'b', ft_uns_bin},
	{'c', ft_int_uchar},
	{'C', ft_int_uchar},
	{'s', ft_charray},
	{'S', ft_charray},
	{'p', ft_pointer},
};

t_color			g_color[19] = {
	{"{black}", "\033[30m"},
	{"{red}", "\033[31m"},
	{"{green}", "\033[32m"},
	{"{yellow}", "\033[33m"},
	{"{blue}", "\033[34m"},
	{"{magenta}", "\033[35m"},
	{"{cyan}", "\033[36m\033[1m"},
	{"{white}", "\033[37m"},
	{"{bblack}", "\033[40m"},
	{"{bred}", "\033[41m"},
	{"{bgreen}", "\033[42m"},
	{"{bold}", "\033[1m"},
	{"{dim}", "\033[2m"},
	{"{underline}", "\033[4m"},
	{"{blink}", "\033[5m"},
	{"{highlight}", "\033[7m"},
	{"{hidden}", "\033[8m"},
	{"{eoc}", "\033[0m"},
};

#endif
