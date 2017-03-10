/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 21:12:07 by jjacobi           #+#    #+#             */
/*   Updated: 2017/03/09 21:12:08 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler_map.h"
#include "libft.h"

int parse_map_header(t_map *map)
{
    char    *header;

    get_next_line(0, &header);
    if (ft_strlen(header) < 12)
        return (-1);
    if (ft_memcmp(header, "Plateau ", 8 * sizeof(char)))
        return (-1);
    map->mHeight = ft_atoi(header + (8 * sizeof(char)));
    map->mWidth = ft_atoi(header + (9 + ft_strlen(ft_itoa(map->mHeight)))
                    * sizeof(char));
    if (map->mHeight < 1 || map->mWidth < 1)
        return (-1);
    return (0);
}

int parse_map_tab(t_map *map)
{
    int     count;
    int     lineMapLen;
    char    *lineMap;

    count = 0;
    lineMapLen = 4 + map->mWidth;
    if ((map->map = malloc(sizeof(char *) * (map->mHeight + 1))) == NULL)
        return (-1);
    map->map[map->mHeight] = NULL;
    while(count < map->mHeight && get_next_line(0, &lineMap) > 0)
    {
        if ((int)ft_strlen(lineMap) != lineMapLen)
            return (-1);
        if((map->map[count] = ft_strdup(lineMap + 4)) == NULL)
            return (-1);
        free(lineMap);
        count++;
    }
    if (count != map->mHeight)
        return (-1);
    return (0);
}

int parse_map(t_map *map)
{
    char    *useless;

    if (parse_map_header(map) == -1)
        return (-1);
    get_next_line(0, &useless);
    free(useless);
    if (parse_map_tab(map) == -1)
        return (-1);
    return (0);
}

int get_map(t_map *map)
{
    if (parse_map(map) == -1)
        return (-1);
    return (0);
}
