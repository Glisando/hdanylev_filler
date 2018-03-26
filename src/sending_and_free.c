/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sending_and_free.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdanylev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 13:05:06 by hdanylev          #+#    #+#             */
/*   Updated: 2018/03/22 13:05:31 by hdanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

void	free_all_struct(t_s *s)
{
	int i;

	i = 0;
	while (s->old_map[i])
	{
		free(s->old_map[i]);
		i++;
	}
	free(s->old_map);
	free(s);
}

void	free_vse(t_s *s)
{
	int i;

	i = 0;
	while (s->map[i])
	{
		free(s->map[i]);
		i++;
	}
	free(s->map);
	i = 0;
	while (i < s->stars)
	{
		s->pc_y[i] = 0;
		s->pc_x[i] = 0;
		i++;
	}
}

void	put_on(t_s *s, int i, int j)
{
	int x;
	int y;

	x = i - s->move_x;
	y = j - s->move_y;
	free_vse(s);
	ft_printf("%d %d\n", y, x);
}
