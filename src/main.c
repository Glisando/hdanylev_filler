/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdanylev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 14:13:03 by hdanylev          #+#    #+#             */
/*   Updated: 2018/03/15 14:13:35 by hdanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

int		main(void)
{
	char	*line;
	t_s		*s;

	s = (t_s*)malloc(sizeof(t_s));
	s->mcol = 0;
	s->old_map = NULL;
	while ((get_next_line(0, &line)))
	{
		if (line[1] == 'i')
			get_the_size_of_piece(&s, line);
		else if (line[1] == 'l')
			get_the_size_of_map(&s, line);
		else if (line[0] >= '0' && line[0] <= '9' && s->flag_m > 0)
			get_the_map(&s, line);
		else if ((line[0] == '.' || line[0] == '*') && s->flag_p > 0)
			get_the_piece(&s, line);
		else if (line[0] == '$')
			get_the_player(&s, line);
		free(line);
	}
	free_all_struct(s);
	return (0);
}
