/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   side_score.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <jjacobi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 19:46:54 by jjacobi           #+#    #+#             */
/*   Updated: 2017/04/20 19:53:20 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	leftright_score(t_map *map, t_coord *result)
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
	return (min < max ? min : max);
}

int	bottop_score(t_map *map, t_coord *result)
{
	int	i;
	int	min;
	int	max;

	i = 0;
	min = 2147483647;
	max = 0;
	while (map->pcoords[i].x != -1)
	{
		if (min > result->y + map->pcoords[i].y)
			min = result->y + map->pcoords[i].y;
		if (max < result->y + map->pcoords[i].y)
			max = result->y + map->pcoords[i].y;
		i++;
	}
	max = map->mheight - max;
	return (min < max ? min : max);
}

int	side_score(t_map *map, t_coord *result)
{
	int	width_result;
	int	height_result;

	width_result = leftright_score(map, result);
	height_result = bottop_score(map, result);
	return (width_result < height_result ? width_result : height_result);
}
