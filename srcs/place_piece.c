/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <jjacobi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 17:06:29 by jjacobi           #+#    #+#             */
/*   Updated: 2017/04/19 04:18:37 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "libft.h"

int		calc_distance(t_coord *a, t_coord *b, t_coord *addtob)
{
	int resx;
	int	resy;

	resx = ft_power((addtob->x + b->x) - a->x, 2);
	resy = ft_power((addtob->y + b->y) - a->y, 2);
	return (ft_sqrt(resx + resy));
}

int		distance_score(t_map *map, char enemy, t_coord *result)
{
	t_coord	index;
	int		distance;
	int		i;

	index.x = 0;
	index.y = 0;
	i = -1;
	distance = 2147483647;
	while (map->pcoords[++i].x != -1)
		while (index.y < map->mheight)
		{
			while (index.x < map->mwidth)
			{
				if (map->map[index.y][index.x] == enemy)
					if (distance > calc_distance(&index, &map->pcoords[i],
													result))
						distance = calc_distance(&index, &map->pcoords[i],
													result);
				index.x++;
			}
			index.x = 0;
			index.y++;
		}
	return (distance);
}

int		side_score(t_map *map, char enemy, t_coord *result)
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

int		diag_score(t_map *map, char enemy, t_coord *result)
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

int		leftright_score(t_map *map, t_coord *result)
{
	int	i;
	int	min;
	int	max;

	i = 0;
	min = 2147483647;
	max = 0;
	while (map->pcoords[i].x != -1)
	{
		if (min > result->x + map->pcoords[i].x)
			min = result->x + map->pcoords[i].x;
		if (max < result->x + map->pcoords[i].x)
			max = result->x + map->pcoords[i].x;
		i++;
	}
	max = map->mwidth - max;
	return (min < max ? max : min);
}

int		calc_score(t_map *map, char player, t_coord *result)
{
	int	score;

	score = side_score(map, (player == 'x' ? 'O' : 'X'), result);
	score += diag_score(map, (player == 'x' ? 'O' : 'X'), result);
	if (score == 0)
	{
		score -= distance_score(map, (player == 'x' ? 'O' : 'X'), result);
		if (-score < map->mwidth / (2.0 * (map->mwidth / 100.0)))
			score -= (leftright_score(map, result) * 10);
	}
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
