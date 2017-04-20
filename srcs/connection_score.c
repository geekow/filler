/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connection_score.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <jjacobi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 19:40:47 by jjacobi           #+#    #+#             */
/*   Updated: 2017/04/20 19:58:12 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	diag_score(t_map *map, char enemy, t_coord *result)
{
	int	i;
	int	score;

	i = -1;
	score = 0;
	while (map->pcoords[++i].x != -1)
	{
		if (map->pcoords[i].y + result->y - 1 >= 0 && map->pcoords[i].x +
			result->x - 1 >= 0 && map->map[map->pcoords[i].y + result->y - 1]
			[map->pcoords[i].x + result->x - 1] == enemy)
			score++;
		if (map->pcoords[i].y + result->y - 1 >= 0 && map->pcoords[i].x +
			result->x + 1 < map->mwidth && map->map[map->pcoords[i].y +
			result->y - 1][map->pcoords[i].x + result->x + 1] == enemy)
			score++;
		if (map->pcoords[i].y + result->y + 1 < map->mheight && map->pcoords[i].
			x + result->x + 1 < map->mwidth && map->map[map->pcoords[i].y +
			result->y + 1][map->pcoords[i].x + result->x + 1] == enemy)
			score++;
		if (map->pcoords[i].y + result->y + 1 < map->mheight && map->pcoords[i].
			x + result->x - 1 >= 0 && map->map[map->pcoords[i].y + result->y +
			1][map->pcoords[i].x + result->x - 1] == enemy)
			score++;
	}
	return (score);
}

int	sides_score(t_map *map, char enemy, t_coord *result)
{
	int	i;
	int	score;

	i = -1;
	score = 0;
	while (map->pcoords[++i].x != -1)
	{
		if (map->pcoords[i].x + result->x + 1 < map->mwidth)
			if (map->map[map->pcoords[i].y + result->y]
				[map->pcoords[i].x + result->x + 1] == enemy)
				score++;
		if (map->pcoords[i].x + result->x - 1 >= 0)
			if (map->map[map->pcoords[i].y + result->y]
				[map->pcoords[i].x + result->x - 1] == enemy)
				score++;
		if (map->pcoords[i].y + result->y + 1 < map->mheight)
			if (map->map[map->pcoords[i].y + result->y + 1]
				[map->pcoords[i].x + result->x] == enemy)
				score++;
		if (map->pcoords[i].y + result->y - 1 >= 0)
			if (map->map[map->pcoords[i].y + result->y - 1]
				[map->pcoords[i].x + result->x] == enemy)
				score++;
	}
	return (score);
}

int	connection_score(t_map *map, char enemy, t_coord *result)
{
	return (sides_score(map, enemy, result) + diag_score(map, enemy, result));
}
