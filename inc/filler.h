/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdanylev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 13:42:56 by hdanylev          #+#    #+#             */
/*   Updated: 2018/03/24 20:25:38 by hdanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# define ABC(x) (((x) < 0) ? -(x) : (x))
# include "../libftprintf/inc/printf.h"

typedef struct		s_s
{
	char			**map;
	char			**old_map;
	int				player;
	char			enemy_ch;
	char			enemy_bch;
	char			ch;
	char			bch;
	int				stars;
	int				pc_x[64];
	int				pc_y[64];
	int				flag_p;
	int				flag_m;
	int				mcol;
	int				mrow;
	int				pcol;
	int				prow;
	int				enemy_x;
	int				enemy_y;
	int				move_x;
	int				move_y;
	int				manhattan;
	int				short_i;
	int				short_j;
	int				flag_size_m;
}					t_s;

void				move_stars(t_s *s);
void				put_on(t_s *s, int i, int j);
void				get_the_player(t_s **s, char *line);
void				get_the_size_of_piece(t_s **s, char *line);
void				get_the_size_of_map(t_s **s, char *line);
void				get_the_map(t_s **s, char *line);
void				get_the_piece(t_s **s, char *line);
void				free_vse(t_s *s);
void				free_all_struct(t_s *s);
t_s					*where_is_the_enemy(t_s *s);
t_s					*where_is_the_enemy_1(t_s *s);
t_s					*find_place(t_s *s, int i, int j);

#endif
