/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 12:43:35 by jjacobi           #+#    #+#             */
/*   Updated: 2017/03/16 14:52:08 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler_map.h"
#include "libft.h"

int	parse_piece_header(t_map *map)
{
	char	*header;

	if (1 != get_next_line(0, &header))
		return (-1);
	if (ft_strlen(header) < 9)
		return (-1);
	if (ft_memcmp(header, "Piece ", 5 * sizeof(char)))
		return (-1);
	map->pheight = ft_atoi(header + (5 * sizeof(char)));
	map->pwidth = ft_atoi(header + (5 + ft_strlen(ft_itoa(map->mheight)))
			* sizeof(char));
	if (map->pheight < 1 || map->pwidth < 1)
		return (-1);
	return (0);
}

int	parse_piece_tab(t_map *map)
{
	int		count;
	char	*linepiece;

	count = 0;
	if ((map->piece = malloc(sizeof(char*) * (map->pheight + 1))) == NULL)
		return (-1);
	map->piece[map->pheight] = NULL;
	while (count < map->pheight && get_next_line(0, &linepiece) > 0)
	{
		if ((int)ft_strlen(linepiece) != map->pwidth)
			return (-1);
		if ((map->piece[count] = ft_strdup(linepiece)) == NULL)
			return (-1);
		free(linepiece);
		count++;
	}
	if (count != map->pheight)
		return (-1);
	return (0);
}

int	save_piece(t_map *map)
{
	int	i;
	int	j;
	int	k;

	k = 0;
	i = 0;
	if ((map->pcoord = malloc(sizeof(t_coord*) *
					(map->pheight * map->pwidth))) == NULL)
		return (-1);
	while (map->piece[i])
	{
		j = 0;
		while (map->piece[i][j])
		{
			if (map->piece[i][j] == '*')
			{
				map->pcoord[k].x = j;
				map->pcoord[k++].y = i;
			}
			j++;
		}
		i++;
	}
	map->pcoord[k].x = -1;
	return (0);
}

int	get_piece(t_map *map)
{
	if (parse_piece_header(map) == -1)
		return (-1);
	if (parse_piece_tab(map) == -1)
		return (-1);
	if (save_piece(map) == -1)
		return (-1);
	return (0);
}
