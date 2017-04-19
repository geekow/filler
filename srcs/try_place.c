/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_place.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <jjacobi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 14:58:18 by jjacobi           #+#    #+#             */
/*   Updated: 2017/04/19 03:22:00 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler_map.h"
#include "libft.h"

int		try_on_pos(t_map *map, t_coord *coord, char player)
{
	int		i;
	char	c;

	c = 0;
	i = 0;
	while (map->pcoords[i].x != -1)
	{
		if (coord->y + map->pcoords[i].y >= map->mheight ||
				coord->x + map->pcoords[i].x >= map->mwidth)
			return (-1);
		if (coord->y + map->pcoords[i].y < 0 ||
			coord->x + map->pcoords[i].x < 0)
			return (-1);
		else if (player - 32 ==
				map->map[coord->y + map->pcoords[i].y][coord->x +
				map->pcoords[i].x])
			c++;
		else if (map->map[coord->y + map->pcoords[i].y]
				[coord->x + map->pcoords[i].x] != '.')
			return (-1);
		i++;
	}
	return (c == 1 ? 0 : -1);
}

int		min_x_pcoord(t_coord *pcoords)
{
	int	i;
	int	min_x;

	min_x = 2147483647;
	i = 0;
	while (pcoords[i].x != -1)
	{
		if (pcoords[i].x < min_x)
			min_x = pcoords->x;
		i++;
	}
	return (min_x);
}

t_coord	*find_next_possible_pos(t_coord *startcoord, t_map *map, char player,
		t_coord *result)
{
	t_coord coord;
	t_coord tmp;

	coord = *startcoord;
	while (coord.y < map->mheight)
	{
		while (coord.x < map->mwidth)
		{
			tmp.x = coord.x - min_x_pcoord(map->pcoords);
			tmp.y = coord.y - map->pcoords[0].y;
			if (try_on_pos(map, &tmp, player) == 0)
			{
				*result = tmp;
				*startcoord = coord;
				return (result);
			}
			coord.x += 1;
		}
		coord.x = 0;
		coord.y += 1;
	}
	return (NULL);
}
