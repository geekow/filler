/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <jjacobi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 21:12:07 by jjacobi           #+#    #+#             */
/*   Updated: 2017/04/21 21:30:03 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler_map.h"
#include "libft.h"

int	parse_map_header(t_map *map)
{
	char	*header;
	char	*tmp;

	if (1 != get_next_line(0, &header))
		return (-1);
	if (ft_strlen(header) < 12)
		return (-1);
	if (!ft_memcmp(header, "Plateau ", 8 * sizeof(char)))
	{
		map->mheight = ft_atoi(header + (8 * sizeof(char)));
		tmp = ft_itoa(map->mheight);
		map->mwidth = ft_atoi(header + (9 + ft_strlen(tmp))
			* sizeof(char));
		free(header);
		free(tmp);
	}
	if (map->mheight < 1 || map->mwidth < 1)
		return (-1);
	return (0);
}

int	parse_map_tab(t_map *map)
{
	int		count;
	int		linemaplen;
	char	*linemap;

	count = 0;
	linemaplen = 4 + map->mwidth;
	if ((map->map = malloc(sizeof(char *) * (map->mheight + 1))) == NULL)
		return (-1);
	map->map[map->mheight] = NULL;
	while (count < map->mheight && get_next_line(0, &linemap) > 0)
	{
		if ((int)ft_strlen(linemap) != linemaplen)
			return (-1);
		if ((map->map[count] = ft_strdup(linemap + 4)) == NULL)
			return (-1);
		free(linemap);
		count++;
	}
	if (count != map->mheight)
		return (-1);
	return (0);
}

int	parse_map(t_map *map)
{
	char	*useless;

	if (parse_map_header(map) == -1)
		return (-1);
	if (1 != get_next_line(0, &useless))
		return (-1);
	free(useless);
	if (parse_map_tab(map) == -1)
		return (-1);
	return (0);
}

int	get_map(t_map *map)
{
	if (parse_map(map) == -1)
		return (-1);
	return (0);
}
