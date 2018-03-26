/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_something.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdanylev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 13:11:46 by hdanylev          #+#    #+#             */
/*   Updated: 2018/03/22 13:12:10 by hdanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

void	get_the_piece(t_s **s, char *line)
{
	int i;

	i = -1;
	while (line[++i])
	{
		if (line[i] == '*')
		{
			(*s)->pc_x[(*s)->stars] = i;
			(*s)->pc_y[(*s)->stars] = (*s)->prow - (*s)->flag_p;
			(*s)->stars++;
		}
	}
	(*s)->flag_p--;
	if ((*s)->flag_p == 0)
		move_stars((*s));
}

void	get_the_map(t_s **s, char *line)
{
	int i;
	int x;

	x = 0;
	i = 3;
	while (line[++i])
	{
		(*s)->map[(*s)->mrow - (*s)->flag_m][x] = line[i];
		x++;
	}
	(*s)->flag_m--;
}

void	get_the_size_of_map(t_s **s, char *line)
{
	int y;

	(*s)->mrow = ft_atoi(&line[8]);
	(*s)->mcol = (*s)->mrow > 99 ? ft_atoi(&line[11]) : ft_atoi(&line[10]);
	(*s)->flag_m = (*s)->mrow;
	(*s)->map = (char**)malloc(sizeof(char*) * (*s)->mrow + 1);
	y = 0;
	while (y < (*s)->mrow)
	{
		(*s)->map[y] = ft_strnew((size_t)(*s)->mcol);
		y++;
	}
	(*s)->map[y] = NULL;
	(*s)->flag_size_m = 1;
}

void	get_the_size_of_piece(t_s **s, char *line)
{
	(*s)->prow = ft_atoi(&line[6]);
	(*s)->pcol = (*s)->prow > 99 ? ft_atoi(&line[9]) : ft_atoi(&line[8]);
	(*s)->flag_p = (*s)->prow;
	(*s)->stars = 0;
}

void	get_the_player(t_s **s, char *line)
{
	(*s)->player = line[10] == '1' ? 1 : 2;
	if ((*s)->player == 2)
	{
		(*s)->enemy_ch = 'o';
		(*s)->enemy_bch = 'O';
		(*s)->ch = 'x';
		(*s)->bch = 'X';
	}
	else
	{
		(*s)->enemy_ch = 'x';
		(*s)->enemy_bch = 'X';
		(*s)->ch = 'o';
		(*s)->bch = 'O';
	}
}
