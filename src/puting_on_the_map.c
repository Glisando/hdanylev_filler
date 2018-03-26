/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puting_on_the_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdanylev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 13:02:32 by hdanylev          #+#    #+#             */
/*   Updated: 2018/03/22 13:02:46 by hdanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

t_s		*shortest_distance(t_s *s, int j, int i)
{
	int	tmp;
	int min;
	int l;

	l = 0;
	min = 200;
	while (l < s->stars)
	{
		tmp = ABC(s->enemy_x - i + s->pc_x[l])
			+ ABC(s->enemy_y - j + s->pc_y[l]);
		min = tmp < min ? tmp : min;
		l++;
	}
	if (min < s->manhattan)
	{
		s->manhattan = min;
		s->short_i = i;
		s->short_j = j;
	}
	return (s);
}

t_s		*find_place(t_s *s, int j, int i)
{
	int l;
	int connect;
	int x;
	int y;

	connect = 0;
	l = -1;
	while (++l < s->stars)
	{
		x = i + s->pc_x[l];
		y = j + s->pc_y[l];
		if (y > s->mrow - 1 || x > s->mcol - 1)
			break ;
		if (s->map[y][x] != '.' && s->map[y][x] != s->ch &&
			s->map[y][x] != s->bch)
			break ;
		if (s->map[y][x] == s->ch || s->map[y][x] == s->bch)
			connect++;
	}
	if (l == s->stars && connect == 1)
	{
		return (shortest_distance(s, j, i));
	}
	return (s);
}

void	put_a_piece(t_s *s)
{
	int i;
	int j;

	j = 0;
	where_is_the_enemy(s);
	while (j < s->mrow)
	{
		i = 0;
		while (i < s->mcol)
		{
			find_place(s, j, i);
			i++;
		}
		j++;
	}
	put_on(s, s->short_i, s->short_j);
}

void	move_stars(t_s *s)
{
	int i;

	i = 0;
	s->move_x = s->pcol;
	s->move_y = s->prow;
	s->manhattan = 200;
	s->short_i = 0;
	s->short_j = 0;
	while (i < s->stars)
	{
		if (s->move_x > s->pc_x[i])
			s->move_x = s->pc_x[i];
		if (s->move_y > s->pc_y[i])
			s->move_y = s->pc_y[i];
		i++;
	}
	i = 0;
	while (i < s->stars)
	{
		s->pc_x[i] -= s->move_x;
		s->pc_y[i] -= s->move_y;
		i++;
	}
	put_a_piece(s);
}
