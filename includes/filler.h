/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <jjacobi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 22:33:33 by jjacobi           #+#    #+#             */
/*   Updated: 2017/04/20 21:07:47 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "filler_map.h"

int		get_map(t_map *map);
int		get_piece(t_map *map);
int		connection_score(t_map *map, char enemy, t_coord *result);
int		side_score(t_map *map, t_coord *result);
int		wall_score(t_map *map, char player, t_coord *result);
int		distance_score(t_map *map, char enemy, t_coord *result);
int		place_piece(t_map *map, char player, t_coord *start, t_coord *result);
t_coord	*find_next_possible_pos(t_coord *startcoord, t_map *map, char player,
								t_coord *result);

#endif
