/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <jjacobi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 17:06:29 by jjacobi           #+#    #+#             */
/*   Updated: 2017/04/18 15:29:07 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "libft.h"

void	set_init_size(t_coord *piece, t_coord *result, t_coord *size_min,
						t_coord *size_max)
{
	int i;

	i = 0;
	size_min->x = 2147483647;
	size_min->y = 2147483647;
	size_max->x = 0;
	size_max->y = 0;
	while (piece[i].x != -1)
	{
		if (result->x + piece[i].x < size_min->x)
			size_min->x = result->x + piece[i].x;
		if (result->y + piece[i].y < size_min->y)
			size_min->y = result->y + piece[i].y;
		if (result->x + piece[i].x > size_max->x)
			size_max->x = result->x + piece[i].x;
		if (result->y + piece[i].y > size_max->y)
			size_max->y = result->y + piece[i].y;
		i++;
	}
}

int		calc_score(t_map *map, char player, t_coord *result)
{
	int		score;
	t_coord	coord;
	t_coord	size_min;
	t_coord	size_max;

	coord.x = 0;
	coord.y = 0;
	set_init_size(map->pcoords, result, &size_min, &size_max);
	while (coord.y < map->mheight)
	{
		while (coord.x < map->mwidth)
		{
			if (map->map[coord.y][coord.x] == player ||
				map->map[coord.y][coord.x] == player - 32)
			{
				if (coord.x < size_min.x)
					size_min.x = coord.x;
				if (coord.y < size_min.y)
					size_min.y = coord.y;
				if (coord.x > size_max.x)
					size_max.x = coord.x;
				if (coord.y > size_max.y)
					size_max.y = coord.y;
			}
			coord.x++;
		}
		coord.x = 0;
		coord.y++;
	}
	score = (size_max.x - size_min.x) * (size_max.y - size_min.y);
	return (score);
}

int		place_piece(t_map *map, char player, t_coord *start, t_coord *result)
{
	int		score;
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
		return (-1);
	score = calc_score(map, player, &myresult);
	if (score >= place_piece(map, player, &coord, result))
		*result = myresult;
	return (score);
}
