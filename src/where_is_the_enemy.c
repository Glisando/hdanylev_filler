/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   where_is_the_enemy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdanylev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 16:19:33 by hdanylev          #+#    #+#             */
/*   Updated: 2018/03/22 16:19:48 by hdanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

t_s		*copy_maps(t_s *s)
{
	int j;

	j = 0;
	while (j < s->mrow)
	{
		s->old_map[j] = ft_strcpy(s->old_map[j], s->map[j]);
		j++;
	}
	return (s);
}

t_s		*create_old_map(t_s *s)
{
	int y;

	s->old_map = (char**)malloc(sizeof(char*) * s->mrow + 1);
	y = 0;
	while (y < s->mrow)
	{
		s->old_map[y] = ft_strnew((size_t)s->mcol);
		y++;
	}
	s->old_map[y] = NULL;
	return (copy_maps(s));
}

t_s		*where_is_the_enemy_1(t_s *s)
{
	int i;
	int j;
	int stop;

	j = -1;
	stop = 0;
	while (++j < s->mrow)
	{
		i = 0;
		while (i < s->mcol)
		{
			if (s->map[j][i] == s->enemy_ch || s->map[j][i] == s->enemy_bch)
			{
				stop = 1;
				break ;
			}
			i++;
		}
		if (stop == 1)
			break ;
	}
	s->enemy_x = i;
	s->enemy_y = j;
	return (s);
}

t_s		*where_is_the_enemy(t_s *s)
{
	int	i;
	int	j;

	if (s->old_map == NULL)
	{
		create_old_map(s);
		return (where_is_the_enemy_1(s));
	}
	j = -1;
	while (++j < s->mrow)
	{
		i = -1;
		while (++i < s->mcol)
			if (s->map[j][i] == s->enemy_ch || s->map[j][i] == s->enemy_bch)
				if (s->old_map[j][i] != s->map[j][i])
				{
					s->enemy_x = i;
					s->enemy_y = j;
					break ;
				}
	}
	return (copy_maps(s));
}
