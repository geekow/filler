/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 17:06:29 by jjacobi           #+#    #+#             */
/*   Updated: 2017/03/17 17:06:31 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "libft.h"
#include "ft_printf.h"

t_coord *place_piece(t_map *map, char player, t_coord *stats)
{
    t_coord*    start_pos;
    t_coord*    overlap;
    t_coord*    tabs;
    t_coord*    tmp;
    t_coord*    all_stats;


    all_stats = malloc(sizeof(t_coord) * 500);

    int i = 0;



    tabs = malloc(sizeof(t_coord) * 3);
    overlap = tabs;
    start_pos = tabs + 1;
    tmp = tabs + 2;
    overlap->x = 0;
    overlap->y = 0;
    while ((start_pos = find_next_possible_pos(start_pos, map, player, overlap)) != NULL) {
        //change piece to place
        all_stats[i].x = 0;
        all_stats[i].y = 0;
        place_piece(map, ((player == 'x') ? 'o' : 'x'), all_stats + i++);
        if (tmp->x / (tmp->x + tmp->y) > stats->x / (stats->x + stats->y)){
            stats = tmp;
        }
        //clear tab
    }
    while (--i) {
        stats->x += all_stats[i].x;
        stats->y += all_stats[i].y;
    }
    return start_pos;
}
