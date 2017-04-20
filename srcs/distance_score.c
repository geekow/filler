/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance_score.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <jjacobi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 21:07:12 by jjacobi           #+#    #+#             */
/*   Updated: 2017/04/20 21:07:28 by jjacobi          ###   ########.fr       */
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
