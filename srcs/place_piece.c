/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <jjacobi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 17:06:29 by jjacobi           #+#    #+#             */
/*   Updated: 2017/04/20 21:07:52 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "libft.h"

int		calc_score(t_map *map, char player, t_coord *result)
{
	int	score;
	int	connections;
	int	side;
	int	distance;
	int	wallscore;

	connections = connection_score(map, (player == 'x' ? 'O' : 'X'), result);
	side = side_score(map, result);
	distance = distance_score(map, (player == 'x' ? 'O' : 'X'), result);
	wallscore = wall_score(map, player - 32, result);
	if (map->max_dist / 10 > side && wallscore > map->max_dist / 5)
		score = 20 + map->max_dist - side;
	else
		score = connections + map->max_dist - distance;
	return (score);
}

int		place_piece(t_map *map, char player, t_coord *start, t_coord *result)
{
	int		score;
	int		tmp;
	t_coord	coord;
	t_coord	myresult;

	myresult = *result;
	coord = *start;
	if (coord.x >= map->mwidth)
	{
		coord.y += 1;
		coord.x = 0;
	}
	else
		coord.x += 1;
	if (find_next_possible_pos(&coord, map, player, &myresult) == NULL)
		return (-2147483648);
	score = calc_score(map, player, &myresult);
	tmp = place_piece(map, player, &coord, result);
	if (score >= tmp)
	{
		*result = myresult;
		return (score);
	}
	return (tmp);
}
