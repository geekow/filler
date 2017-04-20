/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_score.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <jjacobi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 20:04:13 by jjacobi           #+#    #+#             */
/*   Updated: 2017/04/20 20:52:28 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "libft.h"

int	calc_distances(t_coord *a, t_coord *b, t_coord *addtob)
{
	int resx;
	int	resy;

	resx = ft_power((addtob->x + b->x) - a->x, 2);
	resy = ft_power((addtob->y + b->y) - a->y, 2);
	return (ft_sqrt(resx + resy));
}

int	side_wall(t_map *map, char player, t_coord *result)
{
	int		i;
	int		pindex;
	int		tmp;
	int		score;
	t_coord	coord;

	pindex = 0;
	score = 2147483647;
	while (map->pcoords[pindex].x != -1)
	{
		i = 0;
		coord.y = 0;
		while (i < 2)
		{
			coord.x = 0;
			while (coord.x < map->mwidth)
			{
				if (map->map[coord.y][coord.x] == player)
				{
					tmp = calc_distances(&coord, &map->pcoords[i], result);
					score = (tmp < score ? tmp : score);
				}
				coord.x++;
			}
			coord.y = map->mheight - 1;
			i++;
		}
		pindex++;
	}
	return (score);
}

int	height_wall(t_map *map, char player, t_coord *result)
{
	int		i;
	int		pindex;
	int		tmp;
	int		score;
	t_coord	coord;

	pindex = 0;
	score = 2147483647;
	while (map->pcoords[pindex].x != -1)
	{
		i = 0;
		coord.x = 0;
		while (i < 2)
		{
			coord.y = 0;
			while (coord.y < map->mheight)
			{
				if (map->map[coord.y][coord.x] == player)
				{
					tmp = calc_distances(&coord, &map->pcoords[i], result);
					score = (tmp < score ? tmp : score);
				}
				coord.y++;
			}
			coord.x = map->mwidth - 1;
			i++;
		}
		pindex++;
	}
	return (score);
}

int	wall_score(t_map *map, char player, t_coord *result)
{
	int	width_score;
	int	height_score;

	width_score = side_wall(map, player, result);
	height_score = height_wall(map, player, result);
	return (width_score < height_score ? width_score : height_score);
}
