/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 22:33:33 by jjacobi           #+#    #+#             */
/*   Updated: 2017/03/16 14:19:54 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "filler_map.h"

int 	get_map(t_map *map);
int	    get_piece(t_map *map);
t_coord *find_next_possible_pos(t_coord *startcoord, t_map *map, char player,
            t_coord *overlap);
//int     place_piece();

#endif
